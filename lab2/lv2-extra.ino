// Viet Anh Le - Felix
// COMP 1045 Lab 2
// January 20 ,2022
#include <time.h>
#include <stdlib.h>
// Level 2:​ Create your own personalized 15 second light show. You need to use at least 3 different time variables between 500 and 1000 ms. Add comments every 5 seconds of your light show.

int random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}

// declare variables

int RGBRedPin = 9;    //The red RGB LED is connected pin 9 of the Arduino.
int RGBGreenPin = 10; //The green RGB LED is connected pin 10 of the Arduino.
int RGBBluePin = 11;  //The blue RGB LED is connected pin 11 of the Arduino.


int showtime1= random_number(500, 1000); 
int showtime2= random_number(500, 1000); 
int showtime3= random_number(500, 1000); 
int limitTime = 15000;
int offTime = 5000; // Set time off while sum > 15000

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

void combineTwoLed(int showTime, int ledTypePort1, int ledTypePort2){
  digitalWrite(ledTypePort1, HIGH);
  digitalWrite(ledTypePort2, HIGH);
  delay(showTime);
  digitalWrite(ledTypePort1, LOW);
  digitalWrite(ledTypePort2, LOW);
}
void combineThreeLed(int showTime, int ledTypePort1, int ledTypePort2, int ledTypePort3 ){
  digitalWrite(ledTypePort1, HIGH);
  digitalWrite(ledTypePort2, HIGH);
  digitalWrite(ledTypePort3, HIGH);
  delay(showTime);
  digitalWrite(ledTypePort1, LOW);
  digitalWrite(ledTypePort2, LOW);
  digitalWrite(ledTypePort3, LOW);
}
void offLed(){
  digitalWrite(RGBRedPin, HIGH);
  digitalWrite(RGBGreenPin, HIGH);
  digitalWrite(RGBRedPin, HIGH);
  digitalWrite(RGBRedPin, LOW);
  digitalWrite(RGBGreenPin, LOW);
  digitalWrite(RGBRedPin, LOW);
  delay(limitTime); 
}


void loop() {
  // if sum time is less than 15 seconds
  // set time off = 5000;

  int sumTime = showtime1 * 5 + showtime2* 5 + showtime3 * 5;
  if(sumTime > limitTime){
    offLed();
  }else{
    singleLed(showtime1, RGBRedPin ); // Display Red  
    singleLed(showtime1, RGBGreenPin ); // Display Green
    singleLed(showtime1, RGBRedPin ); // Display Red  
   singleLed(showtime1, RGBGreenPin ); // Displa Green
      singleLed(showtime1, RGBRedPin ); // Display Red  
    singleLed(showtime2, RGBBluePin ); // Display Blue
    singleLed(showtime2, RGBGreenPin ); // Display Green
    singleLed(showtime2, RGBRedPin ); // Display Red  
    singleLed(showtime2, RGBBluePin ); // Display BBlue
    singleLed(showtime2, RGBGreenPin ); // Displa Green

    singleLed(showtime3, RGBRedPin ); // Display Red  
    singleLed(showtime3, RGBBluePin ); // Display Blue
    singleLed(showtime3, RGBGreenPin ); // Display Green
     singleLed(showtime3, RGBBluePin ); // Display Blue
    singleLed(showtime3, RGBGreenPin ); // Display Green

  }


}