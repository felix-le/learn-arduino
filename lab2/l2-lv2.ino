// Viet Anh Le - Felix
// COMP 1045 Lab 2
// January 20 ,2022

// Level 2:​ Create your own personalized 15 second light show. You need to use at least 3 different time variables between 500 and 1000 ms. Add comments every 5 seconds of your light show.

// declare variables

int RGBRedPin = 9;    //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11;  //The blue RGB LED is connected pin 11 of the Arduino.

int offTime = 1000; //Sets the amount of time to show between color changes.
int showTimeShort = 500; 
int showTimeNormal = 1000;

void setup() { 
  //The Setup function runs once.
  pinMode(RGBRedPin, OUTPUT); //Setup red RGB LED pin as an output pin.
  pinMode(RGBGreenPin, OUTPUT); //Setup green RGB LED pin as an output pin.
  pinMode(RGBBluePin, OUTPUT); //Setup blue RGB LED pin as an output pin.
}
void singleLed(int showTime, int ledTypePort){
  digitalWrite(ledTypePort, HIGH);
  delay(showTime); 
  digitalWrite(ledTypePort, LOW);
  delay(offTime); // Wait for 1 second
}

void combineTwoLed(int showTime, int ledTypePort1, int ledTypePort2){
  digitalWrite(ledTypePort1, HIGH);
  digitalWrite(ledTypePort2, HIGH);
  delay(showTime);
  digitalWrite(ledTypePort1, LOW);
  digitalWrite(ledTypePort2, LOW);
  delay(offTime);  // Wait for 1 second
}
void combineThreeLed(int showTime, int ledTypePort1, int ledTypePort2, int ledTypePort3 ){
  digitalWrite(ledTypePort1, HIGH);
  digitalWrite(ledTypePort2, HIGH);
  digitalWrite(ledTypePort3, HIGH);
  delay(showTime);
  digitalWrite(ledTypePort1, LOW);
  digitalWrite(ledTypePort2, LOW);
  digitalWrite(ledTypePort3, LOW);
  delay(offTime); // Wait for 1 second
}

void loop() {

  // first 5 seconds
  singleLed(showTimeShort, RGBRedPin ); // Display Red for 1.5 seconds
  combineTwoLed(showTimeShort, RGBRedPin , RGBGreenPin) ; // Display Red + Green for 1.5 seconds
  combineThreeLed(showTimeNormal, RGBRedPin , RGBGreenPin, RGBBluePin ) ; // Display Red + Green for 2 seconds

  // second 5 seconds
  combineTwoLed(showTimeNormal, RGBBluePin , RGBGreenPin) ; // Display Red + Green for 2 seconds
  singleLed(showTimeNormal, RGBRedPin ); // Display Red for 2 seconds
  combineThreeLed(showTimeShort, RGBRedPin , RGBGreenPin, RGBBluePin ) ; // Display Red + Green for 1.5 seconds

  // third 5 seconds
  combineTwoLed(showTimeNormal, RGBGreenPin , RGBRedPin) ; // Display Red + Green for 2 seconds
  singleLed(showTimeNormal, RGBBluePin ); // Display Red for 2 seconds
  combineThreeLed(showTimeShort, RGBRedPin , RGBGreenPin, RGBBluePin ) ; // Display Red + Green for 1.5 seconds

}