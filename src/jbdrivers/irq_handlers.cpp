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
	irqController->handleIrq((IRQn_Type)PendSV_IRQn);
	while(1);
}

void SysTick_Handler(void)
{
	irqController->handleIrq(SysTick_IRQn);
}

void DMA0_DMA16_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)0);
}

void DMA1_DMA17_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)1);
}

void DMA2_DMA18_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)2);
}

void DMA3_DMA19_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)3);
}

void DMA4_DMA20_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)4);
}

void DMA5_DMA21_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)5);
}

void DMA6_DMA22_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)6);
}

void DMA7_DMA23_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)7);
}

void DMA8_DMA24_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)8);
}

void DMA9_DMA25_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)9);
}

void DMA10_DMA26_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)10);
}

void DMA11_DMA27_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)11);
}

void DMA12_DMA28_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)12);
}

void DMA13_DMA29_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)13);
}

void DMA14_DMA30_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)14);
}

void DMA15_DMA31_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)15);
}

void DMA_ERROR_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)16);
}

void CTI0_ERROR_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)17);
}

void CTI1_ERROR_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)18);
}

void CORE_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)19);
}

void LPUART1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)20);
}

void LPUART2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)21);
}

void LPUART3_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)22);
}

void LPUART4_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)23);
}

void LPUART5_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)24);
}

void LPUART6_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)25);
}

void LPUART7_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)26);
}

void LPUART8_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)27);
}

void LPI2C1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)28);
}

void LPI2C2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)29);
}

void LPI2C3_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)30);
}

void LPI2C4_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)31);
}

void LPSPI1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)32);
}

void LPSPI2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)33);
}

void LPSPI3_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)34);
}

void LPSPI4_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)35);
}

void CAN1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)36);
}

void CAN2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)37);
}

void FLEXRAM_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)38);
}

void KPP_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)39);
}

void TSC_DIG_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)40);
}

void GPR_IRQ_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)41);
}

void LCDIF_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)42);
}

void CSI_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)43);
}

void PXP_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)44);
}

void WDOG2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)45);
}

void SNVS_HP_WRAPPER_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)46);
}

void SNVS_HP_WRAPPER_TZ_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)47);
}

void SNVS_LP_WRAPPER_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)48);
}

void CSU_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)49);
}

void DCP_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)50);
}

void DCP_VMI_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)51);
}

void Reserved68_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)52);
}

void TRNG_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)53);
}

void SJC_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)54);
}

void BEE_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)55);
}

void SAI1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)56);
}

void SAI2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)57);
}

void SAI3_RX_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)58);
}

void SAI3_TX_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)59);
}

void SPDIF_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)60);
}

void PMU_EVENT_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)61);
}

void Reserved78_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)62);
}

void TEMP_LOW_HIGH_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)63);
}

void TEMP_PANIC_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)64);
}

void USB_PHY1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)65);
}

void USB_PHY2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)66);
}

void ADC1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)67);
}

void ADC2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)68);
}

void DCDC_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)69);
}

void Reserved86_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)70);
}

void Reserved87_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)71);
}

void GPIO1_INT0_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)72);
}

void GPIO1_INT1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)73);
}

void GPIO1_INT2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)74);
}

void GPIO1_INT3_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)75);
}

void GPIO1_INT4_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)76);
}

void GPIO1_INT5_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)77);
}

void GPIO1_INT6_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)78);
}

void GPIO1_INT7_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)79);
}

void GPIO1_Combined_0_15_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)80);
}

void GPIO1_Combined_16_31_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)81);
}

void GPIO2_Combined_0_15_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)82);
}

void GPIO2_Combined_16_31_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)83);
}

void GPIO3_Combined_0_15_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)84);
}

void GPIO3_Combined_16_31_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)85);
}

void GPIO4_Combined_0_15_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)86);
}

void GPIO4_Combined_16_31_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)87);
}

void GPIO5_Combined_0_15_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)88);
}

void GPIO5_Combined_16_31_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)89);
}

void FLEXIO1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)90);
}

void FLEXIO2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)91);
}

void WDOG1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)92);
}

void RTWDOG_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)93);
}

void EWM_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)94);
}

void CCM_1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)95);
}

void CCM_2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)96);
}

void GPC_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)97);
}

void SRC_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)98);
}

void Reserved115_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)99);
}

void GPT1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)100);
}

void GPT2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)101);
}

void PWM1_0_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)102);
}

void PWM1_1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)103);
}

void PWM1_2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)104);
}

void PWM1_3_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)105);
}

void PWM1_FAULT_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)106);
}

void FLEXSPI2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)107);
}

void FLEXSPI_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)108);
}

void SEMC_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)109);
}

void USDHC1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)110);
}

void USDHC2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)111);
}

void USB_OTG2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)112);
}

void USB_OTG1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)113);
}

void ENET_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)114);
}

void ENET_1588_Timer_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)115);
}

void XBAR1_IRQ_0_1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)116);
}

void XBAR1_IRQ_2_3_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)117);
}

void ADC_ETC_IRQ0_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)118);
}

void ADC_ETC_IRQ1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)119);
}

void ADC_ETC_IRQ2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)120);
}

void ADC_ETC_ERROR_IRQ_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)121);
}

void PIT_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)122);
}

void ACMP1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)123);
}

void ACMP2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)124);
}

void ACMP3_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)125);
}

void ACMP4_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)126);
}

void Reserved143_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)127);
}

void Reserved144_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)128);
}

void ENC1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)129);
}

void ENC2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)130);
}

void ENC3_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)131);
}

void ENC4_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)132);
}

void TMR1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)133);
}

void TMR2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)134);
}

void TMR3_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)135);
}

void TMR4_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)136);
}

void PWM2_0_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)137);
}

void PWM2_1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)138);
}

void PWM2_2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)139);
}

void PWM2_3_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)140);
}

void PWM2_FAULT_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)141);
}

void PWM3_0_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)142);
}

void PWM3_1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)143);
}

void PWM3_2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)144);
}

void PWM3_3_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)145);
}

void PWM3_FAULT_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)146);
}

void PWM4_0_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)147);
}

void PWM4_1_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)148);
}

void PWM4_2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)149);
}

void PWM4_3_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)150);
}

void PWM4_FAULT_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)151);
}

void ENET2_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)152);
}

void ENET2_1588_Timer_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)153);
}

void CAN3_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)154);
}

void Reserved171_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)155);
}

void FLEXIO3_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)156);
}

void GPIO6_7_8_9_IRQHandler(void)
{
	irqController->handleIrq((IRQn_Type)157);
}

#ifdef __cplusplus
}
#endif

}
