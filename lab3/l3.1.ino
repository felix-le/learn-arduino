

int rotationPin = A0; //The rotation sensor is plugged into pin A0 of the Arduino.
int data=0;           //Used to store data from sensor.
void setup() { //The Setup function runs once.
Serial.begin(9600); //This will enable the Arduino to send data to the Serial
//monitor.
pinMode(rotationPin,INPUT);
}
void loop() { //The loop function runs forever.
data = analogRead(rotationPin);  //Read the value from the light sensor and store it
//in the lightData variable.
Serial.print("Rotation value =");
Serial.println(data);  //Print the data to the serial port.
delay(1000);           //Wait 1 second (1000mS) before running again.
}