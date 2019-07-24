/**
 * @file
 * @brief JbController Core class realization
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

#include <string.h>
#include "jbdrivers/JbController.hpp"
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "fsl_gpio.h"



namespace jblib::jbdrivers
{

using namespace jbkernel;
using namespace jbutilities;


BoardGpio_t JbController::boardGpios_[] = JBCONTROLLER_BOARD_GPIOS;
bool JbController::isInitialized_ = false;
LinkedList<JbController::MainProceduresListItem>* JbController::mainProceduresList_ =
		new LinkedList<MainProceduresListItem>();


void JbController::initialize(void)
{
	if(!isInitialized_) {
		NVIC_SetPriorityGrouping(0x03); //All 4 bits for pre-emption priority
		__enable_irq();
		BOARD_InitBootPins();
	    BOARD_InitBootClocks();
	    BOARD_InitBootPeripherals();
		isInitialized_ = true;
	}
}



void JbController::delayMs(uint32_t ms)  //For 600MHz Clock
{
	for(uint32_t i = 0; i < ms; i++)
		for(uint32_t j = 0; j < JBCONTROLLER_NUM_NOP_DELAY_MS; j++)
			__NOP();
}



void JbController::delayUs(uint32_t us) //For 600MHz Clock
{
	for(uint32_t i = 0; i < us * JBCONTROLLER_NUM_NOP_DELAY_US; i++)
		__NOP();
}



void JbController::gpioOn(uint8_t number)
{
	GPIO_PortSet((GPIO_Type*)boardGpios_[number].gpioBasePointer,
			1U << boardGpios_[number].gpioPin);
}



void JbController::gpioOff(uint8_t number)
{
	GPIO_PortClear((GPIO_Type*)boardGpios_[number].gpioBasePointer,
			1U << boardGpios_[number].gpioPin);
}



void JbController::gpioTgl(uint8_t number)
{
	GPIO_PortToggle((GPIO_Type*)boardGpios_[number].gpioBasePointer,
			1U << boardGpios_[number].gpioPin);
}



void JbController::resetPeriphery(void)
{
	for(uint32_t i = 0; i < 52; i++) {
		NVIC_DisableIRQ((IRQn_Type)i);
		NVIC_ClearPendingIRQ((IRQn_Type)i);
	}
}



void JbController::softReset(void)
{

}



void JbController::goToApp(uint32_t applicationAddress)
{

}



void JbController::doMain(void)
{
	if(!mainProceduresList_->isEmpty()){
		LinkedList<MainProceduresListItem>::LinkIterator* iterator =
				mainProceduresList_->getIterator();
		iterator->reset();
		while(1){
			iterator->getCurrent()->callback->
					voidCallback(NULL, iterator->getCurrent()->parameter);
			if(!iterator->atEnd())
				iterator->nextLink();
			else
				break;
		}
	}
}



void JbController::addMainProcedure(IVoidCallback* callback, void* parameter)
{
	MainProceduresListItem* newItem = new MainProceduresListItem();
	newItem->callback = callback;
	newItem->parameter = parameter;
	mainProceduresList_->insertLast(newItem);
}



void JbController::deleteMainProcedure(IVoidCallback* callback, void* parameter)
{
	if(!mainProceduresList_->isEmpty()){
		LinkedList<MainProceduresListItem>::LinkIterator* iterator =
				mainProceduresList_->getIterator();
		iterator->reset();
		while(1){
			if((iterator->getCurrent()->callback == callback) &&
					(iterator->getCurrent()->parameter == parameter)){
				free_s(iterator->deleteCurrent());
			}
			if(!iterator->atEnd())
				iterator->nextLink();
			else
				break;
		}
	}
}



void JbController::addMainProcedure(IVoidCallback* callback)
{
	addMainProcedure(callback, NULL);
}



void JbController::deleteMainProcedure(IVoidCallback* callback)
{
	deleteMainProcedure(callback, NULL);
}



uint32_t JbController::getHeapFree(void)
{
    uint32_t ret = 10;
    disableInterrupts();
    void* ptr = malloc(ret);
    while(ptr != NULL){
        free(ptr);
        ret += 10;
        ptr = malloc(ret);
    }
    enableInterrupts();
    return ret;
}

}
