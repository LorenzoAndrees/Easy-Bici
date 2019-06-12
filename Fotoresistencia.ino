int sensorPin = A0;
int ledPin = 8; 
int sensorValue = 0;

void setup() {
 pinMode(ledPin, OUTPUT);
 Serial.begin(9600);
}
void loop() {
 sensorValue = analogRead(sensorPin);
 delay(100);
 Serial.println(sensorValue);
}
