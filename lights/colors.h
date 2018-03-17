#ifndef COLORS_H
#define COLORS_H

#include "FastLED.h"

enum Color_index{
	BLACK,
	WHITE,
	RED,
	GREEN,
	BLUE,
	CYAN,
	MAGENTA,
	YELLOW,
	ORANGE,
	PINK,
	DIM_RED,
	DIM_BLUE,
	DIM_CYAN,
	DIM_YELLOW,
	DIM_ORANGE,
	DARK_CYAN
};

const uint8_t NUMBER_OF_LEDS = 192;

const uint8_t Frame[] = {
	
};

CRGB byte_to_color(const uint8_t INDEX){
	return byte_to_color((Color_index)INDEX);
}

CRGB index_to_color(const Color_index COLOR_INDEX){
	switch(COLOR_INDEX){
		case BLACK:
			return CRGB(0,0,0);
		case WHITE:
			return CRGB(255,255,255);
		case RED:
			return CRGB(255,0,0);
		case GREEN:
			return CRGB(0,255,0);
		case BLUE:
			return CRGB(0,0,255);
		case CYAN:
			return CRGB(0,255,255);
		case MAGENTA:
			return CRGB(255,0,255);
		case YELLOW:
			return CRGB(255,255,0);
		case ORANGE:
			return CRGB(255,136,0);
		case PINK:
			return CRGB(255,204,204);
		case DIM_RED:
			return CRGB(187,0,0);
		case DIM_BLUE:
			return CRGB(0,0,187);
		case DIM_CYAN:
			return CRGB(0,51,51);
		case DIM_YELLOW:
			return CRGB(187,187,0);
		case DIM_ORANGE:
			return CRGB(187,102,0);
		case DARK_CYAN:
			return CRGB(0,34,34);
		default:
			Serial.println("ERROR");
			return CRGB(0,0,0);
	}
}

#endif
