/*
 * Task.c
 *
 *  Created on: Dec 5, 2022
 *      Author: tirua
 */

#include "Task.h"
#include "main.h"

void Link_led1(){
	// chay trong 0.5 giay
	HAL_GPIO_TogglePin(Led_red1_GPIO_Port, Led_red1_Pin);
}
void Link_led2(){
	// chay trong 1 giay
	HAL_GPIO_TogglePin(Led_red2_GPIO_Port, Led_red2_Pin);
}
void Link_led3(){
	// chay trong 1.5 giay
	HAL_GPIO_TogglePin(Led_red3_GPIO_Port, Led_red3_Pin);
}
void Link_led4(){
	// chay trong 2 giay
	HAL_GPIO_TogglePin(Led_red4_GPIO_Port, Led_red4_Pin);
}
void Link_led5(){
	// chay 1 lan
	HAL_GPIO_TogglePin(Led_red5_GPIO_Port, Led_red5_Pin);
}
