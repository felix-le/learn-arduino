// Viet Anh Le
// March 13rd
// 8.2

#include <LiquidCrystal.h>
//Initialise the Serial LCD.
LiquidCrystal lcd( 12,11,5,4,3,2); //These pin numbers are hard coded in on the serial backpack
void setup()
{
lcd.begin (16,2); //Initialize the LCD.
}

void loop() {
  
  for(int i = -2 ; i  <12; i++ ) 
  {
    if (i==0){
      lcd.setCursor(i,0);
      lcd.print("Viet Anh Le");
      delay(500);
      lcd.clear();
  
  }
  else {
      lcd.setCursor(i,1);
      lcd.print("Viet Anh Le");
      delay(500);
      lcd.clear();
 
  }
  }
}
 