void score(){
  
  pixels3.show();
  int scoreZon = map(scoreP1, 0, 64, 0, 9);
  Serial.println(scoreZon);
  
  pixels3.setPixelColor(currentPixel, 255, 50, 0);

  if (scoreZon != currentPixel) {
    currentPixel = currentPixel + 1;
  }

  Serial.println(currentPixel);

}