int estadoActual1=0;
int estadoActual2=0;
int estadoUltimo=0;
int contador=0;
float radioEnCm=0.0;   //ingresar radio de la rueda en cm
float pi=3.1416;
float perimetroRueda=2*pi*(radioEnCm/100);  //Calcula Perimetro en metros
float distRecorrida=0;
float distKM=0;
int tiempo1=0;
int tiempo2=0;
int tiempo3=0;
int tiempo5=0;
int tiempo6=0;
float tiempo4=0;
float velocidad=0;
int time_now=0;
int periodo = 1000;
//int contador2=0;
//int contador3=0;

void setup(){
        pinMode(4,OUTPUT);
        pinMode(3,INPUT);
        Serial.begin(9600);
}

void loop(){
        estadoActual1=digitalRead(3);
        delay10();
        estadoActual2=digitalRead(3);
//Si los estados no son iguales, el sketch no hace gran cosa
        if (estadoActual1 == estadoActual2) {
              if (estadoActual1 != estadoUltimo){
                    if (estadoActual1 == HIGH) {
                        contador = contador + 1;
                        //contador2=contador2 + 1;
                        //contador3=contador3 + 1;
                        distancia();
                        VEL();
                    }
              }
        }
        estadoUltimo= estadoActual1;
              
        if (contador%2 == 0 ) {
              digitalWrite(4, LOW);
        }
        else {
              digitalWrite(4, HIGH);
        }
}


void distancia(){ 
                        if (Serial.available()){
                          radioEnCm = Serial.read();
                        }

                        //float perimetroRueda = 0.0;
                        float perimetroRueda=2*pi*(radioEnCm/100);  //Calcula Perimetro en metros
                        
                        distRecorrida=perimetroRueda*contador;
                        distKM=distRecorrida/1000;
                        //if (contador2>4){
                        if(distRecorrida<=999){
                          Serial.print("Distancia :");
                                Serial.print(distRecorrida);
                                Serial.print(" M");
                                Serial.println("*");
                                //contador2=0;
                                }
                                
                        
                        else {
                                Serial.print("Distancia :");
                                Serial.print(distKM);
                                Serial.print(" KM");
                                Serial.println("*");
                                //contador2=0;
                        }
                       // }
                        }



void VEL(){
        if (Serial.available()){
          radioEnCm = Serial.read();
        }

        //float perimetroRueda = 0.0;
        float perimetroRueda=2*pi*(radioEnCm/100);  //Calcula Perimetro en metros
  
        if (contador%2 == 0 ) {
              tiempo1=millis();
        }
        else {
              tiempo2=millis();
        }
        tiempo3=abs(tiempo2-tiempo1); //hay que pasar el tiempo a hrs
        tiempo4=(((tiempo3/1000.0)/60.0)/60.0);
        velocidad=((perimetroRueda/1000)/tiempo4);
       // if(contador3>4){       
                                Serial.print("Velocidad :");
                                Serial.print(velocidad);
                                Serial.println(" M/S *");
                                //contador3=0;
        //}
}

void delay10(){
  time_now = millis();
  while(millis() < time_now + 10){
    //espera el tiempo aprox de 10 ms
  }
}
