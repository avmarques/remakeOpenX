void game(){
  static long previousTime = 0;
  if (millis() - previousTime >= 750) {
    previousTime = millis();
    if(!twoPlayerMode){
      int randomLED = random(2, 14);
      pixels2.clear();
      pixels2.setPixelColor(randomLED, pixels2.Color(255, 255, 255));
      Serial.println(randomLED);
      
    } else if (twoPlayerMode){
      int randomLEDp1 = random(2, 7);
      int randomLEDp2 = random(8, 13);

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
  // pixels2.clear();
}