/*	Author: gyama009
 *  Partner(s) Name: 
 *	Lab Section:022
 *	Assignment: Lab #3  Exercise #1
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
	DDRB = 0x00; PORTB = 0xFF; // Configure port B's 8 pins as inputs
	DDRC = 0xFF; PORTC = 0x00; // Configure port C's 8 pins as outputs
    	while (1) {
		PORTC = ((PINA & 0x80) >> 7) + ((PINA & 0x40) >> 6) + ((PINA & 0x20) >> 5) +
			 ((PINA & 0x10) >> 4) + ((PINA & 0x08) >> 3) + ((PINA & 0x04) >> 2) +
			 ((PINA & 0x02) >> 1) + (PINA & 0x01) + ((PINB & 0x80) >> 7) +
			 ((PINB & 0x40) >> 6) + ((PINB & 0x20) >> 5) + ((PINB & 0x10) >> 4) +
			 ((PINB & 0x08) >> 3) + ((PINB & 0x04) >> 2) + ((PINB & 0x02) >> 1) + (PINB & 0x01); 
	}
	return 0;
}
