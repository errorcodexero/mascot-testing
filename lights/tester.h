#ifdef TESTING
#ifndef TESTER_H
#define TESTER_H

#include <iostream>
#include <vector>
#include <set>
#include <array>

struct CRGB{
	static const bool MAKE_BLACK_VISIBLE = false;
	
	unsigned red;
	unsigned green; 
	unsigned blue;

	static std::ostream& ostream_hexidecimal(std::ostream&,const CRGB);

	CRGB();
	CRGB(unsigned,unsigned,unsigned);
};

std::ostream& operator<<(std::ostream&,const CRGB);
bool operator==(const CRGB,const CRGB);
bool operator!=(const CRGB,const CRGB);
bool operator<(const CRGB,const CRGB);

struct Serial_c{
	static const bool ENABLE = true;
	
	void println(std::string)const;
	void println(unsigned)const;
};

static const Serial_c Serial;
int random(int,int);
unsigned long millis();

class Design;

struct Display_parser{
	static const unsigned MATRIX_HEIGHT = 12;
	static const unsigned MATRIX_WIDTH = 16;
	
	static const unsigned long MIN_FRAME_LENGTH = 5;//ms
	static const unsigned TIMEOUT = 20 * 1000;//ms
	
	static const std::string RESULT_FILE;
	
	private:
	static std::array<std::array<CRGB,MATRIX_WIDTH>, MATRIX_HEIGHT> format_ptr_array(CRGB*);
	static std::vector<std::array<std::array<CRGB,MATRIX_WIDTH>, MATRIX_HEIGHT>> collect_frames(Design*);
	
	public:
	static void parse(Design*);
};

#endif
#endif
