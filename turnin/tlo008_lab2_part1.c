/*	Author: tlo008
 *      Partner(s) Name: 
 *	Lab Section:
 *	Assignment: Lab #2  Exercise #1
 *	Exercise Description: Garage open at night-- A garage door sensor connects to PA0 
 *	(1 means door open), and a light sensor connects to PA1 (1 means light is sensed).
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	unsigned char tmp1 = 0x00; //tmp1 = PA1
	unsigned char tmp0 = 0x00; //tmp0 = PA0
    /* Insert your solution below */
    while (1) {

	tmp1 = PINA & 0x01;
	tmp0 = PINA & 0x02;

	if((tmp1 == 0x01)&&(tmp0 == 0x00)){
		PORTB = 0x01;
	}else{
		PORTB = 0x00;
	}
    }
    return 0;
}
