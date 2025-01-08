
#define DELAY 200

#include "WiFi.h"
#include "ESPAsyncWebServer.h"

#include <Wire.h>

const char* ssid = "ESP32-Access-Point";
const char* password = "123456789";

#define X_PIN  A0 // Arduino pin connected to VRX pin
#define Y_PIN  A1 // Arduino pin connected to VRY pin
#define KEY_PIN  A0

int xJoystick = 0, yJoystick = 0, key = 0;
char* xJoystickString;
char* yJoystickString;
String keyString;
bool blinkState;

AsyncWebServer server(80);

String getInput()
{
  key = analogRead(KEY_PIN);
  if(key < 100)
  {
    keyString = "UP";
    Serial.print("\nbutton = ");
    Serial.print(keyString);
  }
  else if (key <= 1500)
  {
    keyString = "RIGHT";
    Serial.print("\nbutton = ");
    Serial.print(keyString);
  }
  else if (key <= 2500)
  {
    keyString = "LEFT";
    Serial.print("\nbutton = ");
    Serial.print(keyString);
  }
  else if (key <= 3800)
  {
    keyString = "DOWN";
    Serial.print("\nbutton = ");
    Serial.print(keyString);
  }
  else
  {
    keyString = "NONE";
    // Serial.print("\nbutton = ");
    // Serial.print(keyString);
  }
  return keyString;

}

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  pinMode(KEY_PIN, INPUT);
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);
  server.on("/button", HTTP_GET, [](AsyncWebServerRequest *request){
    String response = getInput();
    request->send(200, "text/plain", response);
  });
  server.begin();

}

void loop() 
{
  // put your main code here, to run repeatedly:
  // xJoystick = analogRead(X_PIN);
  // yJoystick = analogRead(Y_PIN);
  key = analogRead(KEY_PIN);

  if(key < 100)
  {
    keyString = "UP";
    Serial.print("\nbutton = ");
    Serial.print(keyString);
  }
  else if (key <= 1500)
  {
    keyString = "RIGHT";
    Serial.print("\nbutton = ");
    Serial.print(keyString);
  }
  else if (key <= 2500)
  {
    keyString = "LEFT";
    Serial.print("\nbutton = ");
    Serial.print(keyString);
  }
  else if (key <= 3800)
  {
    keyString = "DOWN";
    Serial.print("\nbutton = ");
    Serial.print(keyString);
  }
  else
  {
    keyString = "NONE";
    // Serial.print("\nbutton = ");
    // Serial.print(keyString);
  }

  // Serial.print("\nbutton = ");
  // Serial.print(keyString);
  // Serial.print(key);

  // Serial.print(", xJoystick = ");
  // Serial.print(xJoystick);

  // Serial.print(", yJoystick = ");
  // Serial.print(yJoystick); 
  delay(DELAY);
}
