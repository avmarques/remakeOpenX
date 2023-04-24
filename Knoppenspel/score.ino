// void scoreVisualise(){
//   static long previousTime = 0;
//   if (millis() - previousTime >= 750) {
//     previousTime = millis();
//     int randomLED = random(2, 8);
//     pixels2.clear();
//     if (randomLED >= 2 && randomLED <= 9) {
//         pixels2.setPixelColor(randomLED, pixels2.Color(255, 255, 255));
//         Serial.println(randomLED);
//     }
//     pixels2.show();
// }