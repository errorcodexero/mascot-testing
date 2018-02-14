#include "lights.h"
#include <assert.h>

Lights::Lights():mode_index(random(LIFTER_HEIGHT, OFF)),mode(RECENTLY_ENABLED),wait_timer(),cycle_timer(){
  assert(NUMBER_OF_LEDS > 0);
  for(int& h: heat){
    h = 0;
  }
}

void Lights::setup(){
  FastLED.addLeds<LED_CONTROLLER,LED_STRIP_DATA_PIN, COLOR_ORDER>(leds, NUMBER_OF_LEDS);
  FastLED.setBrightness(MAX_BRIGHTNESS);
  clear();
  randomSeed(millis());
}

void Lights::clear(){
  FastLED.clear();
}

void Lights::println_mode()const{
  print_mode();
  Serial.print("\n");
}

void Lights::print_mode()const{
  switch(mode){
    case NEUTRAL:
      Serial.print("NEUTRAL");
      break;
    case SMILE:
      Serial.print("SMILE");
      break;
    case FROWN:
      Serial.print("FROWN");
      break;
    case SPACE:
      Serial.print("SPACE");
      break;
    case FIRE:
      Serial.print("FIRE");
      break;
    case BSOD:
      Serial.print("BSOD");
      break;
    case TRON:
      Serial.print("TRON");
      break;
    case PACMAN:
      Serial.print("PACMAN");
      break;
    case FIRST:
      Serial.print("FIRST");
      break;
    case SUPRISE:
      Serial.print("SURPRISE");
      break;
    case SLIDE:
      Serial.print("SLIDE");
      break;
    case PONG:
      Serial.print("PONG");
      break;
    case ALERT:
      Serial.print("ALERT");
      break;
    case STAR:
      Serial.print("STAR");
      break;
    case BLUE:
      Serial.print("BLUE");
      break;
    case RED:
      Serial.print("RED");
      break;
    case MATRIX:
      Serial.print("MATRIX");
      break;
    case WHEEL:
      Serial.print("WHEEL");
      break;
    case TEAM:
      Serial.print("TEAM");
      break;
    case TETRIS:
      Serial.print("TETRIS");
      break;
    case CUBE:
      Serial.print("CUBE");
      break;
    default:
      Serial.print("ERROR:LIGHTS MODE DOES NOT EXIST");
  }
}

void Lights::shift_leds(const CRGB NEW_LED){
  CRGB last_leds[NUMBER_OF_LEDS];
  for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
    last_leds[i] = leds[i];
  }
  for(unsigned i = 0; i < NUMBER_OF_LEDS; i++){
    leds[i] = ((int)i - 1 >= 0) ? last_leds[i - 1] : NEW_LED;
  }
}

/*void Lights::color_rainbow_chase(){
  const double UPDATE_DELAY = .1;//slows the color chaning by this percent

  unsigned hue = [&]{
    int remainder = (int)(millis() * UPDATE_DELAY) % 512;
    if(remainder < 256){
      return remainder ;
    } 
    return 512 - remainder ;
  }();
  const unsigned HUE_DELTA = 5;
  fill_rainbow(leds,NUMBER_OF_LEDS,hue,HUE_DELTA);
}*/

void Lights::color_neutral(){
}

void Lights::color_smile(){
}

void Lights::color_frown(){
}

void Lights::color_space(){
}

void Lights::color_fire(){
}

void Lights::color_bsod(){
}

void Lights::color_tron(){
}

void Lights::color_pacman(){
}

void Lights::color_first(){
}

void Lights::color_surprise(){
}

void Lights::color_slide(){
}

void Lights::color_pong(){
}

void Lights::color_alert(){
}

void Lights::color_star(){
}

void Lights::color_blue(){
}

void Lights::color_red(){
}

void Lights::color_matrix(){
}

void Lights::color_wheel(){
}

void Lights::color_team(){
}

void Lights::color_tetris(){
}

void Lights::color_cube(){
}

void Lights::set_leds(const Robot_info& ROBOT_INFO){
  const long CYCLE_TIME = 10000;
  wait_timer.update();
  cycle_timer.update();

  Mode last_mode = mode;
  mode = [&]{//pick mode to display
    if((last_mode == RECENTLY_ENABLED && !wait_timer.done()) || (ROBOT_INFO.enabled && !last_robot_info.enabled)){
      return RECENTLY_ENABLED;
    }
    if(ROBOT_INFO.climbing){
      //TODO
    }
    if(ROBOT_INFO.autonomous){
      //TODO
    }
    if(cycle_timer.done() ||
      (last_mode == RECENTLY_ENABLED && wait_timer.done())
    ){
      mode_index++;
      if(mode_index >= OFF){
        mode_index = LIFTER_HEIGHT;
      }
      return (Lights::Mode)mode_index;
    }
    return last_mode;
  }();

  println_mode();

  if(last_mode != mode){
    clear();
    wait_timer.set(0);
    cycle_timer.set(CYCLE_TIME);
  }

  switch(mode){
    case NEUTRAL:
      color_neutral();
      break;
    case SMILE:
      color_smile();
      break;
    case FROWN:
      color_frown();
      break;
    case SPACE:
      color_space();
      break;
    case FIRE:
      color_fire();
      break;
    case BSOD:
      color_bsod();
      break;
    case TRON:
      color_tron();
      break;
    case PACMAN:
      color_pacman();
      break;
    case FIRST:
      color_first();
      break;
    case SURPRISE:
      color_surprise();
      break;
    case SLIDE:
      color_slide();
      break;
    case PONG:
      color_pong();
      break;
    case ALERT:
      color_alert();
      break;
    case STAR:
      color_star();
      break;
    case BLUE:
      color_blue();
      break;
    case RED:
      color_red();
      break;
    case MATRIX:
      color_matrix();
      break;
    case WHEEL:
      color_wheel();
      break;
    case TEAM:
      color_team();
      break;
    case TETRIS:
      color_tetris();
      break;
    case CUBE:
      color_cube();
      break;
    default:
      assert(0);
  }

  FastLED.show();
  
  last_robot_info = ROBOT_INFO;
}
