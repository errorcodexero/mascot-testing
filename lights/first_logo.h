#ifndef FIRST_LOGO_H
#define FIRST_LOGO_H

#include "frame_set.h"

struct First_logo: public Frame_set {
    void set_leds(CRGB leds[Lights_constants::NUMBER_OF_LEDS])const{
        switch(current_frame){
            case 0:
                leds[17] = CRGB{255,0,0};
                leds[33] = CRGB{255,0,0};
                leds[34] = CRGB{255,0,0};
                leds[38] = CRGB{255,255,255};
                leds[39] = CRGB{255,255,255};
                leds[40] = CRGB{255,255,255};
                leds[43] = CRGB{0,0,255};
                leds[44] = CRGB{0,0,255};
                leds[49] = CRGB{255,0,0};
                leds[50] = CRGB{255,0,0};
                leds[51] = CRGB{255,0,0};
                leds[52] = CRGB{255,255,255};
                leds[53] = CRGB{255,255,255};
                leds[54] = CRGB{255,255,255};
                leds[55] = CRGB{255,255,255};
                leds[56] = CRGB{255,255,255};
                leds[57] = CRGB{255,255,255};
                leds[58] = CRGB{0,0,255};
                leds[59] = CRGB{0,0,255};
                leds[60] = CRGB{0,0,255};
                leds[61] = CRGB{0,0,255};
                leds[65] = CRGB{255,0,0};
                leds[66] = CRGB{255,0,0};
                leds[67] = CRGB{255,0,0};
                leds[68] = CRGB{255,0,0};
                leds[69] = CRGB{255,255,255};
                leds[73] = CRGB{0,0,255};
                leds[74] = CRGB{0,0,255};
                leds[75] = CRGB{255,255,255};
                leds[77] = CRGB{0,0,255};
                leds[78] = CRGB{0,0,255};
                leds[80] = CRGB{255,0,0};
                leds[81] = CRGB{255,0,0};
                leds[82] = CRGB{255,0,0};
                leds[83] = CRGB{255,255,255};
                leds[84] = CRGB{255,0,0};
                leds[85] = CRGB{255,0,0};
                leds[88] = CRGB{0,0,255};
                leds[89] = CRGB{0,0,255};
                leds[90] = CRGB{255,255,255};
                leds[91] = CRGB{255,255,255};
                leds[94] = CRGB{0,0,255};
                leds[95] = CRGB{0,0,255};
                leds[96] = CRGB{255,0,0};
                leds[97] = CRGB{255,0,0};
                leds[99] = CRGB{255,255,255};
                leds[100] = CRGB{255,255,255};
                leds[101] = CRGB{255,255,255};
                leds[102] = CRGB{255,0,0};
                leds[104] = CRGB{0,0,255};
                leds[105] = CRGB{255,255,255};
                leds[106] = CRGB{255,255,255};
                leds[107] = CRGB{255,255,255};
                leds[110] = CRGB{0,0,255};
                leds[111] = CRGB{0,0,255};
                leds[112] = CRGB{255,0,0};
                leds[113] = CRGB{255,0,0};
                leds[116] = CRGB{255,255,255};
                leds[117] = CRGB{255,255,255};
                leds[118] = CRGB{255,255,255};
                leds[119] = CRGB{255,255,255};
                leds[120] = CRGB{255,255,255};
                leds[121] = CRGB{255,255,255};
                leds[122] = CRGB{255,255,255};
                leds[125] = CRGB{0,0,255};
                leds[126] = CRGB{0,0,255};
                leds[128] = CRGB{255,0,0};
                leds[129] = CRGB{255,0,0};
                leds[130] = CRGB{255,0,0};
                leds[131] = CRGB{255,0,0};
                leds[132] = CRGB{255,0,0};
                leds[134] = CRGB{255,255,255};
                leds[135] = CRGB{255,255,255};
                leds[136] = CRGB{255,255,255};
                leds[138] = CRGB{0,0,255};
                leds[139] = CRGB{0,0,255};
                leds[140] = CRGB{0,0,255};
                leds[141] = CRGB{0,0,255};
                leds[144] = CRGB{255,0,0};
                leds[145] = CRGB{255,0,0};
                leds[146] = CRGB{255,0,0};
                leds[147] = CRGB{255,0,0};
                leds[155] = CRGB{0,0,255};
                leds[156] = CRGB{0,0,255};
                leds[160] = CRGB{255,0,0};
                leds[161] = CRGB{255,0,0};
                return;
            default:
                Serial.println("NYI");
                assert(0);
        }
    }

    First_logo():Frame_set(1,100){}
};

#endif