#include "Arduino_GigaDisplay_GFX.h"

GigaDisplay_GFX display;  // Create the object to control the display

#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

#define BLUE1 0x7e9d
#define BLUE2 0x6e5c
#define BLUE3 0x5dfb

#define GREEN1 0x466b
#define GREEN2 0x4ecc
#define GREEN3 0x4deb

#define UP_PIN 2
#define RIGHT_PIN 3
#define DOWN_PIN 4
#define LEFT_PIN 5

#define INTERVAL 6

int xPos = 100, yPos = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(UP_PIN, INPUT);
  pinMode(RIGHT_PIN, INPUT);
  pinMode(DOWN_PIN, INPUT);
  pinMode(LEFT_PIN, INPUT);

  Serial.begin(9600);
  display.begin();
  //Serial.begin(9600);

  // Clear the screen with a black background
  display.fillScreen(BLACK);

  // Rotate 90 degrees
  display.setCursor(0, 0);
  display.setRotation(1); 
}
int test, count = 0;

void loop() {
  // put your main code here, to run repeatedly:
  display.fillScreen(BLACK);

  display.setCursor(xPos, yPos);
  display.setTextSize(8);
  display.setTextColor(YELLOW);


  if(digitalRead(2))      { yPos--; }
  else if(digitalRead(3)) { xPos++; }
  else if(digitalRead(4)) { yPos++; }
  else if(digitalRead(5)) { xPos--; }

  display.print("O");

  delay(10);
}

