#ifndef FRAME_SET_H
#define FRAME_SET_H

#include "FastLED.h" // http://fastled.io/docs/3.1/group___colorutils.html
#include "assert.h"
#include "lights_constants.h"
#include "countdown_timer.h"

struct Frame_set{
	protected:
	uint8_t current_frame;
	uint8_t frame_count;
	Countdown_timer frame_timer;//ms

	public:
	void advance(){
		if(frame_timer.done()){
			current_frame++;
			if(current_frame >= frame_count){
				current_frame = 0;
			}
			frame_timer.reset();
			FastLED.clear();//TODO: move this?
		}
	}

	virtual void set_leds(CRGB*)const = 0;

	Frame_set(uint8_t count,unsigned len):current_frame(0),frame_count(count),frame_timer(len){}

	virtual ~Frame_set(){}
};

#endif
