/////////////////////////////////////////////////////////////////
/*
Arduino Library to make analog or thumb Joysticks working as buttons.
Use callback functions to track press, release and hold actions for Up, Down, Left and Right movements on Analog or Thumb Joysticks.
Tested with Arduino UNO.
Created by rmsk13, December 15, 2020.
*/
/////////////////////////////////////////////////////////////////
#pragma once

#ifndef AnJoyButtonss_h
#define AnJoyButtonss_h

/////////////////////////////////////////////////////////////////

#include "Arduino.h"

/////////////////////////////////////////////////////////////////

#define MAX_VALUE 973
#define MIN_VALUE 50
#define OFF_VALUE 512
#define INTERVAL_BEFORE 1000
#define INTERVAL_AFTER 500

/////////////////////////////////////////////////////////////////

class AnJoyButtons
{
private:
  byte pin;
  bool an_state = false;
  bool prevStateUp = true;
  bool prevStateDown = true;
  int an_state_value = OFF_VALUE;
  long holdIntervalBefore = INTERVAL_BEFORE;
  long holdInterval = INTERVAL_BEFORE;
  long holdIntervalAfter = INTERVAL_AFTER;
  long previousMillsHold = 0;
  int maxValue = MAX_VALUE;
  int minValue = MIN_VALUE;
  int offValue = OFF_VALUE;

  typedef void (*CallbackFunction)(AnJoyButtons &);

  CallbackFunction upSide_cb = NULL;
  CallbackFunction upSideHold_cb = NULL;
  CallbackFunction upSideRelease_cb = NULL;

  CallbackFunction downSide_cb = NULL;
  CallbackFunction downSideHold_cb = NULL;
  CallbackFunction downSideRelease_cb = NULL;

public:
  AnJoyButtons(byte attachTo, long intervalBefore = INTERVAL_BEFORE, long intervalAfter = INTERVAL_AFTER, int offValue = OFF_VALUE, int maxValue = MAX_VALUE, int minValue = MIN_VALUE);
  void setUpHandler(CallbackFunction f);
  void setUpHoldHandler(CallbackFunction f);
  void setUpReleaseHandler(CallbackFunction f);
  void setDownHandler(CallbackFunction f);
  void setDownHoldHandler(CallbackFunction f);
  void setDownReleaseHandler(CallbackFunction f);

  void loop();
};
/////////////////////////////////////////////////////////////////
#endif
/////////////////////////////////////////////////////////////////
