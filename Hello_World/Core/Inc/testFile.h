/*
 * testFile.h
 *
 *	This file encapsules different modular system functions that are used to test the
 *	actuators, GPIO pins, and logic on the STM32. Pins must be defined prior using this
 *	file. Thus, the functions are made so the user provides the pin in the declaration.
 *  Created on: Aug 10, 2026
 *  Last Modified: Aug 10, 2026
 *      Author: Javier Acosta
 */

//#define DEBUG
#define DEBUG




#ifndef INC_TESTFILE_H_
#define INC_TESTFILE_H_

/* Function list objectives:
 * Function that test servo motors
 * Function that test motors
 * Function that test bidirectional motors
 * Function that test a stepper motor. Hardware module required: I don't have an AC source@!!!!!!!!
 * Function that acts as a menu option
 *
 * Like I said, pins should pass as parameters.*/
/*	Test file to demonstrate some basic functionalities of C in stm32 board.*/


int setPWMDutyCycle(int dutyCycle);
int MotorSignal();

void hello();

/*	This function serves as a menu in order to test various features of the microcontroller for this project.
 * 	Is intended for the user to type something related to the menu given, so then a function can be called in response.
 * 	@param -none
 * 	@return -none*/
void display_menu();

#endif /* INC_TESTFILE_H_ */
