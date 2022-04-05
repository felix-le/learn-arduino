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

// BEGIN happy birthday

int speakerPin = 10;

 int length = 28; // the number of notes

 char notes[] = "GGAGcB GGAGdc GGxecBA yyecdc";

 int beats[] = {
   2,
   2,
   8,
   8,
   8,
   16,
   1,
   2,
   2,
   8,
   8,
   8,
   16,
   1,
   2,
   2,
   8,
   8,
   8,
   8,
   16,
   1,
   2,
   2,
   8,
   8,
   8,
   16
 };

 int tempo = 150;

 void playTone(int tone, int duration) {

   for  (long i = 0; i < duration * 1000L; i += tone * 2) {

     digitalWrite(speakerPin, HIGH);

     delayMicroseconds(tone);

     digitalWrite(speakerPin, LOW);

     delayMicroseconds(tone);

   }

 }

 void playNote(char note, int duration) {

   char names[] = {
     'C',
     'D',
     'E',
     'F',
     'G',
     'A',
     'B',

     'c',
     'd',
     'e',
     'f',
     'g',
     'a',
     'b',

     'x',
     'y'
   };

   int tones[] = {
     1915,
     1700,
     1519,
     1432,
     1275,
     1136,
     1014,

     956,
     834,
     765,
     593,
     468,
     346,
     224,

     655,
     715
   };

   int SPEE = 5;

   // play the tone corresponding to the note name

   for (int i = 0; i < 17; i++) {

     if (names[i] == note) {

       int newduration = duration / SPEE;

       playTone(tones[i], newduration);

     }

   }

 }

void playSong (char *notes, int *beats, int length, int tempo) {

  for (int i = 0; i < length; i++) {

      if (notes[i] == ' ') {

       delay(beats[i] * tempo); // rest

     } else {

       playNote(notes[i], beats[i] * tempo);

     }

     // pause between notes

     delay(tempo);

  }
}



// END happy birthday



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
  pinMode(speakerPin, OUTPUT); // speaker
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
	
  if(age == 0 && userName!= NULL){
  	  for (int i = -60 ; i  <12; i++) {
      	lcd.setCursor(i, 1);
        lcd.print("Please use Rotation to show your age");
        delay(100);
        lcd.clear();
      }
  } else if (age != 0 && userName!= NULL){
  	 // Have userName
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(userName);
    lcd.setCursor(0, 1);
    lcd.print(age);
     playSong(notes, beats, length, tempo);	
    delay(500);
  }

}