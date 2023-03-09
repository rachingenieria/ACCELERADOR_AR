const int Sensor1Pin = 2;     // the number of the pushbutton pin
const int Sensor2Pin =  12;      // the number of the LED pin

int Sensor1State;
int Sensor2State;

void setup() {
  Serial.begin(9600);
  pinMode(Sensor1Pin, INPUT);
  pinMode(Sensor2Pin, INPUT);
}

void loop() {
  
  Sensor1State = digitalRead(Sensor1Pin);
  Sensor2State = digitalRead(Sensor2Pin);
  Serial.print(Sensor1State);
  Serial.print(',');
  Serial.println(Sensor2State);
}
