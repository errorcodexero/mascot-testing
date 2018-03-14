#ifndef LIGHTS_CONSTANTS_H
#define LIGHTS_CONSTANTS_H

#define LED_CONTROLLER WS2812B
#define COLOR_ORDER GRB

struct Lights_constants{
	static const unsigned NUMBER_OF_LEDS = 192;
	static const unsigned LED_STRIP_DATA_PIN = 3;
	static const byte MAX_BRIGHTNESS = 255 * .5;
	static constexpr double LEDS_PER_INCH = 1.3333333;	

	static const unsigned FRAME_LENGTH = 100;//ms
};

#endif
