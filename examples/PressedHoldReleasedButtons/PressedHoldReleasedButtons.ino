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
  anUpDown.setUpHandler(upHandler);               //Define pressed button handler for UP
  anUpDown.setUpHoldHandler(upHoldHandler);       //Define hold button handler for UP
  anUpDown.setUpReleaseHandler(upReleaseHandler); //Define released button handler for UP

  anUpDown.setDownHandler(downHandler);               //Define pressed button handler for UP
  anUpDown.setDownHoldHandler(downHoldHandler);       //Define hold button handler for UP
  anUpDown.setDownReleaseHandler(downReleaseHandler); //Define released button handler for UP

  //Left Right
  anLeftRight.setUpHandler(rightHandler);               //Define pressed button handler for RIGHT
  anLeftRight.setUpHoldHandler(rightHoldHandler);       //Define hold button handler for RIGHT
  anLeftRight.setUpReleaseHandler(rightReleaseHandler); //Define released button handler for RIGHT

  anLeftRight.setDownHandler(leftHandler);               //Define pressed button handler for LEFT
  anLeftRight.setDownHoldHandler(leftHoldHandler);       //Define hold button handler for LEFT
  anLeftRight.setDownReleaseHandler(leftReleaseHandler); //Define released button handler for LEFT
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
  Serial.print("UP pressed: ");
  Serial.println(upDownCount);
}

void upHoldHandler()
{
  upDownCount++;
  Serial.print("UP hold: ");
  Serial.println(upDownCount);
}

void upReleaseHandler()
{
  Serial.println("UP released.");
}

void downHandler()
{
  upDownCount--;
  Serial.print("DOWN pressed: ");
  Serial.println(upDownCount);
}

void downHoldHandler()
{
  upDownCount--;
  Serial.print("DOWN hold: ");
  Serial.println(upDownCount);
}

void downReleaseHandler()
{
  Serial.println("DOWN released.");
}

void leftHandler()
{
  leftRightCount--;
  Serial.print("LEFT pressed: ");
  Serial.println(leftRightCount);
}

void leftHoldHandler()
{
  leftRightCount--;
  Serial.print("LEFT hold: ");
  Serial.println(leftRightCount);
}

void leftReleaseHandler()
{
  Serial.println("LEFT released.");
}

void rightHandler()
{
  leftRightCount++;
  Serial.print("RIGHT pressed: ");
  Serial.println(leftRightCount);
}

void rightHoldHandler()
{
  leftRightCount++;
  Serial.print("RIGHT hold: ");
  Serial.println(leftRightCount);
}

void rightReleaseHandler()
{
  Serial.println("RIGHT released.");
}
