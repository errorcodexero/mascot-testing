#include "countdown_timer.h"

#include "Arduino.h"

Countdown_timer::Countdown_timer(const unsigned long LENGTH):length(LENGTH),finish_time(millis() + LENGTH){}
Countdown_timer::Countdown_timer():Countdown_timer(0){}

void Countdown_timer::set(const unsigned long len){
	finish_time = millis() + len;
}

void Countdown_timer::reset(){
	set(length);
}

bool Countdown_timer::done()const{
	return millis() >= finish_time;
}
