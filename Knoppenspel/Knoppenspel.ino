#include <Adafruit_NeoPixel.h>

#define startButton 8
#define twoPlayerButton 33
#define pinStartRing 10

#define buttonLedPin 12
uint8_t ledCount = 14;


int buttonState;    // de huidige staat van de knop
int lastButtonState = LOW; // de laatste bekende staat van de knop

uint8_t numPixels = 32;
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(numPixels, pinStartRing, NEO_GRB + NEO_KHZ800);
int led = numPixels;

Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(ledCount, buttonLedPin, NEO_GRB + NEO_KHZ800);

//Score visualisatie 
#define LED_ScoreSunPIN 6
#define LED_ScoreWaterPIN 4

#define LED_ScoreCOUNT 10

Adafruit_NeoPixel pixels3 = Adafruit_NeoPixel(LED_ScoreCOUNT, LED_ScoreSunPIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4 = Adafruit_NeoPixel(LED_ScoreCOUNT, LED_ScoreWaterPIN, NEO_GRB + NEO_KHZ800);

int scoreP1 = 0;
int scoreP2 = 0;
int currentPixel;


long actionTime = 0;
bool knipperBool = false;

long countDownTimer = 0;
bool isCountingDown = false;

//tweespeler modus
long reset2playerTime = 0;
bool twoPlayerMode = false;
bool gameInProgress = false;

void setup() {

  pinMode(startButton, INPUT_PULLUP);
  pinMode(twoPlayerButton, INPUT_PULLUP);

  // put your setup code here, to run once:
  Serial.begin(115200);

  pixels1.begin();  // This initializes the NeoPixel library.
  pixels1.setBrightness(255);

  pixels2.begin();  // This initializes the NeoPixel library.
  pixels2.setBrightness(255);

  pixels1.clear();
  pixels2.clear();

  //score zon
  pixels3.begin();
  pixels3.clear();
  pixels3.show();  // Zet alle neopixels uit bij de start

  //score water
  pixels4.begin();
  pixels4.clear();
  pixels4.show();  // Zet alle neopixels uit bij de start

}

void loop() {

  bool startState = digitalRead(startButton);  // lees de staat van de knop
  bool twoPlayerState = digitalRead(twoPlayerButton);  // lees de staat van de multiplayerknop

  twoPlayerMode = true;

  // if(twoPlayerState == true && !gameInProgress /*&& reset2playerTime > millis()*/){   //2 speler modus kan alleen worden ingeschakeld wanneer er nog niet op de startknop is gedrukt
  //   if(reset2playerTime <= millis()) {
  //     twoPlayerMode = false;
  //     Serial.println("Tweespeler modus is NO MORE");
  //   }  
  //   else{
  //     twoPlayerMode = true;
  //     Serial.println("Tweespeler modus is ingeschakeld");
  //   }  
  // } 
  // else {
  //   reset2playerTime = millis()+2000;
  // }
  
  //Serial.println(startState);

  if(startState == HIGH || isCountingDown ){
    gameLightTimer();
    game();
    //gameSound();
    gameInProgress = true;
    digitalWrite(27, HIGH);
  } else {
    gameLightDefault();
    gameInProgress = false;
    scoreP1 = 0;
    currentPixel = 0;
    pixels2.clear();
    digitalWrite(27, LOW);
  }

}



