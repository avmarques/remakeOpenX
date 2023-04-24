void gameLightDefault(){

  if(actionTime <= millis()){
    actionTime = millis()+1000;
    if(knipperBool){
      knipperBool = false;
    pixels1.fill(pixels1.Color(255, 255, 255));
    }
    else{
      knipperBool = true;
    pixels1.fill(pixels1.Color(0, 0, 0));
    }
   // knipperBool = !knipperBool;
  }
  pixels1.show();

}