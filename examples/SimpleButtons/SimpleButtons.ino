#include <AnJoyButtons.h>

//Declare buttons on analog pins
AnJoyButtons anUpDown = AnJoyButtons(A0);
AnJoyButtons anLeftRight = AnJoyButtons(A1);

//Counters
int upDownCount = 0;
int leftRightCount = 0;

void setup()
{
  Serial.begin(115200);

  //Up Down
  anUpDown.setUpHandler(upHandler);     //Define pressed button handler for UP
  anUpDown.setDownHandler(downHandler); //Define pressed handler for DOWN

  //Left Right
  anLeftRight.setUpHandler(rightHandler);  //Define pressed button handler for RIGHT
  anLeftRight.setDownHandler(leftHandler); //Define pressed button handler for LEFT
}

void loop()
{
  //Run loop to check for changes
  anUpDown.loop();
  anLeftRight.loop();
}

void upHandler()
{
  upDownCount++;
  Serial.print("upDownCount: ");
  Serial.println(upDownCount);
}

void downHandler()
{
  upDownCount--;
  Serial.print("upDownCount: ");
  Serial.println(upDownCount);
}

void leftHandler()
{
  leftRightCount--;
  Serial.print("leftRightCount: ");
  Serial.println(leftRightCount);
}

void rightHandler()
{
  leftRightCount++;
  Serial.print("leftRightCount: ");
  Serial.println(leftRightCount);
}
