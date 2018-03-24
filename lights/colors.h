#ifndef COLORS_H
#define COLORS_H

#include "FastLED.h"

#define LED_CONTROLLER WS2812B
#define COLOR_ORDER GRB

struct Constants{
	static const uint8_t NUMBER_OF_LEDS = 192;
	static const uint8_t BRIGHTNESS = 255 * 0.3;
	static const uint8_t LED_STRIP_DATA_PIN = 3;

	static const uint16_t TOTAL_FRAME_COUNT = 2;
};

enum Color_index{
	BLACK = 0,
	WHITE = 1,
	RED = 2,
	GREEN = 3,
	BLUE = 4,
	CYAN = 5,
	MAGENTA = 6,
	YELLOW = 7,
	ORANGE = 8,
	PINK = 9,
	DIM_RED = 10,
	DIM_BLUE = 11,
	DIM_CYAN = 12,
	DIM_YELLOW = 13,
	DIM_ORANGE = 14,
	DARK_CYAN = 15
};

CRGB index_to_color(const uint8_t);
const PROGMEM uint8_t FRAMES[Constants::TOTAL_FRAME_COUNT][Constants::NUMBER_OF_LEDS] = {
	{
    Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, 
    Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, 
    Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, 
    Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, 
    Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, 
    Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, 
    Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, 
    Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, 
    Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, 
    Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, 
    Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, 
    Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK, Color_index::BLACK
},
{
    Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, 
    Color_index::RED, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::RED, 
    Color_index::RED, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::RED, 
    Color_index::RED, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::RED, 
    Color_index::RED, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::RED, 
    Color_index::RED, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::RED, 
    Color_index::RED, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::RED, 
    Color_index::RED, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::RED, 
    Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, 
    Color_index::RED, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::RED, 
    Color_index::RED, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::BLACK, Color_index::BLACK, Color_index::RED, Color_index::RED, Color_index::RED, 
    Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED, Color_index::RED
}
};

#endif
