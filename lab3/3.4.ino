
// Viet Anh Le - Felix
// COMP 1045 Lab 3.4
// Feb 5 ,2022

int rotationPin = A0; // potentiometer is connected to analog 0 pin
int RGBredPin = 9; // 
int RGBgreenPin =11 ; // 
int RGBbluePin= 10;//
int incomingByte = 0;
int potValue; // variable used to store the value coming from the sensor
int data; // variable used to store the percentage value
void setup() {
 pinMode(RGBredPin, OUTPUT); // red LED is as an output
 pinMode(RGBgreenPin, OUTPUT); // green LED is as an output
 pinMode(RGBbluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
}

void singleLed(int ledTypePort, int ledTypePort2,int ledTypePort3){
  digitalWrite(ledTypePort, HIGH);
  digitalWrite(ledTypePort2, LOW);
  digitalWrite(ledTypePort3, LOW);
}

void loop() {
  
 potValue = analogRead(rotationPin); // read the value from the potentiometer and assign the name potValue
 data = map(potValue, 0, 1023, 0, 100); // convert potentiometer reading to a percentage    

 // level 4

  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    // say what you got:
    Serial.print("red");
    Serial.println(incomingByte, DEC);
    
    
    if(incomingByte == 82){
     singleLed(RGBredPin, RGBgreenPin, RGBbluePin);
    } else if( incomingByte ==71 ){
      singleLed(RGBbluePin, RGBgreenPin, RGBredPin);
     }else if(incomingByte == 66){
      singleLed(RGBgreenPin, RGBgreenPin, RGBredPin);

    }
  
  }

}