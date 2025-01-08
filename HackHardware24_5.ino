// File: tron_game.ino

#include "Arduino_GigaDisplay_GFX.h" // Graphics library for Arduino GIGA

#define BLUE1 0x7e9d
#define BLUE2 0x6e5c
#define BLUE3 0x5dfb

#define GREEN1 0x466b
#define GREEN2 0x4ecc
#define GREEN3 0x4deb

// Pin definitions for Player 1 (WASD-style)
const int player1UpPin = 2;
const int player1DownPin = 3;
const int player1LeftPin = 4;
const int player1RightPin = 5;

// Pin definitions for Player 2 (Arrow keys-style)
const int player2UpPin = 6;
const int player2DownPin = 7;
const int player2LeftPin = 8;
const int player2RightPin = 9;

// Constants for display
const int screenWidth = 480; // GIGA Display Width
const int screenHeight = 320; // GIGA Display Height
const int tileSize = 10; // Size of each tile in the grid
const int gridWidth = screenWidth / tileSize;
const int gridHeight = screenHeight / tileSize;

// Player 1 properties
int player1X = gridWidth / 4, player1Y = gridHeight / 2; // Starting position
int player1DirX = 1, player1DirY = 0; // Starting direction
bool player1Alive = true;

// Player 2 properties
int player2X = (3 * gridWidth) / 4, player2Y = gridHeight / 2; // Starting position
int player2DirX = -1, player2DirY = 0; // Starting direction
bool player2Alive = true;

// Game board grid
int gameGrid[gridHeight][gridWidth]; // 0 = empty, 1 = Player 1 trail, 2 = Player 2 trail

// Initialize the display object
GigaDisplay_GFX display;
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

void setup() {
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

  // Initialize game grid
  for (int y = 0; y < gridHeight; y++) {
    for (int x = 0; x < gridWidth; x++) {
      gameGrid[y][x] = 0;
    }
  }
}

void loop() {
  Background();
  if (player1Alive && player2Alive) {
    handleInput();
    movePlayers();
    checkCollisions();
    drawGame();
    delay(200); // Game speed
  } else {
    displayGameOver();
    while (true); // Stop the game
  }
}

void handleInput() {
  // Player 1 input
  if (digitalRead(player1UpPin) == LOW && player1DirY == 0) {
    player1DirX = 0;
    player1DirY = -1;
  } else if (digitalRead(player1DownPin) == LOW && player1DirY == 0) {
    player1DirX = 0;
    player1DirY = 1;
  } else if (digitalRead(player1LeftPin) == LOW && player1DirX == 0) {
    player1DirX = -1;
    player1DirY = 0;
  } else if (digitalRead(player1RightPin) == LOW && player1DirX == 0) {
    player1DirX = 1;
    player1DirY = 0;
  }

  // Player 2 input
  if (digitalRead(player2UpPin) == LOW && player2DirY == 0) {
    player2DirX = 0;
    player2DirY = -1;
  } else if (digitalRead(player2DownPin) == LOW && player2DirY == 0) {
    player2DirX = 0;
    player2DirY = 1;
  } else if (digitalRead(player2LeftPin) == LOW && player2DirX == 0) {
    player2DirX = -1;
    player2DirY = 0;
  } else if (digitalRead(player2RightPin) == LOW && player2DirX == 0) {
    player2DirX = 1;
    player2DirY = 0;
  }
}

void movePlayers() {
  // Update Player 1 position
  if (player1Alive) {
    player1X += player1DirX;
    player1Y += player1DirY;

    // Check if Player 1 crashes into the wall or a trail
    if (player1X < 0 || player1X >= gridWidth || player1Y < 0 || player1Y >= gridHeight || gameGrid[player1Y][player1X] != 0) {
      player1Alive = false;
    } else {
      gameGrid[player1Y][player1X] = 1;
    }
  }

  // Update Player 2 position
  if (player2Alive) {
    player2X += player2DirX;
    player2Y += player2DirY;

    // Check if Player 2 crashes into the wall or a trail
    if (player2X < 0 || player2X >= gridWidth || player2Y < 0 || player2Y >= gridHeight || gameGrid[player2Y][player2X] != 0) {
      player2Alive = false;
    } else {
      gameGrid[player2Y][player2X] = 2;
    }
  }
}

void checkCollisions() {
  // If both players crash into each other or trails at the same time
  if (!player1Alive && !player2Alive) {
    display.fillScreen(display.color565(255, 255, 0));
    display.setCursor(screenWidth / 4, screenHeight / 2);
    display.setTextColor(display.color565(0, 0, 0));
    display.setTextSize(3);
    display.print("DRAW!");
    while (true); // End game loop
  }
}

void drawGame() {
  display.fillScreen(0); // Clear the screen

  // Draw game grid
  for (int y = 0; y < gridHeight; y++) {
    for (int x = 0; x < gridWidth; x++) {
      if (gameGrid[y][x] == 1) {
        display.fillRect(x * tileSize, y * tileSize, tileSize, tileSize, display.color565(0, 0, 255)); // Player 1 trail
      } else if (gameGrid[y][x] == 2) {
        display.fillRect(x * tileSize, y * tileSize, tileSize, tileSize, display.color565(255, 0, 0)); // Player 2 trail
      }
    }
  }

  // Draw Player 1
  display.fillRect(player1X * tileSize, player1Y * tileSize, tileSize, tileSize, display.color565(0, 0, 255));

  // Draw Player 2
  display.fillRect(player2X * tileSize, player2Y * tileSize, tileSize, tileSize, display.color565(255, 0, 0));
}

void displayGameOver() {
  display.fillScreen(0);
  display.setCursor(screenWidth / 4, screenHeight / 2);
  display.setTextColor(display.color565(255, 255, 255));
  display.setTextSize(3);
  if (!player1Alive && player2Alive) {
    display.print("Player 2 Wins!");
  } else if (!player2Alive && player1Alive) {
    display.print("Player 1 Wins!");
  } else {
    display.print("It's a Draw!");
  }
}
