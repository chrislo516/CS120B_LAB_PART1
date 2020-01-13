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
#include <stdlib.h>
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0x00; PORTC = 0xFF;
	DDRD = 0xFF; PORTD = 0x00;
	
	unsigned char wa = 0x00; // weight A
	unsigned char wb = 0x00; // weight B
	unsigned char wc = 0x00; // weight C
	unsigned short totalW = 0x00; // Total weight
	unsigned char diffW = 0x00;
    	unsigned char tmpW = 0x00;
/* Insert your solution below */
    while (1) {
	wa = PINA;
	wb = PINB;
	wc = PINC;
	totalW = wa+wb+wc;
	if(totalW >= 0x008C){
	   tmpW = 0x01;
	}
	if(abs((wa-wc)) >= 0x50){
	   diffW = 0x02;
	}
	PORTD = tmpW|diffW;
	totalW = 0x0000;
	diffW = 0x00;
	tmpW = 0x00;
    }
    return 0;
}
