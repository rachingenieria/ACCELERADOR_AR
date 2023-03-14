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

static int motord, motori;

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
}

void loop() {
  
  Sensor1State = digitalRead(Sensor1Pin);
  Sensor2State = digitalRead(Sensor2Pin);

  
  //Serial.print(Sensor1State);
  //Serial.print(',');
  //Serial.println(Sensor2State);

  if(!Sensor1State)
  {

     digitalWrite(INDUCTORD_AINA,LOW);
     digitalWrite(INDUCTORD_AINB,HIGH);
     analogWrite(INDUCTORD_PWM,255);
     delay(40);
     digitalWrite(INDUCTORD_AINA,HIGH);
     digitalWrite(INDUCTORD_AINB,HIGH);
     analogWrite(INDUCTORD_PWM,0);
     delay(10);
     digitalWrite(INDUCTORD_AINA,LOW);
     digitalWrite(INDUCTORD_AINB,LOW);
     Serial.println("DERECHA");
     
  }

 if(!Sensor2State)
  {
 
     digitalWrite(INDUCTORI_AINA,LOW);
     digitalWrite(INDUCTORI_AINB,HIGH);
     analogWrite(INDUCTORI_PWM,255);
     delay(40);
     digitalWrite(INDUCTORI_AINA,HIGH);
     digitalWrite(INDUCTORI_AINB,HIGH);
     analogWrite(INDUCTORI_PWM,0);
     delay(10);
     digitalWrite(INDUCTORI_AINA,LOW);
     digitalWrite(INDUCTORI_AINB,LOW);
     Serial.println("IZQUIERDA");
   
     
  }
    
}
