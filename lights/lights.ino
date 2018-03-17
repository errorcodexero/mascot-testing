#include "colors.h"

#define LED_CONTROLLER WS2812B
#define COLOR_ORDER GRB

const uint8_t BRIGHTNESS = 255 * 0.3;
const uint8_t LED_STRIP_DATA_PIN = 3;

CRGB leds[NUMBER_OF_LEDS];

void setup() {
	FastLED.addLeds <LED_CONTROLLER, LED_STRIP_DATA_PIN, COLOR_ORDER>(leds, NUMBER_OF_LEDS);
	FastLED.setBrightness(BRIGHTNESS);
	Serial.begin(9600);
}

void loop(){
	//FastLED.clear();
	for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
		leds[i] = CRGB::White;
	}
	FastLED.show();
	
}

