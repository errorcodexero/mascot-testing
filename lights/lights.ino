#include "colors.h"

CRGB leds[Constants::NUMBER_OF_LEDS];

void setup() {
	FastLED.addLeds <LED_CONTROLLER, Constants::LED_STRIP_DATA_PIN, COLOR_ORDER>(leds, Constants::NUMBER_OF_LEDS);
	FastLED.setBrightness(Constants::BRIGHTNESS);
	Serial.begin(9600);
}

void loop(){
	//FastLED.clear();
	for(unsigned frame_index = 0; frame_index < Constants::FRAME_COUNT; frame_index++){
		for(unsigned led_index = 0; led_index < Constants::NUMBER_OF_LEDS; led_index++){
			leds[led_index] = index_to_color(FRAMES[frame_index][led_index);
		}
	}
	FastLED.show();
	delay(100);//TODO
}

