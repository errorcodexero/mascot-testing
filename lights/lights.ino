#include "countdown_timer.h"

#include "blue.h"
#include "first_logo.h" 
#include "red.h"
#include "slide.h"
#include "wave.h"
#include "wheel.h"

enum Design{
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
	TEAM = 18,//Flames with team number animation
	TETRIS = 19,//Tetris animation
	CUBE = 20,//Rubik's cube animation
	DESIGNS = 21 //Used to refer to the number of designs
};
Design design;

enum Display_mode{
	HOLD,
	CYCLE,
	RANDOM
};

Display_mode display_mode;

CRGB leds[Lights_constants::NUMBER_OF_LEDS];
Frame_set* frame_set = new First_logo(); //TODO: have first design be Surprise?
Countdown_timer cycle_timer;
const unsigned long CYCLE_TIME = 10 * 1000;//ms

void set_frame_set(){
	delete frame_set;
	switch(design){
		case NEUTRAL:
			return;
		case SMILE:
			return;
		case FROWN:
			return;
		case SPACE:
			return;
		case FIRE:
			return;
		case BSOD:
			return;
		case TRON:
			return;
		case PACMAN:
			return;
		case FIRST:
			frame_set = new First_logo();
			return;
		case SUPRISE:
			return;
		case SLIDE:
			frame_set = new Slide();
			return;
		case PONG:
			return;
		case ALERT:
			return;
		case STAR:
			return;
		case BLUE:
			frame_set = new Blue();
			return;
		case RED:
			frame_set = new Red();
			return;
		case MATRIX:
			return;
		case WHEEL:
			frame_set = new Wheel();
			return;
		case TEAM:
			return;
		case TETRIS:
			return;
		case CUBE:
			return;
		case DESIGNS:
		default:
			Serial.println("NYI");
			assert(0);
	}
}

void setup() {
	FastLED.addLeds <LED_CONTROLLER, Lights_constants::LED_STRIP_DATA_PIN, COLOR_ORDER>(leds, Lights_constants::NUMBER_OF_LEDS);
	Serial.begin(9600);
}

void loop(){
	switch(display_mode){
		case HOLD:
			break;
		case CYCLE:
			if(cycle_timer.done()){
				design = (Design)(design  + 1);
				if(design >= DESIGNS){
					design  = (Design)0;
				}
				set_frame_set();
				cycle_timer.set(CYCLE_TIME);
			}
			break;
		case RANDOM:
			if(cycle_timer.done()){
				design  = (Design)random(0,DESIGNS);
				set_frame_set();
				cycle_timer.set(CYCLE_TIME);
			}
			break;
		default:
			Serial.println("NYI");
			assert(0);
	}
	
	frame_set -> set_leds(leds);
	frame_set -> advance();
	FastLED.show();
	delay(Lights_constants::FRAME_LENGTH);
}

