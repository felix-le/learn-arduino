// C++ code
#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //lcd pins

// get interactive Time
int tmp = 0;
int arr[2] = {
  0,
  0
};

int InputByte;
char character;
int delayTime(300);
int delayShowUp(2000);

// Check onChange
String inputName = "";

// Final variable
String userName = "";

// get age
int age;
int Rotation = A0;

void setup() {
  Serial.begin(9600);
  pinMode(Rotation, INPUT);
  lcd.begin(16, 2); //Initialize the LCD.
}

void loop() {
  //===== get age
  age = analogRead(Rotation);
  age = map(age, 0, 1023, 0, 100);
  if (age > 0) {
    Serial.println(age);
    delay(delayTime);
  }

  //===== get name
  // whenever user input char from keyboard
  while (Serial.available()) {
    character = Serial.read();
    inputName.concat(character);
    delay(delayTime);
  }
  //if character end with ] =>> get the user's name
  if (character == ']') {
    // reset inputName value
    if (inputName != NULL) {
      userName = inputName;
      inputName = "";
      //Serial.println(userName);
      delay(delayTime);
    }
  }
  // if userName has value print it
  if (userName == NULL) {
    // Run the question:
    for (int i = -60 ; i  <12; i++) {
      lcd.setCursor(i, 1);
        lcd.print("Please input your name with the End is ]");
        delay(100);
        lcd.clear();
    	}
    
  	}
	
  if(age == NULL && userName!= NULL){
  	  for (int i = -60 ; i  <12; i++) {
      	lcd.setCursor(i, 1);
        lcd.print("Please use Rotation to show your age");
        delay(100);
        lcd.clear();
      }
  } else {
  	 // Have userName
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(userName);
    lcd.setCursor(0, 1);
    lcd.print(age);
    delay(500);
  }

}