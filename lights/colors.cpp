#include "colors.h"

CRGB index_to_color(const uint8_t COLOR_INDEX){
	switch(COLOR_INDEX){
		case Color_index::BLACK:
			return CRGB(0,0,0);
		case Color_index::WHITE:
			return CRGB(255,255,255);
		case Color_index::RED:
			return CRGB(255,0,0);
		case Color_index::GREEN:
			return CRGB(0,255,0);
		case Color_index::BLUE:
			return CRGB(0,0,255);
		case Color_index::CYAN:
			return CRGB(0,255,255);
		case Color_index::MAGENTA:
			return CRGB(255,0,255);
		case Color_index::YELLOW:
			return CRGB(255,255,0);
		case Color_index::ORANGE:
			return CRGB(255,136,0);
		case Color_index::PINK:
			return CRGB(255,100,100);
		case Color_index::DIM_RED:
			return CRGB(187,0,0);
		case Color_index::DIM_BLUE:
			return CRGB(0,0,187);
		case Color_index::DIM_CYAN:
			return CRGB(0,51,51);
		case Color_index::DIM_YELLOW:
			return CRGB(187,187,0);
		case Color_index::DIM_ORANGE:
			return CRGB(187,102,0);
		case Color_index::DARK_CYAN:
			return CRGB(0,34,34);
		default:
			//Serial.println("ERROR");
			return CRGB(0,0,0);
	}
}
