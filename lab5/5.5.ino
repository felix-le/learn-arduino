// Viet Anh Le (Felix)
// Date: Feb 22 2022
// Description: lab 5 - level 4


int RGBRedPin = 9; //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11; //The blue RGB LED is connected pin 11 of the Arduino.
int waitTime = 500; //Sets the amount of time for 1 sec
int button1Pin=2;
int button2Pin=3;

int flagBtn1 = 0;
int flagBtn2 = 0;

int singleGreen = 12;
int singleRed = 13;



void setup() { //The Setup function runs once.
pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
pinMode(singleGreen, OUTPUT);
  pinMode(singleRed, OUTPUT);
  //set up buttons
pinMode(button1Pin,INPUT);
pinMode(button2Pin,INPUT);

}
void singleLed(int ledTypePort){
  digitalWrite(ledTypePort, HIGH);
  delay(waitTime); 
  digitalWrite(ledTypePort, LOW);
}
void combineTwoLed(  int ledTypePort1, int ledTypePort2){
  digitalWrite(ledTypePort1, HIGH);
  digitalWrite(ledTypePort2, HIGH);
  delay(waitTime);
  digitalWrite(ledTypePort1, LOW);
  digitalWrite(ledTypePort2, LOW);
}

void runShowTime(){
    singleLed(RGBRedPin);
    singleLed(RGBGreenPin);
    singleLed(RGBBluePin);
    combineTwoLed(RGBRedPin, RGBGreenPin);
    combineTwoLed(RGBRedPin, RGBBluePin);
    combineTwoLed(RGBBluePin, RGBGreenPin);
}


void loop() {//the loop function for pressing the button
  if(digitalRead(button1Pin)==HIGH){
    if(flagBtn1 == 0){
      flagBtn1 = 1;
      digitalWrite(singleGreen, HIGH);
      digitalWrite(singleRed, LOW);
      
   
      delay(waitTime);
    }else if(flagBtn1 == 1){
      flagBtn1 = 0;
      digitalWrite(singleGreen, LOW);
      digitalWrite(singleRed, HIGH);	
      delay(waitTime);
    }
  }
   if(flagBtn1 == 1 &&digitalRead(button2Pin)==HIGH){
      runShowTime();
   };
  
 
}