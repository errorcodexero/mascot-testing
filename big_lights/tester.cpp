#ifdef TESTING

#include "tester.h"

#include <chrono>
#include <sstream>
#include <fstream>
#include <algorithm>

#include "display.h"

using namespace std;

const std::string Display_parser::RESULT_FILE = "result.txt";

CRGB::CRGB(unsigned r,unsigned g,unsigned b):red(r),green(g),blue(b){}
CRGB::CRGB():CRGB(0,0,0){}

ostream& operator<<(ostream& o,const CRGB a){
	o<<"CRGB(";
	o<<a.red;
	o<<",";
	o<<a.green;
	o<<",";
	o<<a.blue;
	o<<")";
	return o;
}

string dec_to_hexidec(unsigned a){
	stringstream ss;
	ss<<hex<<a;
	string s = ss.str();
	if(s.length() == 1){
		return "0" + s;
	}
	return s;
}

ostream& CRGB::ostream_hexidecimal(ostream& o,const CRGB a){
	if(CRGB::MAKE_BLACK_VISIBLE){
		if(a.red ==0 && a.green == 0 && a.blue == 0){
			o<<"[\"11\",\"11\",\"11\"]";
			return o;
		}
	}
	o<<"[";
	o<<"\""<<dec_to_hexidec(a.red)<<"\",";
	o<<"\""<<dec_to_hexidec(a.green)<<"\",";
	o<<"\""<<dec_to_hexidec(a.blue)<<"\"";
	o<<"]";
	return o;
}

bool operator==(const CRGB a,const CRGB b){
	return a.red == b.red &&
		a.green == b.green && 
		a.blue == b.blue;
}

bool operator!=(const CRGB a,const CRGB b){
	return !(a==b);
}

bool operator<(const CRGB a,const CRGB b){
	if(a.red < b.red) return true;
	if(b.red < a.red) return false;
	if(a.green < b.green) return true;
	if(b.green < a.green) return false;
	if(a.blue < b.blue) return true;
	if(b.blue < a.blue) return false;
	return false;
}

void Serial_c::println(string s)const{
	if(!Serial_c::ENABLE){
		return;
	}
	cout<<s<<endl;
}

void Serial_c::println(unsigned a)const{
	if(!Serial_c::ENABLE){
		return;
	}
	cout<<a<<endl;
}

int random(int min,int max){
	srand(time(NULL));
	int r = rand() % max + min;
	return r;
}

unsigned long millis(){
	return (unsigned long int)(std::chrono::duration_cast<std::chrono::milliseconds>((std::chrono::time_point_cast<std::chrono::milliseconds>(std::chrono::system_clock::now())).time_since_epoch())).count();
}

array<array<CRGB,Display_parser::MATRIX_WIDTH>, Display_parser::MATRIX_HEIGHT> Display_parser::format_ptr_array(CRGB leds[Lights_constants::NUMBER_OF_LEDS]){
	unsigned i = 0;
	array<array<CRGB,Display_parser::MATRIX_WIDTH>, MATRIX_HEIGHT> formatted;
	for(array<CRGB, Display_parser::MATRIX_WIDTH>& row: formatted){
		for(CRGB& led: row){
			led = leds[i];
			i++;
		}
	}
	return formatted;
}

vector<array<array<CRGB,Display_parser::MATRIX_WIDTH>, Display_parser::MATRIX_HEIGHT>> Display_parser::collect_frames(Design* design){
	vector<array<array<CRGB,Display_parser::MATRIX_WIDTH>, Display_parser::MATRIX_HEIGHT>> frames;
	Display display = design;
	CRGB leds[Lights_constants::NUMBER_OF_LEDS];
	
	for(unsigned i = 0; i < Lights_constants::NUMBER_OF_LEDS; i++){
		leds[i] = CRGB(0,0,0);
	}

	Countdown_timer timeout_timer = {Display_parser::TIMEOUT};
	
	while(!timeout_timer.done()){
		display.show(leds);
		array<array<CRGB,Display_parser::MATRIX_WIDTH>, Display_parser::MATRIX_HEIGHT>new_frame = format_ptr_array(leds);
		if(find(frames.begin(), frames.end(), new_frame) == frames.end()){
			frames.push_back(new_frame);
		}
		
		Countdown_timer pause = {Display_parser::MIN_FRAME_LENGTH};
		while(!pause.done());
	}
	
	return frames;
};

void Display_parser::parse(Design* design){
	vector<array<array<CRGB,Display_parser::MATRIX_WIDTH>, Display_parser::MATRIX_HEIGHT>> frames = collect_frames(design);
	
	ofstream target_file(Display_parser::RESULT_FILE ,ofstream::out);
	
	target_file<<"[\n";

	for(unsigned i = 0; i < frames.size(); i++){
		array<array<CRGB,MATRIX_WIDTH>, MATRIX_HEIGHT> frame = frames[i];
		target_file<<"    [\n";
		for(unsigned row = 0; row < MATRIX_HEIGHT; row++){
			target_file<<"        [";
			for(unsigned i = 0; i < MATRIX_WIDTH; i ++){
				CRGB::ostream_hexidecimal(target_file,frame[row][i]);
				if(i != MATRIX_WIDTH - 1){
					target_file<<", ";
				}
			}
			target_file<<"]";
			if(row != MATRIX_HEIGHT - 1){
				target_file<<",\n";
			}
		}
		target_file<<"\n    ]";
		if(i < frames.size()){
			target_file<<",";
		}
		target_file<<"\n";
	}

	target_file<<"]";
	target_file.close();
	
	delete design;
	
	cout<<"\nFinished parsing. Parsed "<<frames.size()<<" unique frames over "<<Display_parser::TIMEOUT<<" ms."<<endl;
}

int main(){
	Display_parser::parse(new Fire2());
	return 0;
}

#endif
