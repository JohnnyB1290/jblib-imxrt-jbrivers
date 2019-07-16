/**
 * @file
 * @brief UART Driver Realization
 *
 *
 * @note
 * Copyright © 2019 Evgeniy Ivanov. Contacts: <strelok1290@gmail.com>
 * All rights reserved.
 * @note
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 * @note
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @note
 * This file is a part of JB_Lib.
 */

// This is an open source non-commercial project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "jbkernel/jb_common.h"
#if JBDRIVERS_USE_LPUART

#include <stdlib.h>
#include "jbdrivers/Uart.hpp"
#include "fsl_lpuart.h"
#include "clock_config.h"



namespace jblib::jbdrivers
{

using namespace jbkernel;

Uart* Uart::uarts_[UARTS_NUM] = {NULL};
LPUART_Type* Uart::bases_[UARTS_NUM] = {
#ifdef LPUART1
		LPUART1,
#else
		NULL,
#endif
#ifdef LPUART2
		LPUART2,
#else
		NULL,
#endif
#ifdef LPUART3
		LPUART3,
#else
		NULL,
#endif
#ifdef LPUART4
		LPUART4,
#else
		NULL,
#endif
#ifdef LPUART5
		LPUART5,
#else
		NULL,
#endif
#ifdef LPUART6
		LPUART6,
#else
		NULL,
#endif
#ifdef LPUART7
		LPUART7,
#else
		NULL,
#endif
#ifdef LPUART8
		LPUART8,
#else
		NULL,
#endif
};
const IRQn_Type Uart::irqNums_[UARTS_NUM] = {
		(IRQn_Type)20, (IRQn_Type)21, (IRQn_Type)22,
		(IRQn_Type)23, (IRQn_Type)24, (IRQn_Type)25,
		(IRQn_Type)26, (IRQn_Type)27};
uint32_t Uart::interruptPriorities_[UARTS_NUM] = {
		UART_1_INTERRUPT_PRIORITY, UART_2_INTERRUPT_PRIORITY,
		UART_3_INTERRUPT_PRIORITY, UART_4_INTERRUPT_PRIORITY,
		UART_5_INTERRUPT_PRIORITY, UART_6_INTERRUPT_PRIORITY,
		UART_7_INTERRUPT_PRIORITY, UART_8_INTERRUPT_PRIORITY,
};



Uart* Uart::getUart(uint8_t number, uint32_t baudrate)
{
	if(number >= UARTS_NUM)
		return NULL;
	if(uarts_[number] == NULL)
		uarts_[number] = new Uart(number, baudrate);
	return uarts_[number];
}



Uart::Uart(uint8_t number, uint32_t baudrate) : IVoidChannel(), IIrqListener()
{
	this->number_ = number;
	this->baudrate_ = baudrate;
	IrqController::getIrqController()->addIrqListener(this, irqNums_[number]);
}


void Uart::initialize(void* (* const mallocFunc)(size_t),
		const uint16_t txBufferSize, IChannelCallback* const callback)
{
	if(!this->initialized_) {
		this->callback_ = callback;
		this->txRingBuffer_ =
				new RingBuffer(mallocFunc(txBufferSize), 1, txBufferSize);
		lpuart_config_t config;
	    LPUART_GetDefaultConfig(&config);
	    config.baudRate_Bps = this->baudrate_;
	    config.enableTx     = true;
	    config.enableRx     = true;
	    LPUART_Init(bases_[this->number_], &config, INITIALIZE_CLOCK_UART_CLK_ROOT);
	    LPUART_EnableInterrupts(bases_[this->number_], kLPUART_RxDataRegFullInterruptEnable);
	    IrqController::getIrqController()->
	    		setPriority(irqNums_[this->number_], interruptPriorities_[this->number_]);
	    IrqController::getIrqController()->enableInterrupt(irqNums_[this->number_]);
		this->initialized_ = true;
	}
}



void Uart::irqHandler(IRQn_Type irqNumber)
{
	static uint8_t byte = 0;
	if(this->initialized_) {
		uint32_t status =  LPUART_GetStatusFlags(bases_[this->number_]);
		if (status & kLPUART_RxDataRegFullFlag) {
			byte = LPUART_ReadByte(bases_[this->number_]);
			if(this->callback_){
				this->callback_->channelCallback(&byte, 1, (void*)this, NULL);
			}
		}
		if(status & kLPUART_TxDataRegEmptyFlag){
			bases_[this->number_]->CTRL &= ~kLPUART_TxDataRegEmptyInterruptEnable;
			 if(this->txRingBuffer_->pop(&byte)){
				 LPUART_WriteByte(bases_[this->number_], byte);
				 bases_[this->number_]->CTRL |= kLPUART_TxDataRegEmptyInterruptEnable;
			 }
		}
	}
}



void Uart::deinitialize(void)
{
	if(this->initialized_) {
		LPUART_Deinit(bases_[this->number_]);
		this->callback_ = NULL;
		this->initialized_ = false;
		IrqController::getIrqController()->disableInterrupt(irqNums_[this->number_]);
	}
}



Uart::~Uart(void)
{

}



void Uart::tx(uint8_t* const buffer, const uint16_t size, void* parameter)
{
	if(this->initialized_) {
		this->txRingBuffer_->insertMult(buffer, size);
		bases_[this->number_]->CTRL |= kLPUART_TxDataRegEmptyInterruptEnable;
	}
}



void Uart::getParameter(const uint8_t number, void* const value)
{

}



void Uart::setParameter(const uint8_t number, void* const value)
{

}

}

#endif
