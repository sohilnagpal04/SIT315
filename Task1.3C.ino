const byte led_pin = 4;
const byte interrupt_pin1 = 2;
const byte interrupt_pin2 = 3;
volatile byte state1 = LOW;
volatile byte state2 = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(led_pin,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin1),interrupt_routine1,CHANGE);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin2),interrupt_routine2,CHANGE);
}

void loop() {
}

void interrupt_routine1(){
  state1 = digitalRead(interrupt_pin1);
  digitalWrite(led_pin,state1);
  if (state1)
    Serial.println("MOTION DETECTED BY SENSOR 1");
  else
    Serial.println("No Motion Detected");
}

void interrupt_routine2(){
  state2 = digitalRead(interrupt_pin2);
  digitalWrite(led_pin,state2);
  if (state2)
    Serial.println("MOTION DETECTED BY SENSOR 2");
  else
    Serial.println("No Motion Detected");
}