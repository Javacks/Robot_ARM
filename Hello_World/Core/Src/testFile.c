/*
 * testFile.c
 *
 *  Created on: Aug 11, 2026
 *      Author: javieracosta
 */

#include <stdio.h>
#include <tim.h>
#include "testFile.h"

// Pin definitions
#define PWM_PIN TIM_CHANNEL_1		//PA8 = D9 = CN3-12

// VARIABLES********************
int ARR = 20000; 		//Value from the auto reload register. This was calculated paper
int dutyCycle = 100;	//PWM value [%] as integer form. This is for the servo motor.


void hello(){
	printf("Hello World\n");

	printf("Hello Revenge 2\n");


}

/*	This function serves as a menu in order to test various features of the microcontroller for this project.
 * 	Is intended for the user to type something related to the menu given, so then a function can be called in response.
 * 	@param -none
 * 	@return -none*/
void display_menu(){
	printf("Main Menu.\nNow testing for servo motor....\n");

	if(setPWMDutyCycle(dutyCycle))
		printf("PWMTest SuccesSful....\n");
	else
		printf("Failed to load...\n");

}

/*
 * 	@brief: Sets the PWM duty cycle based on the desire percentage. This fucntion will handle the small details
 * 			used for setting the duty cycle correctly
 * 	@note:	The Duty cycle for this particular servo motor is 2ms. Since this is a 1/10
 * 			of the PWM cycle, CCR is divided by 10 again to reflect the correct
 * 			parameter set on top of this .c file.
 * 	@parm:	Duty cycle percentage as integer (no decimal numbers).
 * 	@return:	int value registering if function was successful
 * 	*/
int setPWMDutyCycle(int dutyCycle){
	int CCR = dutyCycle*ARR/100,
		ret = 0;
	CCR /= 10;
	TIM1->CCR1 = CCR;

	//HAL_StatusTypeDef construct to check if function is passed correctly.
	//HAL_TIM_PWM_Start: starts PWM cycle
	HAL_StatusTypeDef func = HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
	if(func == HAL_OK)
	ret = 1;

	#ifdef DEBUG
		printf("\n---------BEGIN OF DEBUG--------\n");
		printf("CRR: %d. \t Duty Cycle %d%%\n", CCR, dutyCycle);
		printf("---------END OF DEBUG----------\n\n");
	#endif

	HAL_Delay(2000);	//2s pause


	HAL_TIM_PWM_Stop(&htim1, PWM_PIN);
	return ret;
}
