void gameLightTimer(){ //count down during game
    for (int led = 0; led <= numPixels; led++) {

    setColor(led, 255, 255, 255, 100);
  }
  delay(100);
  for (int led = numPixels; led >= 0; led--) {

    setColor(led, 0, 0, 0, 100);
    delay(1000);
  }
  delay(100);
}