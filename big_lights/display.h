#ifndef DISPLAY_H
#define DISPLAY_H

//#include "alert.h"
//#include "blue.h"
//#include "charging.h"
//#include "cube.h"
//#include "error.h"
//#include "fire.h"
//#include "fire2.h"
//#include "first_logo.h" 
//#include "frown.h"
//#include "matrix.h"
//#include "neutral.h"
//#include "pacman.h"
//#include "pong.h"
//#include "red.h"
//#include "slide.h"
//#include "smile.h"
//#include "space.h"
//#include "star.h"
//#include "surprise.h"
#include "tetris.h"
//#include "tron.h"
//#include "wave.h"
//#include "wheel.h"

struct Display{
	public:
	enum Display_mode{
		HOLD,
		CYCLE,
		RANDOM
	};
	
	enum Design_picker{
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
		CHARGING = 21,//displays a battery charging animation
		DESIGNS = 22 //Used to refer to the number of designs
	};
	
	const unsigned long CYCLE_TIME = 10 * 1000;//ms
	
	private:
	Design* design;
	Display_mode display_mode;
	Design_picker design_picker;

	Countdown_timer cycle_timer;

	public:
	void set_design(const Design_picker);
	void set_display_mode(const Display_mode);
	
	void show(CRGB* leds);

	Display(Design*);
	Display();
};

#endif
