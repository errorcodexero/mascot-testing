#ifndef FRAME_SET_H
#define FRAME_SET_H

#include "FastLED.h" // http://fastled.io/docs/3.1/group___colorutils.html
#include "assert.h"
#include "lights_constants.h"

struct Frame_set{
	protected:
	uint8_t current_frame;
	uint8_t frame_count;

	public:
	void advance(){
		current_frame++;
		if(current_frame >= frame_count){
			current_frame = 0;
		}
	}

	virtual void set_leds(CRGB*)const = 0;

	Frame_set(uint8_t len):current_frame(0),frame_count(len){}

	virtual ~Frame_set(){}
};

#endif
