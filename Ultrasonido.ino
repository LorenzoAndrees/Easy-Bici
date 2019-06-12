const int pingPin = 7; //back
const int pingPin2 = 6; //left
const int pingPin3 = 5; //right
const int ledPin=12; //led
float time_now=0;
bool side;
double duration, duration2, distance, m1, m2, vRelativa, vBici, vAuto;
void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  side=false;
}

void loop() {
  if(side==true){
  // establish variables for duration of the ping
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delay2();
    digitalWrite(pingPin, HIGH);
    delay5();
    digitalWrite(pingPin, LOW);

    // The same pin is used to read the signal from the PING))): a HIGH pulse
    // whose duration is the time (in microseconds) from the sending of the ping
    // to the reception of its echo off of an object.
    pinMode(pingPin, INPUT);
    duration = pulseIn(pingPin, HIGH);
    
    // convert the time into a distance
    m1 = microsecondsToCentimeters(duration)/100.0;

    delay100();

    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delay2();
    digitalWrite(pingPin, HIGH);
    delay5();
    digitalWrite(pingPin, LOW);
  
    pinMode(pingPin, INPUT);
    duration = pulseIn(pingPin, HIGH);

    pinMode(pingPin2, OUTPUT);
    digitalWrite(pingPin2, LOW);
    delay2();
    digitalWrite(pingPin2, HIGH);
    delay5();
    digitalWrite(pingPin2, LOW);
    
    pinMode(pingPin2, INPUT);
    duration2 = pulseIn(pingPin2, HIGH);
    
    m2 = microsecondsToCentimeters(duration)/100.0;
    distance = microsecondsToCentimeters(duration2)/100.0;
    Serial.print(distance);
    Serial.print(": Distancia hacia la izq");
    Serial.println();
    vRelativa = (m2-m1)*3,6;
    Serial.print(vRelativa);
    Serial.print(" km/h");
    Serial.println();

    if(abs(vRelativa) >= 10.0 & m2<=3.0){
      Serial.print("ALERTA EN LA PARTE TRASERA");
      Serial.println();
      digitalWrite(ledPin, HIGH);
      delay500();
      digitalWrite(ledPin, LOW);
      //VERIFICAR SI ES AUTO
      //ALERTAR
    }
    
    if(distance<=1.5){
      Serial.print("ALERTA EN LA PARTE IZQUIERDA");
      Serial.println();
      digitalWrite(ledPin, HIGH);
      delay100();
      digitalWrite(ledPin, LOW);
    } 
  }
  else if(side==false){
    
  // establish variables for duration of the ping
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delay2();
    digitalWrite(pingPin, HIGH);
    delay5();
    digitalWrite(pingPin, LOW);

    // The same pin is used to read the signal from the PING))): a HIGH pulse
    // whose duration is the time (in microseconds) from the sending of the ping
    // to the reception of its echo off of an object.
    pinMode(pingPin, INPUT);
    duration = pulseIn(pingPin, HIGH);
    
    // convert the time into a distance
    m1 = microsecondsToCentimeters(duration)/100.0;

    delay100();

    pinMode(pingPin, OUTPUT);
    digitalWrite(pingPin, LOW);
    delay2();
    digitalWrite(pingPin, HIGH);
    delay5();
    digitalWrite(pingPin, LOW);
  
    pinMode(pingPin, INPUT);
    duration = pulseIn(pingPin, HIGH);

    pinMode(pingPin3, OUTPUT);
    digitalWrite(pingPin3, LOW);
    delay2();
    digitalWrite(pingPin3, HIGH);
    delay5();
    digitalWrite(pingPin3, LOW);
    
    pinMode(pingPin3, INPUT);
    duration2 = pulseIn(pingPin3, HIGH);
    
    m2 = microsecondsToCentimeters(duration)/100.0;
    distance = microsecondsToCentimeters(duration2)/100.0;
    Serial.print(distance);
    Serial.print(": Distancia hacia la der");
    Serial.println();
    
    vRelativa = (m2-m1)*3,6;
    Serial.print(vRelativa);
    Serial.print(" km/h");
    Serial.println();

    if(abs(vRelativa) >= 10.0 & m2<=3.0){
      Serial.print("ALERTA EN LA PARTE TRASERA");
      Serial.println();
      digitalWrite(ledPin, HIGH);
      delay500();
      digitalWrite(ledPin, LOW);
      //VERIFICAR SI ES AUTO
      //ALERTAR
    }
    
    if(distance<=1.5){
      Serial.print("ALERTA EN LA PARTE DERECHA");
      Serial.println();
      digitalWrite(ledPin, HIGH);
      delay100();
      digitalWrite(ledPin, LOW);
    }
  }
}
long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}

void delay100(){
  time_now = millis();
  while(millis() < time_now + 100){
    //wait approx. [period] ms
    }
}
void delay500(){
  time_now = millis();
  while(millis() < time_now + 500){
    //wait approx. [period] ms
    }
}
void delay1000(){
  time_now = millis();
  while(millis() < time_now + 1000){
    //wait approx. [period] ms
    }
}
void delay2(){
  time_now = millis();
  while(millis() < time_now + 2){
    //wait approx. [period] ms
    }
}
void delay5(){
  time_now = millis();
  while(millis() < time_now + 5){
    //wait approx. [period] ms
    }
}
