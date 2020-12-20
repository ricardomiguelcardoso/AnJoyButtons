/////////////////////////////////////////////////////////////////
/*
Arduino Library to make analog or thumb Joysticks working as buttons.
Use callback functions to track press, release and hold actions for Up, Down, Left and Right movements on Analog or Thumb Joysticks.
Tested with Arduino UNO.
Created by rmsk13, December 15, 2020.
*/
/////////////////////////////////////////////////////////////////

#include "Arduino.h"
#include "AnJoyButtons.h"

/////////////////////////////////////////////////////////////////

AnJoyButtons::AnJoyButtons(byte attachTo, long intervalBefore, long intervalAfter, int offValue, int _maxValue, int _minValue)
{
  pin = attachTo;
  an_state_value = offValue;
  holdIntervalBefore = intervalBefore;
  holdIntervalAfter = intervalAfter;
  maxValue = _maxValue;
  minValue = _minValue;
}

/////////////////////////////////////////////////////////////////

void AnJoyButtons::setUpHandler(CallbackFunction f)
{
  upSide_cb = f;
}

void AnJoyButtons::setUpHoldHandler(CallbackFunction f)
{
  upSideHold_cb = f;
}

void AnJoyButtons::setUpReleaseHandler(CallbackFunction f)
{
  upSideRelease_cb = f;
}

/////////////////////////////////////////////////////////////////

void AnJoyButtons::setDownHandler(CallbackFunction f)
{
  downSide_cb = f;
}

void AnJoyButtons::setDownHoldHandler(CallbackFunction f)
{
  downSideHold_cb = f;
}

void AnJoyButtons::setDownReleaseHandler(CallbackFunction f)
{
  downSideRelease_cb = f;
}

/////////////////////////////////////////////////////////////////

void AnJoyButtons::loop()
{
  int sensorValue = analogRead(pin);

  an_state_value = 0.9 * an_state_value + 0.1 * sensorValue;

  if (an_state_value > minValue && an_state_value < maxValue)
  {
    if (an_state == true)
    {
      if (prevStateUp == false)
      {
        if (upSideRelease_cb != NULL)
          upSideRelease_cb(*this);
      }
      if (prevStateDown == false)
      {
        if (downSideRelease_cb != NULL)
          downSideRelease_cb(*this);
      }
    }
    an_state = false;
    prevStateUp = true;
    prevStateDown = true;
    return;
  }
  if (an_state == false)
  {
    if (an_state_value > maxValue)
    {
      an_state = true;
      prevStateUp = false;
      previousMillsHold = millis();
      holdInterval = holdIntervalBefore;
      if (upSide_cb != NULL)
        upSide_cb(*this);
      return;
    }
    if (an_state_value < minValue)
    {
      an_state = true;
      prevStateDown = false;
      previousMillsHold = millis();
      holdInterval = holdIntervalBefore;
      if (downSide_cb != NULL)
        downSide_cb(*this);
      return;
    }
  }
  else
  {
    unsigned long currentMillis = millis();
    if (an_state == true && prevStateUp == false)
    {
      if (currentMillis - previousMillsHold >= holdInterval)
      {
        previousMillsHold = currentMillis;
        holdInterval = holdIntervalAfter;
        if (upSideHold_cb != NULL)
          upSideHold_cb(*this);
      }
    }
    else if (an_state == true && prevStateDown == false)
    {
      if (currentMillis - previousMillsHold >= holdInterval)
      {
        previousMillsHold = currentMillis;
        holdInterval = holdIntervalAfter;
        if (downSideHold_cb != NULL)
          downSideHold_cb(*this);
      }
    }
  }
}

/////////////////////////////////////////////////////////////////
