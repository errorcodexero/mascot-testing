#ifndef LIGHTS_CONSTANTS_H
#define LIGHTS_CONSTANTS_H

#define LED_CONTROLLER WS2812B
#define COLOR_ORDER GRB

struct Lights_constants{
	static const uint8_t NUMBER_OF_LEDS = 192;
	static const uint8_t LED_STRIP_DATA_PIN = 3;
	static const uint8_t MAX_BRIGHTNESS = 255 * 0.5;
	//static constexpr float LEDS_PER_INCH = 1.3333333;	

	static const unsigned FRAME_LENGTH = 100;//ms
};

#endif
