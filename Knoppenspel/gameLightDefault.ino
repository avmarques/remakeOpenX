void gameLightDefault(){

  pixels.fill(pixels.Color(255, 255, 255)); 
  pixels.show(); // update de Neopixel-ring
  delay(1000);
  pixels.fill(pixels.Color(0, 0, 0)); 
  pixels.show(); // update de Neopixel-ring
  delay(1000);


}