/**
 * @file
 * @brief Uart Driver Description
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

#ifndef UART_HPP_
#define UART_HPP_

#include "jbkernel/jb_common.h"
#include "jbkernel/callback_interfaces.hpp"
#include "jbdrivers/IrqController.hpp"
#include "jbkernel/IVoidChannel.hpp"
#include "jbutilities/RingBuffer.hpp"

#if !defined UARTS_NUM
#define UARTS_NUM			8
#endif

namespace jblib::jbdrivers
{

using namespace jbkernel;
using namespace jbutilities;


class Uart : public IVoidChannel, protected IIrqListener
{
public:
	static Uart* getUart(uint8_t number, uint32_t baudrate);
	virtual void initialize(void* (* const mallocFunc)(size_t),
			const uint16_t txBufferSize, IChannelCallback* const callback);
	virtual void deinitialize(void);
	virtual void tx(uint8_t* const buffer, const uint16_t size, void* parameter);
	virtual void getParameter(const uint8_t number, void* const value);
	virtual void setParameter(const uint8_t number, void* const value);

private:
	Uart(uint8_t number, uint32_t baudrate);
	virtual ~Uart(void);
	virtual void irqHandler(int irqNumber);

	static Uart* uarts_[UARTS_NUM];
	static LPUART_Type* bases_[UARTS_NUM];
	static const IRQn_Type irqNums_[UARTS_NUM];
	static uint32_t interruptPriorities_[UARTS_NUM];
	uint8_t number_ = 0;
	uint32_t baudrate_ = 0;
	IChannelCallback* callback_ = NULL;
	bool initialized_ = false;
	RingBuffer* txRingBuffer_ = NULL;
};

}

#endif /* UART_HPP_ */
