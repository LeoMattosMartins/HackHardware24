#include "Arduino_GigaDisplay_GFX.h" // Graphics library for Arduino GIGA

#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

// Pin definitions for Player 1 (WASD-style)
#define player1UpPin  2
#define player1DownPin  3
#define player1LeftPin  4
#define player1RightPin  5

// Pin definitions for Player 2 (Arrow keys-style)
#define player2UpPin  6
#define player2DownPin 7
#define player2LeftPin  8
#define player2RightPin  9

#define INTERVAL 5

GigaDisplay_GFX display;

int xPos1 = 100, xPos2 = 300, yPos1 = 100, yPos2 = 100;

void setup() {
  // put your setup code here, to run once:
  display.begin();
  display.setRotation(1); 
  display.fillScreen(0); // Clear the screen

  // Initialize button pins for Player 1
  pinMode(player1UpPin, INPUT);
  pinMode(player1DownPin, INPUT);
  pinMode(player1LeftPin, INPUT);
  pinMode(player1RightPin, INPUT);

  // Initialize button pins for Player 2
  pinMode(player2UpPin, INPUT);
  pinMode(player2DownPin, INPUT);
  pinMode(player2LeftPin, INPUT);
  pinMode(player2RightPin, INPUT);
}

void loop() {
  display.fillScreen(0); // Clear the screen

  display.setTextSize(3);
  display.setCursor(xPos1, yPos1);
  display.setTextColor(YELLOW);
  display.print("C");
  display.setCursor(xPos1, yPos1);
  display.setTextColor(YELLOW);
  display.print("<");
  display.setCursor(xPos1, yPos1);
  display.setTextColor(YELLOW);
  display.print("(");

  display.setCursor(xPos2, yPos2);
  display.setTextColor(RED);
  display.print("B");

  int up1 = digitalRead(player1UpPin);
  int down1 = digitalRead(player1DownPin);
  int left1 = digitalRead(player1LeftPin);
  int right1 = digitalRead(player1RightPin);

  // Initialize button pins for Player 2
  int up2 = digitalRead(player2UpPin);
  int down2 = digitalRead(player2DownPin);
  int left2 = digitalRead(player2LeftPin);
  int right2 = digitalRead(player2RightPin);

  if(up1) { yPos1 -= INTERVAL; }
  if(down1) { xPos1 += INTERVAL; }
  if(right1) { xPos1 -= INTERVAL; }
  if(left1) { yPos1 += INTERVAL; }

  if(up2) { yPos2 += INTERVAL; }
  if(down2) { yPos2 -= INTERVAL; }
  if(right2) { xPos2 += INTERVAL; }
  if(left2) { xPos2 -= INTERVAL; }

  delay(10);
  // put your main code here, to run repeatedly:

}
