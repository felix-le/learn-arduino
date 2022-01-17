// C++ code
// Viet Anh Le
// Date: Jan 16th 2022
// Description: Lab 1 - level 3

// Declare variables

// LED & port
int blueLED = 8;
int redLED = 13;

// Times
int dotTime = 100;
int dashTime = 1000;
int offTime = 500;

// Show one time function 

void showOneTime(int time, int ledTypePort){
	digitalWrite(ledTypePort, HIGH);
    delay(time);
    digitalWrite(ledTypePort, LOW);
    delay(offTime);
}


void setup()
{
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
}

void loop()
{
  // Letter T: dash
  showOneTime(dashTime, redLED);
  
  // Letter P: dot dash dash dot
  showOneTime(dotTime, redLED);
  showOneTime(dashTime, blueLED);
  showOneTime(dashTime, redLED);
  showOneTime(dotTime, blueLED);

}