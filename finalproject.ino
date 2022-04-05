// C++ code
#include <LiquidCrystal.h>

LiquidCrystal lcd( 12,11,5,4,3,2);//lcd pins

// get interactive Time

int tmp = 0;
int arr[2] = {0,0};

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
}

void loop() {
  //===== get age
  age = analogRead(Rotation);
  age = map(age, 0, 1023, 0,100);
  if(age > 0){
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
    if(inputName != NULL){
        userName = inputName;
          inputName= "";
          //Serial.println(userName);
          delay(delayTime);
    }
  }
 // if userName has value print it
  if(userName == NULL){
    Serial.println("Please input your name with the End is ]");
  
  }
  //TODO: if users inputed their name and show the name on LCD 
  if(userName != NULL) {
    Serial.println(userName);
    delay(delayShowUp);
  }
  

}