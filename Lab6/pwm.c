#include "lab6_PWM.h"

void pwmInit(void){
	
	TIM1->CR1 |= TIM_CR1_CEN;
	TIM1->CR2 |= TIM_CR2_OIS1;
	TIM1->EGR |= TIM_EGR_UG;
	
	TIM1->CCMR1 &= ~TIM_CCMR1_OC1M;
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1PE | TIM_CCMR1_OC1FE;
	
	TIM1->CCER |= TIM_CCER_CC1E;
	
	TIM1->PSC = 23999;
	TIM1->ARR = 10;
	TIM1->CCR1 = 5;
	
	TIM1->BDTR |= TIM_BDTR_MOE | TIM_BDTR_OSSI;
	TIM1->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN;
}

void pwmUpdate(unsigned int inCCR1){
	TIM1->CCR1 = inCCR1;
	//TIM1->EGR |= TIM_EGR_UG;
}

void checkButton(void){
	if((GPIOA->IDR & GPIO_IDR_IDR0) == 1)
		pwmUpdate(3);
	else
		pwmUpdate(5);
}