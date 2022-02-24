//Tanya Pachkalov 
//level 4 - week 4
//Oct 13,2021


int lightPin=A1;//the light plug inA1
int RGBredPin=13;
int RGBbluePin=12;
int RGBorange=11;
int RGBgreenPin=10;
int data=0; //store the data from the sensor

void setup(){
 Serial.begin(9600);
  pinMode(RGBredPin,OUTPUT);
  pinMode(RGBbluePin,OUTPUT);
  pinMode(RGBorange,OUTPUT);
  pinMode(RGBgreenPin,OUTPUT);
  
}

void loop(){//loops run forever
data=analogRead(lightPin);
  data=map(data,0,1023,0,24);
  Serial.print("light value=");
  Serial.println(data);
  delay(10);
  
  if (data<1){
  digitalWrite(RGBredPin, LOW); 
  digitalWrite(RGBorange, LOW); 
  digitalWrite(RGBbluePin, LOW);
  digitalWrite(RGBgreenPin, LOW);
	delay(750);
  }
  if (data>2){
  digitalWrite(RGBredPin, HIGH); 
  digitalWrite(RGBorange, LOW); 
  digitalWrite(RGBbluePin, LOW);
  digitalWrite(RGBgreenPin, LOW);
	delay(750);
  }
    if (data>4){
  digitalWrite(RGBredPin, HIGH); 
  digitalWrite(RGBorange, LOW); 
  digitalWrite(RGBbluePin, HIGH);
  digitalWrite(RGBgreenPin, LOW);
	delay(750);
  }
  
   if (data>6){
  digitalWrite(RGBredPin, HIGH); 
  digitalWrite(RGBorange, HIGH); 
  digitalWrite(RGBbluePin, HIGH);
  digitalWrite(RGBgreenPin, LOW);
	delay(750);
  }
     if (data>8){
  digitalWrite(RGBredPin, HIGH); 
  digitalWrite(RGBorange, HIGH); 
  digitalWrite(RGBbluePin, HIGH);
  digitalWrite(RGBgreenPin, HIGH);
	delay(750);
  }
    if (data >12 ){ // if it is more than21 % and less then 25%
//all of them light up
  digitalWrite(RGBredPin, HIGH); 
  digitalWrite(RGBorange, HIGH); 
  digitalWrite(RGBbluePin, HIGH);
  digitalWrite(RGBgreenPin, HIGH);

  
}
  

}





