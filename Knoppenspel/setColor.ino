//simple function which takes values for the red, green and blue led and also
//a delay
void setColor(int led, int redValue, int greenValue, int blueValue, int delayValue) {
  pixels1.setPixelColor(led, pixels1.Color(redValue, greenValue, blueValue));
  pixels1.show();
  delay(delayValue);
  pixels2.setPixelColor(led, pixels2.Color(redValue, greenValue, blueValue));
  pixels2.show();
  delay(delayValue);
}