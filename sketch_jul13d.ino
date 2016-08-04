#include <Servo.h>
Servo myservo;




/*
 Fading

 This example shows how to fade an LED using the analogWrite() function.

 The circuit:
 * LED attached from digital pin 9 to ground.

 Created 1 Nov 2008
 Bdey David A. Mellis
 modified 30 Aug 2011
 By Tom Igoe

 http://www.arduino.cc/en/Tutorial/Fading

 This example code is in the public domain.

 */

int pin= 9;
int pos = 0;
int fadeAmount = 5;
//int ledPin = 9;    // LED connected to digital pin 9

void setup() {
  myservo.attach(pin);
  // nothing happens in setup
}

void loop() {
  myservo.write(pos);
  delay(15);
  pos= pos + fadeAmount;
  if(pos < 0 || pos >180){
    fadeAmount--;
  }
  // fade in from min to max in increments of 5 points:
 /* for (int fadeValue ; fadeValue <= 255; fadeValue += 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }

  // fade out from max to min in increments of 5 points:
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    // sets the value (range from 0 to 255):
    analogWrite(ledPin, fadeValue);
    // wait for 30 milliseconds to see the dimming effect
    delay(30);
  }*/
}


