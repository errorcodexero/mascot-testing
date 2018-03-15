#include "design.h"

void Design::update(){
	if(frame_timer.done()){
		current_frame++;
		if(current_frame >= frame_count){
			current_frame = 0;
		}
		frame_timer.reset();
	}
}

void Design::show(CRGB leds[Lights_constants::NUMBER_OF_LEDS]){
	if(current_frame == last_shown_frame){
		return;
	}
	FastLED.clear();
	set_leds(leds);
	FastLED.show();

	last_shown_frame = current_frame;
}

Design::Design(uint8_t count,unsigned len):
	current_frame(0),
	frame_count(count),
	last_shown_frame(-1),
	frame_timer(len)
{}
