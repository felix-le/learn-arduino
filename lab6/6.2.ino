// Viet Anh Le (Felix)
// Date: Feb 22 2022
// Description: lab 6.2


int btn1 = 2;
int Red=9;
int Green = 10;
int Blue = 11;
int Rotation = A0;
int count = 0;
int data = 0;


void setup()
{
  Serial.begin(9600);
  pinMode(Red, OUTPUT);
  
   pinMode(Green, OUTPUT);
   pinMode(Blue, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(Rotation, INPUT);
}

void loop()
{
 	data = analogRead(Rotation);
  Serial.print("Rotation value =");
  Serial.println(data);
  
  analogWrite(Green,data);
  
}