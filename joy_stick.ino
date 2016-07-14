// Module KY023
// For more info see http://tkkrlab.nl/wiki/Arduino_KY-023_XY-axis_joystick_module
int JoyStick_X = A0; // x
int JoyStick_Y = A1; // y
int JoyStick_Z = 3; // key

int mapped_x = 0;
int mapped_y = 0;

//servo stuffs
#include <Servo.h>

Servo myservo;
Servo myservo1;// create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0; 

void setup ()
{
  pinMode (JoyStick_X, INPUT);
  pinMode (JoyStick_Y, INPUT);
  pinMode (JoyStick_Z, INPUT_PULLUP);
  Serial.begin (9600); // 9600 bps
  myservo.attach(9); 
   myservo1.attach(10); 
}
void loop ()
{
  int x, y, z;
  x = analogRead (JoyStick_X);
  y = analogRead (JoyStick_Y);
  z = digitalRead (JoyStick_Z);
  Serial.print (x, DEC);
  Serial.print (",");
  Serial.print (y, DEC);
  Serial.print (",");
  Serial.print (z, DEC);
  

/*
  if(z==0){
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myservo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }*/
  
    pos = map(y,0,1024,180,0);
    myservo1.write(x/5.69);              // tell servo to go to position in variable 'pos'
                           // waits 15ms for the servo to reach the position
  
   // myservo.write(y/5.69);              // tell servo to go to position in variable 'pos'
   myservo.write(pos);
                           // waits 15ms for the servo to reach the position
  
  
  Serial.print (",");
  Serial.println (pos, DEC);
  //

}
