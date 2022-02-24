// Viet Anh Le (Felix)
// Date: Feb 6 2022
// Description: lab 4 - level 2
 
int lightPin = A1; //The light sensor is plugged into pin A1 of the Arduino.
int data; //This will store the data from the sensor.
int RGBredPin = 9; // red
int RGBgreenPin =10 ; // green
int RGBbluePin= 11;//blue

int potValue; // variable used to store the value coming from the sensor


void setup() {
  //The Setup function runs once.
Serial.begin(9600);
 pinMode(RGBredPin, OUTPUT); // red LED is as an output
 pinMode(RGBgreenPin, OUTPUT); // green LED is as an output
 pinMode(RGBbluePin, OUTPUT);
}


    
void loop() {
 potValue = analogRead(lightPin); // read the value from the potentiometer and assign the name potValue
 data = map(potValue, 0, 1023, 0, 100); // convert potentiometer reading to a percentage
Serial.print("Light value =");
Serial.println(data); //Print the data to the serial port.
delay(1000); 
 if (data < 20) { //if the percentage is less than 10%...
 digitalWrite(RGBredPin, HIGH); // turn the red LED on
   delay(1000); 
 digitalWrite(RGBredPin, LOW); 
   
 } 
 
 else if (data >=21 && data <40){ // if it is more than 21% and less then 40%
//show cyan
//Display Cyan (Blue + Green)
digitalWrite(RGBbluePin, HIGH); //Turn on BLUE
digitalWrite(RGBgreenPin, HIGH); //Turn on GREEN
   delay(1000); 
digitalWrite(RGBbluePin, LOW); //Turn of BLUE
digitalWrite(RGBgreenPin, LOW); //Turn off GREEN

}    
 else if (data >=41 && data <50){ // if it is more than 41% and less then 50%
//show blue
digitalWrite(RGBbluePin, HIGH); //Turn on RED
   delay(1000); 
digitalWrite(RGBbluePin, LOW); //Turn off Red

}          

}