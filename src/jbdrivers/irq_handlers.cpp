/**
 * @file
 * @brief Bind IRQ Handlers with IRQ irqController
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

#include "jbdrivers/IrqController.hpp"

namespace jblib::jbdrivers
{

static IrqController* const irqController = IrqController::getIrqController();

#ifdef __cplusplus
extern "C" {
#endif

void NMI_Handler(void)
{
	irqController->handleIrq(NonMaskableInt_IRQn);
	while(1);
}

void HardFault_Handler(void)
{
	irqController->handleIrq(HardFault_IRQn);
	while(1);
}

void MemManage_Handler(void)
{
	irqController->handleIrq(MemoryManagement_IRQn);
	while(1);
}

void BusFault_Handler(void)
{
	irqController->handleIrq(BusFault_IRQn);
	while(1);
}

void UsageFault_Handler(void)
{
	irqController->handleIrq(UsageFault_IRQn);
	while(1);
}

void SVC_Handler(void)
{
	irqController->handleIrq(SVCall_IRQn);
	while(1);
}

void DebugMon_Handler(void)
{
	irqController->handleIrq(DebugMonitor_IRQn);
	while(1);
}

void PendSV_Handler(void)
{
	irqController->handleIrq(PendSV_IRQn);
	while(1);
}

void SysTick_Handler(void)
{
	irqController->handleIrq(SysTick_IRQn);
}

void DMA0_DMA16_IRQHandler(void)
{
	irqController->handleIrq(0);
}

void DMA1_DMA17_IRQHandler(void)
{
	irqController->handleIrq(1);
}

void DMA2_DMA18_IRQHandler(void)
{
	irqController->handleIrq(2);
}

void DMA3_DMA19_IRQHandler(void)
{
	irqController->handleIrq(3);
}

void DMA4_DMA20_IRQHandler(void)
{
	irqController->handleIrq(4);
}

void DMA5_DMA21_IRQHandler(void)
{
	irqController->handleIrq(5);
}

void DMA6_DMA22_IRQHandler(void)
{
	irqController->handleIrq(6);
}

void DMA7_DMA23_IRQHandler(void)
{
	irqController->handleIrq(7);
}

void DMA8_DMA24_IRQHandler(void)
{
	irqController->handleIrq(8);
}

void DMA9_DMA25_IRQHandler(void)
{
	irqController->handleIrq(9);
}

void DMA10_DMA26_IRQHandler(void)
{
	irqController->handleIrq(10);
}

void DMA11_DMA27_IRQHandler(void)
{
	irqController->handleIrq(11);
}

void DMA12_DMA28_IRQHandler(void)
{
	irqController->handleIrq(12);
}

void DMA13_DMA29_IRQHandler(void)
{
	irqController->handleIrq(13);
}

void DMA14_DMA30_IRQHandler(void)
{
	irqController->handleIrq(14);
}

void DMA15_DMA31_IRQHandler(void)
{
	irqController->handleIrq(15);
}

void DMA_ERROR_IRQHandler(void)
{
	irqController->handleIrq(16);
}

void CTI0_ERROR_IRQHandler(void)
{
	irqController->handleIrq(17);
}

void CTI1_ERROR_IRQHandler(void)
{
	irqController->handleIrq(18);
}

void CORE_IRQHandler(void)
{
	irqController->handleIrq(19);
}

void LPUART1_IRQHandler(void)
{
	irqController->handleIrq(20);
}

void LPUART2_IRQHandler(void)
{
	irqController->handleIrq(21);
}

void LPUART3_IRQHandler(void)
{
	irqController->handleIrq(22);
}

void LPUART4_IRQHandler(void)
{
	irqController->handleIrq(23);
}

void LPUART5_IRQHandler(void)
{
	irqController->handleIrq(24);
}

void LPUART6_IRQHandler(void)
{
	irqController->handleIrq(25);
}

void LPUART7_IRQHandler(void)
{
	irqController->handleIrq(26);
}

void LPUART8_IRQHandler(void)
{
	irqController->handleIrq(27);
}

void LPI2C1_IRQHandler(void)
{
	irqController->handleIrq(28);
}

void LPI2C2_IRQHandler(void)
{
	irqController->handleIrq(29);
}

void LPI2C3_IRQHandler(void)
{
	irqController->handleIrq(30);
}

void LPI2C4_IRQHandler(void)
{
	irqController->handleIrq(31);
}

void LPSPI1_IRQHandler(void)
{
	irqController->handleIrq(32);
}

void LPSPI2_IRQHandler(void)
{
	irqController->handleIrq(33);
}

void LPSPI3_IRQHandler(void)
{
	irqController->handleIrq(34);
}

void LPSPI4_IRQHandler(void)
{
	irqController->handleIrq(35);
}

void CAN1_IRQHandler(void)
{
	irqController->handleIrq(36);
}

void CAN2_IRQHandler(void)
{
	irqController->handleIrq(37);
}

void FLEXRAM_IRQHandler(void)
{
	irqController->handleIrq(38);
}

void KPP_IRQHandler(void)
{
	irqController->handleIrq(39);
}

void TSC_DIG_IRQHandler(void)
{
	irqController->handleIrq(40);
}

void GPR_IRQ_IRQHandler(void)
{
	irqController->handleIrq(41);
}

void LCDIF_IRQHandler(void)
{
	irqController->handleIrq(42);
}

void CSI_IRQHandler(void)
{
	irqController->handleIrq(43);
}

void PXP_IRQHandler(void)
{
	irqController->handleIrq(44);
}

void WDOG2_IRQHandler(void)
{
	irqController->handleIrq(45);
}

void SNVS_HP_WRAPPER_IRQHandler(void)
{
	irqController->handleIrq(46);
}

void SNVS_HP_WRAPPER_TZ_IRQHandler(void)
{
	irqController->handleIrq(47);
}

void SNVS_LP_WRAPPER_IRQHandler(void)
{
	irqController->handleIrq(48);
}

void CSU_IRQHandler(void)
{
	irqController->handleIrq(49);
}

void DCP_IRQHandler(void)
{
	irqController->handleIrq(50);
}

void DCP_VMI_IRQHandler(void)
{
	irqController->handleIrq(51);
}

void Reserved68_IRQHandler(void)
{
	irqController->handleIrq(52);
}

void TRNG_IRQHandler(void)
{
	irqController->handleIrq(53);
}

void SJC_IRQHandler(void)
{
	irqController->handleIrq(54);
}

void BEE_IRQHandler(void)
{
	irqController->handleIrq(55);
}

void SAI1_IRQHandler(void)
{
	irqController->handleIrq(56);
}

void SAI2_IRQHandler(void)
{
	irqController->handleIrq(57);
}

void SAI3_RX_IRQHandler(void)
{
	irqController->handleIrq(58);
}

void SAI3_TX_IRQHandler(void)
{
	irqController->handleIrq(59);
}

void SPDIF_IRQHandler(void)
{
	irqController->handleIrq(60);
}

void PMU_EVENT_IRQHandler(void)
{
	irqController->handleIrq(61);
}

void Reserved78_IRQHandler(void)
{
	irqController->handleIrq(62);
}

void TEMP_LOW_HIGH_IRQHandler(void)
{
	irqController->handleIrq(63);
}

void TEMP_PANIC_IRQHandler(void)
{
	irqController->handleIrq(64);
}

void USB_PHY1_IRQHandler(void)
{
	irqController->handleIrq(65);
}

void USB_PHY2_IRQHandler(void)
{
	irqController->handleIrq(66);
}

void ADC1_IRQHandler(void)
{
	irqController->handleIrq(67);
}

void ADC2_IRQHandler(void)
{
	irqController->handleIrq(68);
}

void DCDC_IRQHandler(void)
{
	irqController->handleIrq(69);
}

void Reserved86_IRQHandler(void)
{
	irqController->handleIrq(70);
}

void Reserved87_IRQHandler(void)
{
	irqController->handleIrq(71);
}

void GPIO1_INT0_IRQHandler(void)
{
	irqController->handleIrq(72);
}

void GPIO1_INT1_IRQHandler(void)
{
	irqController->handleIrq(73);
}

void GPIO1_INT2_IRQHandler(void)
{
	irqController->handleIrq(74);
}

void GPIO1_INT3_IRQHandler(void)
{
	irqController->handleIrq(75);
}

void GPIO1_INT4_IRQHandler(void)
{
	irqController->handleIrq(76);
}

void GPIO1_INT5_IRQHandler(void)
{
	irqController->handleIrq(77);
}

void GPIO1_INT6_IRQHandler(void)
{
	irqController->handleIrq(78);
}

void GPIO1_INT7_IRQHandler(void)
{
	irqController->handleIrq(79);
}

void GPIO1_Combined_0_15_IRQHandler(void)
{
	irqController->handleIrq(80);
}

void GPIO1_Combined_16_31_IRQHandler(void)
{
	irqController->handleIrq(81);
}

void GPIO2_Combined_0_15_IRQHandler(void)
{
	irqController->handleIrq(82);
}

void GPIO2_Combined_16_31_IRQHandler(void)
{
	irqController->handleIrq(83);
}

void GPIO3_Combined_0_15_IRQHandler(void)
{
	irqController->handleIrq(84);
}

void GPIO3_Combined_16_31_IRQHandler(void)
{
	irqController->handleIrq(85);
}

void GPIO4_Combined_0_15_IRQHandler(void)
{
	irqController->handleIrq(86);
}

void GPIO4_Combined_16_31_IRQHandler(void)
{
	irqController->handleIrq(87);
}

void GPIO5_Combined_0_15_IRQHandler(void)
{
	irqController->handleIrq(88);
}

void GPIO5_Combined_16_31_IRQHandler(void)
{
	irqController->handleIrq(89);
}

void FLEXIO1_IRQHandler(void)
{
	irqController->handleIrq(90);
}

void FLEXIO2_IRQHandler(void)
{
	irqController->handleIrq(91);
}

void WDOG1_IRQHandler(void)
{
	irqController->handleIrq(92);
}

void RTWDOG_IRQHandler(void)
{
	irqController->handleIrq(93);
}

void EWM_IRQHandler(void)
{
	irqController->handleIrq(94);
}

void CCM_1_IRQHandler(void)
{
	irqController->handleIrq(95);
}

void CCM_2_IRQHandler(void)
{
	irqController->handleIrq(96);
}

void GPC_IRQHandler(void)
{
	irqController->handleIrq(97);
}

void SRC_IRQHandler(void)
{
	irqController->handleIrq(98);
}

void Reserved115_IRQHandler(void)
{
	irqController->handleIrq(99);
}

void GPT1_IRQHandler(void)
{
	irqController->handleIrq(100);
}

void GPT2_IRQHandler(void)
{
	irqController->handleIrq(101);
}

void PWM1_0_IRQHandler(void)
{
	irqController->handleIrq(102);
}

void PWM1_1_IRQHandler(void)
{
	irqController->handleIrq(103);
}

void PWM1_2_IRQHandler(void)
{
	irqController->handleIrq(104);
}

void PWM1_3_IRQHandler(void)
{
	irqController->handleIrq(105);
}

void PWM1_FAULT_IRQHandler(void)
{
	irqController->handleIrq(106);
}

void FLEXSPI2_IRQHandler(void)
{
	irqController->handleIrq(107);
}

void FLEXSPI_IRQHandler(void)
{
	irqController->handleIrq(108);
}

void SEMC_IRQHandler(void)
{
	irqController->handleIrq(109);
}

void USDHC1_IRQHandler(void)
{
	irqController->handleIrq(110);
}

void USDHC2_IRQHandler(void)
{
	irqController->handleIrq(111);
}

void USB_OTG2_IRQHandler(void)
{
	irqController->handleIrq(112);
}

void USB_OTG1_IRQHandler(void)
{
	irqController->handleIrq(113);
}

void ENET_IRQHandler(void)
{
	irqController->handleIrq(114);
}

void ENET_1588_Timer_IRQHandler(void)
{
	irqController->handleIrq(115);
}

void XBAR1_IRQ_0_1_IRQHandler(void)
{
	irqController->handleIrq(116);
}

void XBAR1_IRQ_2_3_IRQHandler(void)
{
	irqController->handleIrq(117);
}

void ADC_ETC_IRQ0_IRQHandler(void)
{
	irqController->handleIrq(118);
}

void ADC_ETC_IRQ1_IRQHandler(void)
{
	irqController->handleIrq(119);
}

void ADC_ETC_IRQ2_IRQHandler(void)
{
	irqController->handleIrq(120);
}

void ADC_ETC_ERROR_IRQ_IRQHandler(void)
{
	irqController->handleIrq(121);
}

void PIT_IRQHandler(void)
{
	irqController->handleIrq(122);
}

void ACMP1_IRQHandler(void)
{
	irqController->handleIrq(123);
}

void ACMP2_IRQHandler(void)
{
	irqController->handleIrq(124);
}

void ACMP3_IRQHandler(void)
{
	irqController->handleIrq(125);
}

void ACMP4_IRQHandler(void)
{
	irqController->handleIrq(126);
}

void Reserved143_IRQHandler(void)
{
	irqController->handleIrq(127);
}

void Reserved144_IRQHandler(void)
{
	irqController->handleIrq(128);
}

void ENC1_IRQHandler(void)
{
	irqController->handleIrq(129);
}

void ENC2_IRQHandler(void)
{
	irqController->handleIrq(130);
}

void ENC3_IRQHandler(void)
{
	irqController->handleIrq(131);
}

void ENC4_IRQHandler(void)
{
	irqController->handleIrq(132);
}

void TMR1_IRQHandler(void)
{
	irqController->handleIrq(133);
}

void TMR2_IRQHandler(void)
{
	irqController->handleIrq(134);
}

void TMR3_IRQHandler(void)
{
	irqController->handleIrq(135);
}

void TMR4_IRQHandler(void)
{
	irqController->handleIrq(136);
}

void PWM2_0_IRQHandler(void)
{
	irqController->handleIrq(137);
}

void PWM2_1_IRQHandler(void)
{
	irqController->handleIrq(138);
}

void PWM2_2_IRQHandler(void)
{
	irqController->handleIrq(139);
}

void PWM2_3_IRQHandler(void)
{
	irqController->handleIrq(140);
}

void PWM2_FAULT_IRQHandler(void)
{
	irqController->handleIrq(141);
}

void PWM3_0_IRQHandler(void)
{
	irqController->handleIrq(142);
}

void PWM3_1_IRQHandler(void)
{
	irqController->handleIrq(143);
}

void PWM3_2_IRQHandler(void)
{
	irqController->handleIrq(144);
}

void PWM3_3_IRQHandler(void)
{
	irqController->handleIrq(145);
}

void PWM3_FAULT_IRQHandler(void)
{
	irqController->handleIrq(146);
}

void PWM4_0_IRQHandler(void)
{
	irqController->handleIrq(147);
}

void PWM4_1_IRQHandler(void)
{
	irqController->handleIrq(148);
}

void PWM4_2_IRQHandler(void)
{
	irqController->handleIrq(149);
}

void PWM4_3_IRQHandler(void)
{
	irqController->handleIrq(150);
}

void PWM4_FAULT_IRQHandler(void)
{
	irqController->handleIrq(151);
}

void ENET2_IRQHandler(void)
{
	irqController->handleIrq(152);
}

void ENET2_1588_Timer_IRQHandler(void)
{
	irqController->handleIrq(153);
}

void CAN3_IRQHandler(void)
{
	irqController->handleIrq(154);
}

void Reserved171_IRQHandler(void)
{
	irqController->handleIrq(155);
}

void FLEXIO3_IRQHandler(void)
{
	irqController->handleIrq(156);
}

void GPIO6_7_8_9_IRQHandler(void)
{
	irqController->handleIrq(157);
}

#ifdef __cplusplus
}
#endif

}
