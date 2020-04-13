/*	Author: gyama009
 *  Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #  Exercise #
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
	DDRA = 0x00; PORTA = 0xFF; // Configure port A's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs
    	unsigned char temp = 0x00; // Holds temp value
	unsigned char hold = 0x00; // Holds hold value
	while (1) {
		temp = PINA;
		hold = (((temp & 0x0F) >= 1) << 5) + (((temp & 0x0F) >= 3) << 4) + (((temp & 0x0F) >= 5) << 3) + (((temp & 0x0F) >= 7) << 2) + (((temp & 0x0F) >= 10) << 1) + (((temp & 0x0F) >= 13) << 0) + (((temp & 0x0F) <= 4) << 6);
		if((PINA & 0x10) && (PINA & 0x20) && !(PINA & 0x40)){
			hold += 0x80;
		}
		PORTC = hold;
	}
	return 0;
}
