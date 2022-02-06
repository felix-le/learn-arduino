int rotationPin = A0; // potentiometer is connected to analog 0 pin
int RGBredPin = 9; // 
int RGBgreenPin =11 ; // 
int RGBbluePin= 10;//
int potValue; // variable used to store the value coming from the sensor
int data; // variable used to store the percentage value
void setup() {
 pinMode(RGBredPin, OUTPUT); // red LED is as an output
 pinMode(RGBgreenPin, OUTPUT); // green LED is as an output
 pinMode(RGBbluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
}

void combineThreeLed(  int ledTypePort1,  int anaParam1, int ledTypePort2,int anaParam2, int ledTypePort3, int anaParam3 ){
  digitalWrite(ledTypePort1, anaParam1);
  digitalWrite(ledTypePort2, anaParam2);
  digitalWrite(ledTypePort3, anaParam3);
 
}

void loop() {
 potValue = analogRead(rotationPin); // read the value from the potentiometer and assign the name potValue
 data = map(potValue, 0, 1023, 0, 100); // convert potentiometer reading to a percentage

  // show seven color of rainbow

if ( data =<15){ // if it is more than 10% and less then 15%
  // red
  combineThreeLed(RGBredPin, 255, RGBgreenPin, 0, RGBbluePin, 0);

 }
 else if (data >=16 && data <30){ // if it is more than 10% and less then 15%
  //orange
  combineThreeLed(RGBredPin, 255, RGBgreenPin, 127, RGBbluePin, 0);

}
  
 else if (data >=21 && data <25){ // if it is more than 10% and less then 15%
 // yellow
  combineThreeLed(RGBredPin, 255, RGBgreenPin, 255, RGBbluePin, 0);
}
 else if (data >=26 && data <40){ // if it is more than 10% and less then 15%
  // green
  combineThreeLed(RGBredPin, 0, RGBgreenPin, 255, RGBbluePin, 0);

}    
 else if (data >=41 && data <50){ // if it is more than 10% and less then 15%
  // blue
  combineThreeLed(RGBredPin, 0, RGBgreenPin, 0, RGBbluePin, 255);

}    
 else if (data >50){ // if it is more than 10% and less then 15%
  // purple
  combineThreeLed(RGBredPin, 255, RGBgreenPin, 0, RGBbluePin, 255);
}       
 if (data >80){ // if it is more than 10% and less then 15%
  // white
  combineThreeLed(RGBredPin, 255, RGBgreenPin, 255, RGBbluePin, 255);
}  
}