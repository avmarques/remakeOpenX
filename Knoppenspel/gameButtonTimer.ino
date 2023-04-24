
void gameLightTimer(){ //count down during game
  if(!isCountingDown){
    pixels1.fill(pixels1.Color(0, 0, 0));
    pixels1.show();
      for (int led = 0; led <= numPixels; led++) {
      setColor(led, 255, 255, 255, 30);
      }
      isCountingDown = true;
      led = numPixels;
  }
  if(countDownTimer <= millis() && isCountingDown){
    setColor(led, 0, 0, 0, 0);
    led--;
    if(led <= 0){
      isCountingDown = false;
      twoPlayerMode = false;
    }
    
      countDownTimer = millis()+1000;
  }

}