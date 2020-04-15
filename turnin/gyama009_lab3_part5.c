/*	Author: gyama009
 *  Partner(s) Name: 
 *	Lab Section:022
 *	Assignment: Lab #3  Exercise #5
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
	DDRD = 0x00; PORTD = 0xFF; // Configure port D's 8 pins as inputs
	DDRB = 0xFE; PORTB = 0x00; // Configure port B's 8 pins as outputs
	unsigned char temp = 0x00; // temp variable that holds temp
	while (1) {
		temp = ((PIND & 0xFF) << 1) + (PINB & 0x01);
		if(temp >= 0x46){
			PORTB = 0x02;
		}
		else if((temp > 0x05) && (temp < 0x46)){
			PORTB = 0x04;
		}
		else{
			PORTB = 0x00;
		}
	}
	return 0;
}
