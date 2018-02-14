#ifndef LIGHTS_H
#define LIGHTS_H

#include "robot_info.h"
#include "countdown_timer.h"
#include "FastLED.h" // http://fastled.io/docs/3.1/group___colorutils.html

#define LED_CONTROLLER WS2812B
#define COLOR_ORDER GRB

class Lights{
  public:
  enum Mode{
    NEUTRAL = 0;//Neutral face
    SMILE = 1;//Smiling face
    FROWN = 2;//Frowning face
    SPACE = 3;//Space invaders animation
    FIRE = 4;//Flame animation
    BSOD = 5;//BSOD face
    TRON = 6;//Tron animation
    PACMAN = 7;//Pacman animation
    FIRST = 8;//FIRST logo
    SURPRISE = 9;//?! scrolling animation
    SLIDE = 10;//G Slide animation
    PONG = 11;//Pong animation
    ALERT = 12;//Alert animation
    STAR = 13;//Star animation
    BLUE = 14;//Blue alliance animation
    RED = 15;//Red alliance animation
    MATRIX = 16;//Matrix animation
    WHEEL = 17;//Color wheel animation
    TEAM = 1425;//Flames with team number animation
    TETRIS = 19;//Tetris animation
    CUBE = 20;//Rubik's cube animation
  };
  
  static const unsigned NUMBER_OF_LEDS = 192;
  static const unsigned LED_STRIP_DATA_PIN = 7;
  static const byte MAX_BRIGHTNESS = 255;
  static constexpr double LEDS_PER_INCH = 1.3333333;

  private:
  CRGB leds[NUMBER_OF_LEDS];
  int heat[NUMBER_OF_LEDS];
  unsigned mode_index;
  
  //Robot_info last_robot_info;//information about the robot used to inform the lights
  Mode mode;//the display mode
  
  Countdown_timer wait_timer;//used in timing for various modes
  Countdown_timer cycle_timer;//used to swtich between modes at random when the robot isn't doing anything interesting
  
  void shift_leds(const CRGB);

  void color_rainbow_chase();
  void clear();

  public:
  void print_mode()const;
  void println_mode()const;

  void set_leds(const Robot_info&);
  void setup();

  Lights();
};

#endif
