#include "countdown_timer.h"
#include "display.h"

Display display = {new Tetris()};
CRGB leds[Lights_constants::NUMBER_OF_LEDS];

void setup() {
	FastLED.addLeds <LED_CONTROLLER, Lights_constants::LED_STRIP_DATA_PIN, COLOR_ORDER>(leds, Lights_constants::NUMBER_OF_LEDS);
	FastLED.setBrightness(Lights_constants::MAX_BRIGHTNESS);
	Serial.begin(9600);
}

void loop(){
	display.show(leds);
}

