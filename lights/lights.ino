#include "lights_constants.h"

#include "first_logo.h" 

enum Mode{
    NEUTRAL = 0,//Neutral face
    SMILE = 1,//Smiling face
    FROWN = 2,//Frowning face
    SPACE = 3,//Space invaders animation
    FIRE = 4,//Flame animation
    BSOD = 5,//BSOD face
    TRON = 6,//Tron animation
    PACMAN = 7,//Pacman animation
    FIRST = 8,//FIRST logo
    SUPRISE = 9,//?! scrolling animation
    SLIDE = 10,//G Slide animation
    PONG = 11,//Pong animation
    ALERT = 12,//Alert animation
    STAR = 13,//Star animation
    BLUE = 14,//Blue alliance animation
    RED = 15,//Red alliance animation
    MATRIX = 16,//Matrix animation
    WHEEL = 17,//Color wheel animation
    TEAM = 1425,//Flames with team number animation
    TETRIS = 19,//Tetris animation
    CUBE = 20//Rubik's cube animation
};

unsigned mode_index; 
Mode mode;

CRGB leds[Lights_constants::NUMBER_OF_LEDS];

Frame_set* frame_set = new First_logo();

void setup() {
	FastLED.addLeds <LED_CONTROLLER, Lights_constants::LED_STRIP_DATA_PIN, COLOR_ORDER>(leds, Lights_constants::NUMBER_OF_LEDS);
	Serial.begin(9600);
}

void loop(){
	delay(Lights_constants::FRAME_LENGTH);
	frame_set -> set_leds(leds);
	frame_set -> advance();
	FastLED.show();
}

