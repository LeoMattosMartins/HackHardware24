#include "Wire.h"

#include <JoystickShield.h> //JoystickShield Library

JoystickShield joystickShield; //Create an instance of JoystickShield object


void setup() 
{
  Serial.begin(9600);
  delay(100);

  // New calibration function

  joystickShield.calibrateJoystick();
  

  // Predefined Joystick to Pins 0 and 1.
  // Change it if you are using a different joystick shield
  // SetJoystickPins(0, 1);
  // Predefined buttons to the following pins.
  // Change it if you’re using a different joystick shield.
  // setButtonPins(pinJoystickButton, pinUp, pinRight, pinDown, pinLeft,pinF, pinE); // K,A,B,C,D,F,E
  // To deactivate a button, use a pin outside of the range of the Arduino e.g. 255, but not the above!
  // setButtonPins(8, 2, 3, 4, 5, 7, 6);
}

void loop() 
{
  joystickShield.processEvents(); // Process events

  if (joystickShield.isUp()) { Serial.println("Up"); }

  if (joystickShield.isRightUp()) { Serial.println("RightUp"); }

  if (joystickShield.isRight()) { Serial.println("Right"); }

  if (joystickShield.isRightDown()) { Serial.println("RightDown"); }

  if (joystickShield.isDown()) { Serial.println("Down"); }

  if (joystickShield.isLeftDown()) { Serial.println("LeftDown"); }

  if (joystickShield.isLeft()) { Serial.println("Left"); }

  if (joystickShield.isLeftUp()) { Serial.println("LeftUp"); }

  // button clicks 
  if (joystickShield.isJoystickButton()) 
  { 
    Serial.println("Joystick Clicked"); 
    //Keyboard.write(' ');
  }

  if (joystickShield.isUpButton()) 
  { 
    Serial.println("Up Button Clicked"); 
    //Keyboard.write('w');
  }

  if (joystickShield.isRightButton())
  { 
    Serial.println("Right Button Clicked");
    //Keyboard.write('d');
  }

  if (joystickShield.isDownButton()) 
  { 
    Serial.println("Down Button Clicked");
    //Keyboard.write('s');
  }

  if (joystickShield.isLeftButton()) 
  { 
    Serial.println("Left Button Clicked");
    //Keyboard.write('a');
  }

  // new event functions

  if (joystickShield.isEButton()) { Serial.println("E Button Clicked"); }

  if (joystickShield.isFButton()) { Serial.println("F Button Clicked"); }

  if (joystickShield.isNotCenter()) { Serial.println("NotCenter"); }

  // New position functions
  /*
  Serial.print("x ");    
  Serial.print(joystickShield.xAmplitude());

  Serial.print(" y ");
  Serial.println(joystickShield.yAmplitude());
  */
  delay(150);
}