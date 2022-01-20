// Viet Anh Le - Felix
// COMP 1045 Lab 2
// January 20 ,2022

// Level 2:​ Create your own personalized 15 second light show. You need to use at least 3 different time variables between 500 and 1000 ms. Add comments every 5 seconds of your light show.

// declare variables

int RGBRedPin = 9;    //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11;  //The blue RGB LED is connected pin 11 of the Arduino.

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
}

void combineTwoLed( int showTime,  int ledTypePort1, int ledTypePort2){
  digitalWrite(ledTypePort1, HIGH);
  digitalWrite(ledTypePort2, HIGH);
  delay(showTime);
  digitalWrite(ledTypePort1, LOW);
  digitalWrite(ledTypePort2, LOW);
}

void combineThreeLed( int showTime,  int ledTypePort1, int ledTypePort2, int ledTypePort3 ){
  digitalWrite(ledTypePort1, HIGH);
  digitalWrite(ledTypePort2, HIGH);
  digitalWrite(ledTypePort3, HIGH);
  delay(showTime);
  digitalWrite(ledTypePort1, LOW);
  digitalWrite(ledTypePort2, LOW);
  digitalWrite(ledTypePort3, LOW);
}
 
void loop() {
  // loop from 1 to 10
  for (int i = 1; i <= 10; i++) {
    singleLed(i *1000 / 7, RGBRedPin ); // Display Red
    singleLed(i *1000 / 7,RGBGreenPin ); // Display Green
    singleLed(i *1000 / 7,RGBBluePin ); // Display Blue
    combineTwoLed(i *1000 / 7,RGBRedPin , RGBBluePin) ; // Display Magenta Red + Blue
    combineTwoLed(i *1000 / 7,RGBGreenPin , RGBBluePin) ; // Display Cyan Green + Blue
    combineTwoLed(i *1000 / 7,RGBRedPin , RGBGreenPin) ; // Display Yellow Red + Green
    combineThreeLed(i *1000 / 7,RGBRedPin , RGBGreenPin, RGBBluePin ) ; // Display White Red + Green + Blue
  }
}