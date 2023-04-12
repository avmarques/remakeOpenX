#include <Adafruit_MCP23X08.h>
#include <Adafruit_MCP23X17.h>
#include <Adafruit_MCP23XXX.h>

#include <Wire.h>

#include <Adafruit_NeoPixel.h>

#define startButton 0
#define twoPlayerButton 14
#define PIN 12

int buttonState;    // de huidige staat van de knop
int lastButtonState = LOW; // de laatste bekende staat van de knop

uint8_t numPixels = 32;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numPixels, PIN, NEO_GRB + NEO_KHZ800);

Adafruit_MCP23X17 mcp;

long actionTime = 0;
bool knipperBool = false;

long countDownTimer = 0;
bool isCountingDown = false;

//tweespeler modus
bool twoPlayerMode = false;
bool gameInProgress = false;

void setup() {
  Wire.begin();
  mcp.begin_I2C(0x20); // Address 0

  mcp.pinMode(startButton, INPUT_PULLUP);
  mcp.pinMode(twoPlayerButton, INPUT_PULLUP);

  pinMode(27, OUTPUT);

  // put your setup code here, to run once:
  Serial.begin(115200);

  pixels.begin();  // This initializes the NeoPixel library.
  pixels.setBrightness(100);

}

void loop() {
  soilCheck();    //TODO
  uvLightCheck(); //TODO

  bool startState = mcp.digitalRead(startButton);  // lees de staat van de knop
  bool twoPlayerState = mcp.digitalRead(twoPlayerButton);  // lees de staat van de multiplayerknop

  if(twoPlayerState == true && !gameInProgress){   //2 speler modus kan alleen worden ingeschakeld wanneer er nog niet op de startknop is gedrukt
    twoPlayerMode = true;
    Serial.println("Tweespeler modus is ingeschakeld"); 
  } else if(!gameInProgress && !twoPlayerMode ) {
    Serial.println("Nope fuck you");
  }
  
  //Serial.println(startState);

  if(startState == HIGH || isCountingDown ){
    gameLightTimer(); 
    digitalWrite(27,HIGH);
    gameInProgress = true;
  } else {
    gameLightDefault();
    digitalWrite(27,LOW);
    gameInProgress = false;
  }

}
