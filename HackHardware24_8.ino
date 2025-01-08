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

#define X_PIN A0
#define Y_PIN A1
#define DELAY 10
#define INTERVAL 2
#define FOOD_CHAR '*' 

#define X_OFFSET 150
#define TIME_OFFSET 75

int count = 0;
int xPos, yPos; // Position of the text (y-axis)
int xs[] = {0, 0};
int ys[] = {0, 0};
int xDiff, yDiff;

int textWidth = 160;  // Estimate the width of the text (adjust based on font size)
int yFood = 110;
int xFood[] = {50, 100, 150, 200, 250};
int yOffset = 0;

int randomArrows[] = {2, 3, 1, 0, 2, 1, 3, 0, 1, 2, 0, 3, 1, 2, 3, 0, 1, 3, 2, 0, 3, 1, 0, 2, 1, 3, 2, 0, 1, 3, 0, 2, 1, 3, 0, 2, 1, 3, 2, 0, 3, 1, 0, 2, 3, 1, 2, 0, 3, 1, 2, 0, 1, 3, 2, 0, 1, 3, 2, 0, 3, 1, 0, 2, 1, 3, 0, 2, 1, 3, 2, 0, 3, 1, 2, 0, 1, 3, 0, 2, 3, 1, 0, 2, 3, 1, 0, 2, 1, 3, 0, 2, 1, 3, 2, 0, 3, 1, 0, 2, 3, 1, 2, 0, 1, 3, 2, 0, 3, 1, 0, 2, 1, 3, 2, 0, 3, 1, 0, 2, 1, 3, 0, 2, 1, 3, 2, 0, 1, 3, 0, 2, 1, 3, 2, 0};

int key = 0;

void Background()
{
  display.fillRect(0,0 , 800, 150, BLUE1);
  display.fillRect(0,150 , 800, 150, BLUE2);
  display.fillRect(0,300 , 800, 160, BLUE3);

  display.fillRect(0, 460, 800, 20, GREEN1);
  display.setCursor(10, 430);
  display.setTextColor(GREEN1);
  display.setTextSize(5);
  display.print("ww|w||ww||w|w||WwW||W|www|");
  //display.fillRect(0, 410, 800, 400, GREEN2);
  display.setCursor(15, 437);
  display.setTextColor(GREEN2);
  // display.setTextSize(5);
  display.print("w|W||wW||W|w||WW||W|wwwwi");
  display.setCursor(8, 445);
  display.setTextColor(GREEN3);
  // display.setTextSize(5);
  display.print("w|W||wW||W|w||WW||W|wwwwi");
  display.setCursor(6, 445);
  display.print("xwxxxwwxxxxxwwxxxwxxxwwxxx");
  // Set the cursor to the new position
}

void downArrow(int y){
  display.setTextSize(5);
  display.setCursor(X_OFFSET, y);
  display.setTextColor(RED);
  display.print("v");
  display.setCursor(X_OFFSET, y);
  display.print("!");
}

void upArrow(int y){
  display.setCursor(X_OFFSET * 3, y);
  display.setTextSize(5);
  display.setTextColor(YELLOW);
  display.print("^");
  display.setCursor(X_OFFSET * 3, y);
  display.print("!");
}

void leftArrow(int y){
  display.setCursor(X_OFFSET * 4, y);
  display.setTextSize(5);
  display.setTextColor(CYAN);
  display.print("-");
  display.setCursor(X_OFFSET * 4, y);
  display.print(">");
}

void rightArrow(int y){
  display.setCursor(X_OFFSET * 2 + 10, y);
  display.setTextSize(5);
  display.setTextColor(GREEN);
  display.print("-");
  display.setCursor(X_OFFSET * 2, y);
  display.print("<");
}

void setup() 
{
  // Initialize the display
  display.begin();
  Serial.begin(9600);
  //Serial.begin(9600);

  // Clear the screen with a black background
  display.fillScreen(BLACK);

  // Rotate 90 degrees
  display.setCursor(0, 0);
  display.setRotation(1); 

  pinMode(X_PIN, INPUT);
  pinMode(Y_PIN, INPUT);
}

int ii = 0;

