// Viet Anh Le (Felix)
// Date: Jan 16th 2022
// Description: lab 1 - level 1

// declaring variable
int blueLED = 13; // Blue led connected to port 13
int quick = 100; // quick time
int slow = 1000; // slow time



void setup()
{
	pinMode(blueLED, OUTPUT); 
}

void loop() 
// Arduino make loop 

{
  // Slow Three times
  
  for(int i = 0; i < 3; i ++){
   	digitalWrite(blueLED, HIGH);
    delay(slow); 
    digitalWrite(blueLED, LOW);
    delay(slow); 
  }
 
  // ======

  // Quick Three Times
  for(int i = 0; i < 3; i ++){
   	digitalWrite(blueLED, HIGH);
    delay(quick); 

    digitalWrite(blueLED, LOW);
    delay(quick);  
  }
}