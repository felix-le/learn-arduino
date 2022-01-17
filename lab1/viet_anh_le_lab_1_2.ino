// C++ code
// Viet Anh Le 
// Date: Jan 16th 2022
// Description: lab 1 level 2

// Declaring Variable
int dotTime = 100;
int dashTime = 1000;
int offTime = 500;

// Show one time function
void showOneTime(int time){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(time); // Wait for time millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(offTime); // Wait for time millisecond(s)
}

void dot(){
	showOneTime(dotTime);
}

void dash(){
	showOneTime(dashTime);
}

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
	 level2();
}

void level2(){
  // B: dash dot dot dot
  dash();
  dot();
  dot();
  dot();
  delay(2000);
  // Z: dash dash dot dot
  dash();
  dash();
  dot();
  dot();
  
}