#ifndef PONG_H
#define PONG_H

#include "frame_set.h"

struct Pong: public Frame_set {
    void set_leds(CRGB leds[Lights_constants::NUMBER_OF_LEDS])const{
        switch(current_frame){
            case 0:
                leds[32] = CRGB{255,255,255};
                leds[48] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[86] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 1:
                leds[32] = CRGB{255,255,255};
                leds[48] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[103] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 2:
                leds[48] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[120] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                return;
            case 3:
                leds[48] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[137] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                return;
            case 4:
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                leds[154] = CRGB{255,255,255};
                leds[159] = CRGB{255,255,255};
                return;
            case 5:
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                leds[159] = CRGB{255,255,255};
                leds[171] = CRGB{255,255,255};
                return;
            case 6:
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                leds[159] = CRGB{255,255,255};
                leds[175] = CRGB{255,255,255};
                leds[188] = CRGB{255,255,255};
                return;
            case 7:
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                leds[159] = CRGB{255,255,255};
                leds[173] = CRGB{255,255,255};
                leds[175] = CRGB{255,255,255};
                return;
            case 8:
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                leds[158] = CRGB{255,255,255};
                leds[159] = CRGB{255,255,255};
                leds[175] = CRGB{255,255,255};
                return;
            case 9:
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[141] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                leds[159] = CRGB{255,255,255};
                leds[175] = CRGB{255,255,255};
                return;
            case 10:
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[124] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                leds[159] = CRGB{255,255,255};
                return;
            case 11:
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[107] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                leds[159] = CRGB{255,255,255};
                return;
            case 12:
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[90] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                return;
            case 13:
                leds[64] = CRGB{255,255,255};
                leds[73] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                return;
            case 14:
                leds[48] = CRGB{255,255,255};
                leds[56] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 15:
                leds[39] = CRGB{255,255,255};
                leds[48] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 16:
                leds[22] = CRGB{255,255,255};
                leds[32] = CRGB{255,255,255};
                leds[48] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 17:
                leds[5] = CRGB{255,255,255};
                leds[32] = CRGB{255,255,255};
                leds[48] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 18:
                leds[20] = CRGB{255,255,255};
                leds[32] = CRGB{255,255,255};
                leds[48] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 19:
                leds[32] = CRGB{255,255,255};
                leds[35] = CRGB{255,255,255};
                leds[48] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 20:
                leds[48] = CRGB{255,255,255};
                leds[50] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 21:
                leds[48] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[65] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 22:
                leds[48] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[82] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 23:
                leds[48] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[99] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 24:
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[116] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 25:
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[133] = CRGB{255,255,255};
                return;
            case 26:
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                leds[150] = CRGB{255,255,255};
                return;
            case 27:
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                leds[167] = CRGB{255,255,255};
                return;
            case 28:
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                leds[159] = CRGB{255,255,255};
                leds[184] = CRGB{255,255,255};
                return;
            case 29:
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                leds[159] = CRGB{255,255,255};
                leds[169] = CRGB{255,255,255};
                return;
            case 30:
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                leds[154] = CRGB{255,255,255};
                return;
            case 31:
                leds[64] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                leds[139] = CRGB{255,255,255};
                leds[143] = CRGB{255,255,255};
                return;
            case 32:
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[124] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 33:
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[109] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 34:
                leds[63] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[94] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                return;
            case 35:
                leds[63] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[77] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                return;
            case 36:
                leds[60] = CRGB{255,255,255};
                leds[63] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                return;
            case 37:
                leds[43] = CRGB{255,255,255};
                leds[63] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                return;
            case 38:
                leds[26] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 39:
                leds[9] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            case 40:
                leds[24] = CRGB{255,255,255};
                leds[64] = CRGB{255,255,255};
                leds[79] = CRGB{255,255,255};
                leds[80] = CRGB{255,255,255};
                leds[95] = CRGB{255,255,255};
                leds[96] = CRGB{255,255,255};
                leds[111] = CRGB{255,255,255};
                leds[112] = CRGB{255,255,255};
                leds[127] = CRGB{255,255,255};
                return;
            default:
                Serial.println("NYI");
                assert(0);
        }
    }

    Pong():Frame_set(41,200){}
};

#endif
