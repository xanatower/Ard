//int sensorPin = A5;
int factor=1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
 factor = microphone_update();
 Serial.println(factor);
  

}

int microphone_update(){
  int sensorValue = analogRead (A5);
  int brightness = map(sensorValue, 1,255, 1, 5);
  brightness = constrain(brightness, 0, 255);
// Serial.println(brightness);
  //analogWrite(ledPin, brightness);
  return brightness;
}
