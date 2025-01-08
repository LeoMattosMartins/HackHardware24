#include "I2Cdev.h"
#include "MPU6050.h"

/* MPU6050 default I2C address is 0x68*/
MPU6050 mpu;

#define DELAY 500
#define OUTPUT_READABLE_ACCELGYRO

#define X_PIN  A0 // Arduino pin connected to VRX pin
#define Y_PIN  A1 // Arduino pin connected to VRY pin
#define KEY_PIN  A2

int xJoystick = 0, yJoystick = 0, key = 0;
int16_t ax, ay, az;
int16_t gx, gy, gz;
char* xJoystickString;
char* yJoystickString;
char* keyString;
bool blinkState;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() 
{
  // put your main code here, to run repeatedly:
  xJoystick = analogRead(X_PIN);
  yJoystick = analogRead(Y_PIN);
  key = analogRead(KEY_PIN);

  if(key == 1023)
  {
    keyString = "UP";
  }
  else if (key >= 800)
  {
    keyString = "RIGHT";
  }
  else if (key >= 600)
  {
    keyString = "LEFT";
  }
  else if (key >= 400)
  {
    keyString = "DOWN";
  }
  else if (key >= 200)
  {
    keyString = "JUMP";
  }
  else
  {
    keyString = "NONE";
  }

  Serial.print("\nbutton = ");
  Serial.print(keyString);

  Serial.print(", xJoystick = ");
  Serial.print(xJoystick);

  Serial.print(", yJoystick = ");
  Serial.print(yJoystick);

  delay(DELAY);
}
