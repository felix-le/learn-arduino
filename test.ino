// Viet Anh Le
// March 13rd
// 8.4
#include <LiquidCrystal.h>

LiquidCrystal lcd( 12,11,5,4,3,2);//lcd pins

int tmp = 0;

int buttonYes = 7;//button #1

int buttonNo = 6;//button #2

int flag1 = 0,flag2 = 0;

int yes = 0,no = 0;//for the button option for yes or no

int arr[5] = {0,0,0,0,0};//5 questions

String s;

void takeAns(){

        if(buttonYes == HIGH){//if button is  pressed then :

		flag1 = 1;

        delay(20);

      }

  if(buttonYes == LOW && flag1 == 1){ //if its button yes (button number 1)

        arr[tmp] = 1;

        tmp++;

    	flag1 =0;

  }

  if(buttonNo == HIGH){//button pressed

        flag2 = 1;

        delay(20);

      }

  
  if(buttonNo == LOW && flag2 == 1){

        arr[tmp] = 0;

        tmp++;

    	flag2 = 0;

  }

  

}
//lets count if arr is 1 then yes if 0 then no


void takeStatis(){

  for(int i = 0;i < 5;i++){

    if(arr[i] == 1){yes++;}

    if(arr[i] == 0){no++;}

  }

}

void setup(){

lcd.begin (16,2);

pinMode(7,INPUT);

pinMode(6,INPUT);

}

void loop() { //buttons

   buttonYes = digitalRead(7); 

   buttonNo = digitalRead(6);  

  switch(tmp){

    case (0):
//q1
      lcd.setCursor(0,0);

      lcd.print("Do you Like The course?");

      lcd.setCursor(0,1);

      lcd.print("Press YES or NO");

      delay(100);

      takeAns();

    break;

    case(1)://q2

      lcd.setCursor(0,0);

      lcd.print("do you want sushi for dinner?");

      lcd.setCursor(0,1);

      lcd.print("Press YES or NO");

      delay(100);

      takeAns();

    break;
//q3
    case(2):

      lcd.setCursor(0,0);

      lcd.print("Do you like shoppin?");

      lcd.setCursor(0,1);

      lcd.print("Press YES or NO");

      delay(100);

      takeAns();

    break;//q4

      case(3):

      lcd.setCursor(0,0);

      lcd.print("Do you like christmas? ");

      lcd.setCursor(1,1);

      lcd.print("Press YES or NO");

      delay(100);

      takeAns();

    break;

      case(4)://q5

      lcd.setCursor(0,0);

      lcd.print("I am out of ideas what to ask");

      lcd.setCursor(0,1);

    lcd.print(",simply press yes or not");

      lcd.setCursor(2,1);
      lcd.print("Press YES or NO");

      delay(100);

      takeAns();

      break;
//
      case(5):
    //lets do the statistics how many countts

      lcd.setCursor(0,0);

      lcd.print("Statistics");

      lcd.setCursor(0,1);

      takeStatis();

      s = "YES = " + String(yes) + ", NO = " + String(no);

      lcd.print(s);

      delay(5000);

      takeAns();

      tmp++;

    break;

    case(6):

      lcd.setCursor(0,0);

      lcd.print("RESET");//reset

      lcd.setCursor(0,1);

      lcd.print("RESET");

      delay(500);

      tmp = 0;

      break;

}
}