const int Sensor1Pin = 9;     // the number of the pushbutton pin
const int Sensor2Pin =  12;      // the number of the LED pin

#define INDUCTORD_AINA    4   
#define INDUCTORD_AINB    A0  
#define INDUCTORD_PWM     5 

#define INDUCTORI_AINA    7
#define INDUCTORI_AINB    11
#define INDUCTORI_PWM     6  
 

int Sensor1State;
int Sensor2State;

unsigned long tiempo1 = 0;
unsigned long tiempo2 = 0;
unsigned long tiempo_diferencia = 0;
unsigned long tiempo_activacion;


static int motord, motori;

int perimetro =  500; //milimetros, 50 centrimetros
int Bohina_efectiva =  20; //milimetros, 2.5 centrimetros
int relacion_distancia;

void setup() {
  Serial.begin(9600);
  
  pinMode(Sensor1Pin, INPUT);
  pinMode(Sensor2Pin, INPUT);
  
  digitalWrite(Sensor1Pin,HIGH);
  digitalWrite(Sensor2Pin,HIGH);
     

  pinMode(INDUCTORD_AINA, OUTPUT);
  pinMode(INDUCTORD_AINB, OUTPUT);
  pinMode(INDUCTORI_AINA, OUTPUT);
  pinMode(INDUCTORI_AINB, OUTPUT);

  pinMode(INDUCTORI_PWM, OUTPUT);
  pinMode(INDUCTORD_PWM, OUTPUT);
  
  analogWrite(INDUCTORI_PWM,0);
  analogWrite(INDUCTORD_PWM,0);

     digitalWrite(INDUCTORD_AINA,LOW);
     digitalWrite(INDUCTORD_AINB,LOW);
     
     digitalWrite(INDUCTORI_AINA,LOW);
     digitalWrite(INDUCTORI_AINB,LOW);
     
     analogWrite(INDUCTORD_PWM,0);
     analogWrite(INDUCTORI_PWM,0);

     relacion_distancia = perimetro/Bohina_efectiva;
}

void loop() {
  
  Sensor1State = digitalRead(Sensor1Pin);
  Sensor2State = digitalRead(Sensor2Pin);

  
  //Serial.print(Sensor1State);
  //Serial.print(',');
  //Serial.println(Sensor2State);

  if(!Sensor1State)
  {
     tiempo1 = millis();
     tiempo_diferencia = tiempo1 - tiempo2;
     tiempo_activacion = tiempo_diferencia / relacion_distancia;


     if(tiempo_activacion > 30)
      tiempo_activacion = 30;
     
     //if(tiempo_activacion > 20)
      delay(10);
      
     digitalWrite(INDUCTORD_AINA,LOW);
     digitalWrite(INDUCTORD_AINB,HIGH);
     analogWrite(INDUCTORD_PWM,255);
     delay(tiempo_activacion);
     //digitalWrite(INDUCTORD_AINA,HIGH);
     //digitalWrite(INDUCTORD_AINB,HIGH);
     //analogWrite(INDUCTORD_PWM,0);
     //delay(10);
     digitalWrite(INDUCTORD_AINA,LOW);
     digitalWrite(INDUCTORD_AINB,LOW);
     Serial.print("A :");
     Serial.print(tiempo_activacion);
     Serial.print(", :");
     Serial.println(tiempo_diferencia);
     delay(200);
     
  }

 if(!Sensor2State)
  {
     tiempo2 = millis();
     tiempo_diferencia = tiempo2 - tiempo1;
     tiempo_activacion = tiempo_diferencia / relacion_distancia;
     
     if(tiempo_activacion > 30)
        tiempo_activacion = 30;

     //if(tiempo_activacion > 20)
        delay(10);
     
     digitalWrite(INDUCTORI_AINA,HIGH);
     digitalWrite(INDUCTORI_AINB,LOW);
     analogWrite(INDUCTORI_PWM,250);
     delay(tiempo_activacion);
     //digitalWrite(INDUCTORI_AINA,HIGH);
     //digitalWrite(INDUCTORI_AINB,HIGH);
     //analogWrite(INDUCTORI_PWM,0);
     //delay(10);
     digitalWrite(INDUCTORI_AINA,LOW);
     digitalWrite(INDUCTORI_AINB,LOW);
     Serial.print("B :");
     Serial.print(tiempo_activacion);
     Serial.print(", :");
     Serial.println(tiempo_diferencia);
     delay(200);
   
     
  }
    
}
