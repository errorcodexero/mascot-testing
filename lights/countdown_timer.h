#ifndef COUNTDOWN_TIMER_H
#define COUNTDOWN_TIMER_H

//time in milliseconds

class Countdown_timer{
	private:
	unsigned long length;
	unsigned long finish_time;
	
	public:
	Countdown_timer();
	Countdown_timer(const unsigned long);
	void set(const unsigned long);
	void reset();
	bool done()const;
};

#endif
