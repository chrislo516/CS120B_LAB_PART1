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
	DDRC = 0xFF; PORTC = 0x00;
	
	unsigned char cntavail = 0x00; // Parking space availble
	unsigned char park1 = 0x00; // 1st park tmp
	unsigned char park2 = 0x00; // 2nd park tmp
	unsigned char park3 = 0x00; // 3rd park tmp
	unsigned char park4 = 0x00; // 4th park tmp

    /* Insert your solution below */
    while (1) {
	// assign each varibles to its pin
	park1 = PINA & 0x01;
	park2 = PINA & 0x02;
        park3 = PINA & 0x04;
        park4 = PINA & 0x08;

	//If we just sum up the parking, we will have a number that is bigger than 4
	//therefore, we can right shift each pins by its index-1. We will get either
	//1 or 0, and 1 means the parking space is parked, 0 means avaible.
	
	park2 = park2 >> 1;
	park3 = park3 >> 2;
	park4 = park4 >> 3;

	cntavail = park1 + park2 + park3 + park4;
	cntavail = 0x04 - cntavail;
	
	if(cntavail == 0x00){
		PORTC = 0x80;
	}else{
		PORTC = cntavail;
	}
    }
    return 0;
}
