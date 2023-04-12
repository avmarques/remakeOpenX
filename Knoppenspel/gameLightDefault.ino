void gameLightDefault(){

  if(actionTime <= millis()){
    actionTime = millis()+1000;
    if(knipperBool){
      knipperBool = false;
    pixels.fill(pixels.Color(255, 255, 255));
    }
    else{
      knipperBool = true;
    pixels.fill(pixels.Color(0, 0, 0));
    }
   // knipperBool = !knipperBool;
  }
  pixels.show();

}