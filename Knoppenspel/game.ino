int randomLED;
int randomLEDp1;
int randomLEDp2;
int scoreP1 = 0;

const int ledPin =  13;      // the number of the LED pin
int SpelButtonState = 0;
bool next = true;

const int ButtonArray[14]= {0,1,54,55,56,57,58,59,60,61,62,63,64,65};



void game(){
  static long previousTime = 0;
  if (millis() - previousTime >= 2000 || next) {
    next=false;
    previousTime = millis();
    if(!twoPlayerMode){
      randomLED = random(2, 14);
      
      Serial.print("Knop:");
      Serial.println(randomLED);
      
      pixels2.clear();
      pixels2.setPixelColor(randomLED, pixels2.Color(255, 255, 255));
      Serial.println(randomLED);
      
    } else if (twoPlayerMode){
      randomLEDp1 = random(2, 8);
      randomLEDp2 = random(8, 14);

      pixels2.clear();
      pixels2.setPixelColor(randomLEDp1, pixels2.Color(234, 147, 0));
      pixels2.setPixelColor(randomLEDp2, pixels2.Color(173, 216, 230));

      Serial.print("Speler 1:");
      Serial.println(randomLEDp1);
      Serial.print("Speler 2:");
      Serial.println(randomLEDp2);
    }
    
    pixels2.show();
  
  }
  SpelButtonState = digitalRead(ButtonArray[randomLEDp1]);
  if (SpelButtonState) {
    digitalWrite(ledPin, HIGH);
      Serial.println("YES");
      scoreP1++;
    next = true;
    delay(10);
  } else {
    digitalWrite(ledPin, LOW);
    next = false;
  }
}
