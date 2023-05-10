void gameEnding(){
  
    pixels2.fill(pixels1.Color(255, 255, 255));
    pixels2.show();
    delay(1000);
    pixels2.fill(pixels1.Color(0, 0, 0));
    pixels2.show();
    pixels2.clear();

  
}