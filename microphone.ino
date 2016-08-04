int sensorPin = A0; // select the input pin for the potentiometer
int ledPin = 13; // select the pin for the LED
int sensorValue = 0; // variable to store the value coming from the sensor
int brightness =0;
void setup () 
{
  pinMode (ledPin, OUTPUT);
  Serial.begin (9600);
}
 
void loop () 
{
  sensorValue = analogRead (sensorPin);
  brightness = map(sensorValue, 38,60, 0, 255);
  brightness = constrain(brightness, 0, 255);
  analogWrite(ledPin, brightness);

  //Serial.println (sensorValue, DEC);
  //Serial.print("\nbrightness is ");
  //Serial.println (brightness, DEC);
}