void loop() {
  // Clear the previous text
  ii++;
  if(ii > 5){ii = 0;}
  if(!ii)
  {
    xPos = ((analogRead(X_PIN) - 266) / 2) * 2;
    yPos = ((analogRead(Y_PIN) - 586) / 2) * 2;

    if(xPos <= 1) {xPos = 0; }
    if(yPos <= 1) {yPos = 0; }
  }
  // Serial.print(xPos);
  // Serial.print(" --- ");
  // Serial.println(yPos);
  display.fillScreen(BLACK);
  display.fillRect(0, 420, 800, 5, WHITE);

  yOffset += INTERVAL;
  
  downArrow(yOffset);
  rightArrow(yOffset - 1 * TIME_OFFSET);
  leftArrow(yOffset - 2 * TIME_OFFSET);
  upArrow(yOffset - 3 * TIME_OFFSET);
  leftArrow(yOffset - 4 * TIME_OFFSET);
  leftArrow(yOffset - 5 * TIME_OFFSET);
  downArrow(yOffset - 6 * TIME_OFFSET);
  upArrow(yOffset - 7 * TIME_OFFSET);
  rightArrow(yOffset - 8 * TIME_OFFSET);
  upArrow(yOffset - 7 * TIME_OFFSET);
  rightArrow(yOffset - 8 * TIME_OFFSET);
  downArrow(yOffset - 9 * TIME_OFFSET);
  upArrow(yOffset - 10 * TIME_OFFSET);
  leftArrow(yOffset - 11 * TIME_OFFSET);
  downArrow(yOffset - 12 * TIME_OFFSET);
  leftArrow(yOffset - 13 * TIME_OFFSET);
  rightArrow(yOffset - 14 * TIME_OFFSET);
  leftArrow(yOffset - 15 * TIME_OFFSET);
  upArrow(yOffset - 16 * TIME_OFFSET);
  upArrow(yOffset - 17 * TIME_OFFSET);
  leftArrow(yOffset - 18 * TIME_OFFSET);
  rightArrow(yOffset - 19 * TIME_OFFSET);
  rightArrow(yOffset - 20 * TIME_OFFSET);
  downArrow(yOffset - 21 * TIME_OFFSET);
  downArrow(yOffset - 22 + TIME_OFFSET);
  leftArrow(yOffset - 23 * TIME_OFFSET);
  leftArrow(yOffset - 24 * TIME_OFFSET);
  leftArrow(yOffset - 25 * TIME_OFFSET);
  downArrow(yOffset - 26 * TIME_OFFSET);
  upArrow(yOffset - 27 * TIME_OFFSET);
  downArrow(yOffset - 28 * TIME_OFFSET);
  rightArrow(yOffset - 29 * TIME_OFFSET);
  leftArrow(yOffset - 30 * TIME_OFFSET);
  rightArrow(yOffset - 31 * TIME_OFFSET);
  upArrow(yOffset - 32 * TIME_OFFSET);
  leftArrow(yOffset - 33 * TIME_OFFSET);

    // Clear the eaten food
  // for(int ii = 0; ii < 5; ii++)
  // {
  //   display.setTextSize(2);
  //   display.setCursor(xFood[ii], yFood + 10);
  //   display.setTextColor( (((xPos + 5) > xFood[ii]) || ((xPos) > xFood[ii])) ? BLACK : WHITE );  // Set color to background to erase food
  //   display.print(FOOD_CHAR);  // Clear the food
  // }

  // display.setCursor(xPos, yPos);
  // display.setTextSize(5);  // Set the text size
  // display.setTextColor( YELLOW );  // Set the text color to yellow
  // display.print("C");  // Print the text
  // display.setCursor(xPos - 1, yPos);
  // display.print("<");
  // display.setCursor(xPos - 1, yPos);
  // display.print("(");
  // display.setCursor(xPos - 1, yPos);
  // display.print("[");
  //delay(350);

  // display.setCursor(xPos, yPos);
  // display.setTextSize(5);  // Set the text size
  // display.setTextColor((!((xPos + 5) % 50) || !((xPos + 10) % 50)) ? MAGENTA : YELLOW);
  // display.print("o");
  // display.setCursor(xPos - 1, yPos);
  // display.print("0");
  // display.setCursor(xPos - 1, yPos);
  // display.print("O");
  // display.setCursor(xPos - 1, yPos);
  // display.print("G");
  // display.setCursor(xPos - 1, yPos);
  // display.print("@");
  // delay(350);

  // Update the position of the text for animation
  //xPos++;  // Move the text to the right by 1 pixel
  // if( key == 0 )
  // {
  //   yPos -= INTERVAL;
  // }
  // else if( key < 300 )
  // {
  //   xPos += INTERVAL;
  // }
  // else if( key < 500 )
  // {
  //   xPos -= INTERVAL;
  // }
  // else if( key < 800 )
  // {
  //   yPos += INTERVAL;
  // } 
  // Reset position when it goes off-screen
  // if (xPos > display.width()) {
  //   xPos = -textWidth;  // Start the text from the left again
  // }
  // if (xPos > display.height()) {
  //   yPos = -textWidth;
  // }

  delay(DELAY);  // Delay to control the speed of the animation
}
