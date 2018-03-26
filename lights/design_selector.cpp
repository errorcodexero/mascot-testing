#include "design_selector.h"
#include "SevSeg.h"

SevSeg sevseg;

//ten position pot to pick 1s place 0-9
const uint8_t ONES_SELECTOR_IN_PIN = 1;
//three position switch to pick 100s place 100-300
const uint8_t TENS_SELECTOR_IN_PIN_A = 4;
const uint8_t TENS_SELECTOR_IN_PIN_B = 5;

void set_up_seven_segment_display() {
	const uint8_t DIGIT_COUNT = 3;
	uint8_t digit_pins[] = {//which digit to light up, pins on arduino map to pins on display
		11, //Dig 1 - 12
		12, //Dig 2 - 9
		13  //Dig 3 - 8
	};
	uint8_t segment_pins[] = {//pins on arduino which map to A through G plus DP on the display, comments are the pins on the display
		3, //A  - 11
		4, //B  -  7
		5, //C  -  4
		6, //D  -  2
		7, //E  -  1
		8, //F  - 10 
		9, //G  -  5
		10 //DP -  3
	};
	const bool RESISTORS_ON_SEGMENTS = true;
	const uint8_t HARDWARE_CONFIG = COMMON_CATHODE;

	sevseg.begin(HARDWARE_CONFIG, DIGIT_COUNT, digit_pins, segment_pins, RESISTORS_ON_SEGMENTS);
	sevseg.setBrightness(100);//0-100 note: 0 is not off
}


uint8_t interpret_10_turn_pot(uint16_t a){//parse the ten position pot
	uint16_t limits[] = {
		0,
		80,
		160,
		230,
		300,
		370,
		440,
		510,
		590,
		675
	};
	for(uint8_t i = 0; i < 10; i++){
		if(a < (limits[i] + 30)){
			return  9 - i;
		}
	}
	return 0;//error?
}

uint16_t parse_tens(){//read the two analog inputs into 100, 200, or 300
	const uint16_t HIGH_POWER = 1000;//values higher than this are dio high
	uint16_t a = analogRead(TENS_SELECTOR_IN_PIN_A);
	uint16_t b = analogRead(TENS_SELECTOR_IN_PIN_B);
	if(a > HIGH_POWER){
		return 100;
	} 
	if(b > HIGH_POWER){
		return 300;
	}
	return 200;	
}

uint16_t get_design_selection(){
	return parse_tens() + interpret_10_turn_pot(analogRead(ONES_SELECTOR_IN_PIN));
}

void set_seven_segment_display(const uint16_t SELECTOR){
	sevseg.setNumber(SELECTOR, 0);//number to display followed by where to place decimal point
	sevseg.refreshDisplay();
}
