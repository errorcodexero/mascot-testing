#include "design_selector.h"

//ten position pot to pick 1s place 0-9
const uint8_t ONES_SELECTOR_IN_PIN = 1;
//three position switch to pick 100s place 100-300
const uint8_t TENS_SELECTOR_IN_PIN_A = 4;
const uint8_t TENS_SELECTOR_IN_PIN_B = 5;

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
			return 9 - i;
		}
	}
	return 0;//error?
}

uint16_t parse_tens(){//read the two analog inputs into 100, 200, or 300
	const uint16_t HIGH_POWER = 1000;//values higher than this are dio high
	uint16_t a = analogRead(TENS_SELECTOR_IN_PIN_A);
	uint16_t b = analogRead(TENS_SELECTOR_IN_PIN_B);
	if(a > HIGH_POWER){
		return 0;
	} 
	if(b > HIGH_POWER){
		return 20;
	}
	return 10;
}

uint16_t get_scaled_design_selection(){
	return (parse_tens() + 10) * 10 + interpret_10_turn_pot(analogRead(ONES_SELECTOR_IN_PIN));
}

uint8_t get_design_selection(){
	return parse_tens() + interpret_10_turn_pot(analogRead(ONES_SELECTOR_IN_PIN));
}

void set_seven_segment_display(const uint16_t SELECTOR,SevSeg& sevseg){
	sevseg.setNumber(SELECTOR, 0);//number to display followed by where to place decimal point
	sevseg.refreshDisplay();
}

void set_seven_segment_display(char* SELECTOR,SevSeg& sevseg){
	sevseg.setChars(SELECTOR);
	sevseg.refreshDisplay();
}
