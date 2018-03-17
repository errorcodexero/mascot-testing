#ifndef COLORS_H
#define COLORS_H

#include "FastLED.h"

#define LED_CONTROLLER WS2812B
#define COLOR_ORDER GRB

struct Constants{
	static const uint8_t NUMBER_OF_LEDS = 192;
	static const uint8_t BRIGHTNESS = 255 * 0.3;
	static const uint8_t LED_STRIP_DATA_PIN = 3;

	static const uint8_t FRAME_COUNT = 1;
};

enum class Color_index{
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

CRGB index_to_color(const Color_index COLOR_INDEX);

CRGB index_to_color(const uint8_t);

const uint8_t FRAMES[Constants::FRAME_COUNT][Constants::NUMBER_OF_LEDS] = {
	{
	    static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), 
	    static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLUE), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), 
	    static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::GREEN), static_cast<uint8_t>(Color_index::GREEN), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), 
	    static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::GREEN), static_cast<uint8_t>(Color_index::GREEN), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), 
	    static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), 
	    static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), 
	    static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), 
	    static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), 
	    static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), 
	    static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), 
	    static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::BLACK), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), 
	    static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE), static_cast<uint8_t>(Color_index::WHITE)
	}
};

#endif
