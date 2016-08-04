#include <Servo.h>

int led1 = 8;
int led2 = 13;
int pot = A3;

int SensorValue;

bool isLEDon = false;

Servo myServo;

int servo_pos=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  

 Serial.begin(9600);

 myServo.attach(7);
}

void loop() {
  //this is reading nthe sensor from pot
  SensorValue = analogRead(pot);
   Serial.print("SensorValue is \n");
  Serial.println(SensorValue);

  if(isLEDon == true){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    isLEDon = false;
  } else {
    digitalWrite(led2,HIGH);
    digitalWrite(led1,LOW);
    isLEDon = true;
  }

  servo_pos =map(SensorValue, 0, 1024, 0, 180);
  //delay(SensorValue);
  Serial.print("Servo pos is");
  Serial.println(servo_pos);
  myServo.write(servo_pos);
  //digitalWrite(led,HIGH);
  //int sensorReading = analogRead(analogPin);
  
 // int ledLevel = map(sensorReading,0,1023,0,255);
 // Serial.println(sensorReading);
 // Serial.println(ledLevel);
 // delay(500);
 // analogWrite(led,ledLevel);
}
