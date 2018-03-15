#include "display.h"

Display::Display(Design* des):design(des),display_mode(HOLD),design_picker((Design_picker)0){}
Display::Display():Display(new Tetris()){} //TODO: have first design be Surprise?

void Display::set_design(const Design_picker new_design_picker){
	if(design_picker == new_design_picker){
		//If we're setting the design to the current one--don't interrupt it. Let it keep going.
		return;
	}
	
	design_picker = new_design_picker;
	
	delete design;
	switch(design_picker){
		case NEUTRAL:
			//design = new Neutral();
			break;
		case SMILE:
			//design = new Smile();
			break;
		case FROWN:
			//design = new Frown();
			break;
		case SPACE:
			//design = new Space();
			break;
		case FIRE:
			//design = new Fire();
			break;
		case BSOD:
			//design = new Error();
			break;
		case TRON:
			//design = new Tron();
			break;
		case PACMAN:
			//design = new Pacman();
			break;
		case FIRST:
			//design = new First_logo();
			break;
		case SUPRISE:
			//design = new Surprise();
			break;
		case SLIDE:
			//design = new Slide();
			break;
		case PONG:
			//design = new Pong();
			break;
		case ALERT:
			//design = new Alert();
			break;
		case STAR:
			//design = new Star();
			break;
		case BLUE:
			//design = new Blue();
			break;
		case RED:
			//design = new Red();
			break;
		case MATRIX:
			//design = new Matrix();
			break;
		case WHEEL:
			//design = new Wheel();
			break;
		case TEAM:
			//design = new Fire2();
			break;
		case TETRIS:
			//design = new Tetris();
			break;
		case CUBE:
			//design = new Cube();
			break;
		case DESIGNS:
		default:
			Serial.println("NYI");
			assert(0);
	}
}

void Display::set_display_mode(const Display_mode new_display_mode){
	display_mode = new_display_mode;
}

void Display::show(CRGB leds[Lights_constants::NUMBER_OF_LEDS]){
	switch(display_mode){
		case HOLD:
			break;
		case CYCLE:
			if(cycle_timer.done()){
				set_design((Design_picker)(design_picker  + 1));
				if(design_picker >= DESIGNS){
					design_picker  = (Design_picker)0;
				}
				cycle_timer.set(CYCLE_TIME);
			}
			break;
		case RANDOM:
			if(cycle_timer.done()){
				set_design((Design_picker)random(0,DESIGNS));
				cycle_timer.set(CYCLE_TIME);
			}
			break;
		default:
			Serial.println("NYI");
			assert(0);
	}
	
	design -> show(leds);
	design -> update();
}
