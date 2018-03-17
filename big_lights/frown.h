#ifndef FROWN_H
#define FROWN_H

#include "design.h"

struct Frown: public Design {
    void set_leds(CRGB leds[Lights_constants::NUMBER_OF_LEDS])const{
        switch(current_frame){
            case 0:
                leds[21] = CRGB{255,0,0};
                leds[22] = CRGB{255,0,0};
                leds[25] = CRGB{255,0,0};
                leds[26] = CRGB{255,0,0};
                leds[37] = CRGB{255,0,0};
                leds[38] = CRGB{255,0,0};
                leds[41] = CRGB{255,0,0};
                leds[42] = CRGB{255,0,0};
                leds[53] = CRGB{255,0,0};
                leds[54] = CRGB{255,0,0};
                leds[57] = CRGB{255,0,0};
                leds[58] = CRGB{255,0,0};
                leds[69] = CRGB{255,0,0};
                leds[70] = CRGB{255,0,0};
                leds[73] = CRGB{255,0,0};
                leds[74] = CRGB{255,0,0};
                leds[85] = CRGB{255,0,0};
                leds[86] = CRGB{255,0,0};
                leds[89] = CRGB{255,0,0};
                leds[90] = CRGB{255,0,0};
                leds[118] = CRGB{255,0,0};
                leds[119] = CRGB{255,0,0};
                leds[120] = CRGB{255,0,0};
                leds[121] = CRGB{255,0,0};
                leds[132] = CRGB{255,0,0};
                leds[133] = CRGB{255,0,0};
                leds[134] = CRGB{255,0,0};
                leds[135] = CRGB{255,0,0};
                leds[136] = CRGB{255,0,0};
                leds[137] = CRGB{255,0,0};
                leds[138] = CRGB{255,0,0};
                leds[139] = CRGB{255,0,0};
                leds[147] = CRGB{255,0,0};
                leds[148] = CRGB{255,0,0};
                leds[149] = CRGB{255,0,0};
                leds[150] = CRGB{255,0,0};
                leds[151] = CRGB{255,0,0};
                leds[152] = CRGB{255,0,0};
                leds[153] = CRGB{255,0,0};
                leds[154] = CRGB{255,0,0};
                leds[155] = CRGB{255,0,0};
                leds[156] = CRGB{255,0,0};
                leds[163] = CRGB{255,0,0};
                leds[164] = CRGB{255,0,0};
                leds[165] = CRGB{255,0,0};
                leds[166] = CRGB{255,0,0};
                leds[167] = CRGB{255,0,0};
                leds[168] = CRGB{255,0,0};
                leds[169] = CRGB{255,0,0};
                leds[170] = CRGB{255,0,0};
                leds[171] = CRGB{255,0,0};
                leds[172] = CRGB{255,0,0};
                return;
            default:
                Serial.println("NYI");
                assert(0);
        }
    }

    Frown():Design(1,100){}
};

#endif