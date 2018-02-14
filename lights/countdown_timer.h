#ifndef COUNTDOWN_TIMER_H
#define COUNTDOWN_TIMER_H

//time in milliseconds

class Countdown_timer{
	private:
	long left;
	unsigned long last_time;
	
	public:
	Countdown_timer();
	void set(const unsigned long);
	void update();
	bool done()const;
};

#endif

#include "Arduino.h"

Countdown_timer::Countdown_timer():left(0),last_time(0){}

void Countdown_timer::set(const unsigned long length){
	left = length;
	last_time = millis();
}

void Countdown_timer::update(){
	long now = millis();
	if(left > 0){
		left -= (now - last_time);
	}
	last_time = now;
}

bool Countdown_timer::done()const{
	return left <= 0;
}
