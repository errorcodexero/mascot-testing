#include "colors.h"

CRGB leds[Constants::NUMBER_OF_LEDS];

void setup() {
	FastLED.addLeds <LED_CONTROLLER, Constants::LED_STRIP_DATA_PIN, COLOR_ORDER>(leds, Constants::NUMBER_OF_LEDS);
	FastLED.setBrightness(Constants::BRIGHTNESS);
	Serial.begin(9600);
}

void loop(){
	//FastLED.clear();
	for(unsigned frame_index = 0; frame_index < Constants::TOTAL_FRAME_COUNT; frame_index++){
		for(unsigned led_index = 0; led_index < Constants::NUMBER_OF_LEDS; led_index++){
			size_t i = &(FRAMES[frame_index][led_index]);
			uint8_t pixel = pgm_read_byte(i);
			//Serial.println(pixel);
			leds[led_index] = index_to_color(pixel);
		}
		FastLED.show();
		delay(200);//TODO
	}
}

