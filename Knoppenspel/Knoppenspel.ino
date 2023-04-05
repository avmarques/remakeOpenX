#include <Adafruit_MCP23X08.h>
#include <Adafruit_MCP23X17.h>
#include <Adafruit_MCP23XXX.h>

#include <Adafruit_NeoPixel.h>

#define startButton 2
#define PIN 12

int buttonState;    // de huidige staat van de knop
int lastButtonState = LOW; // de laatste bekende staat van de knop

int numPixels = 32;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(numPixels, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pixels.begin();  // This initializes the NeoPixel library.
  pixels.setBrightness(100);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  int startState = digitalRead(startButton);  // lees de staat van de knop
  delay(100);
  
  Serial.println(startState);

  if(startState == HIGH){
    gameLightTimer(); 
  } else {
    gameLightDefault();
  }

}
