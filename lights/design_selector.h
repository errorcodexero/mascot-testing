#ifndef DESIGN_SELECTOR_H
#define DESIGN_SELECTOR_H

#include "Arduino.h"
#include "SevSeg.h"

uint8_t get_design_selection();
uint16_t get_scaled_design_selection();
void set_seven_segment_display(const uint16_t,SevSeg&);
void set_seven_segment_display(char*,SevSeg&);

#endif
