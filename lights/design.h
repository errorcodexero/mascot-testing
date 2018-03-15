#ifndef DESIGN_H
#define DESIGN_H

#include "FastLED.h" // http://fastled.io/docs/3.1/group___colorutils.html
#include "assert.h"
#include "lights_constants.h"
#include "countdown_timer.h"

struct Design{
	protected:
	uint8_t current_frame;
	uint8_t frame_count;
	uint8_t last_shown_frame;

	Countdown_timer frame_timer;//ms

	virtual void set_leds(CRGB*)const = 0;

	public:
	void update();//TODO: merge this with Design::show(CRGB*) ?

	void show(CRGB*);

	Design(uint8_t count,unsigned len);

	virtual ~Design(){}
};

#endif
