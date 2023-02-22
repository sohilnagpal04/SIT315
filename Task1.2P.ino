const byte led_pin = 3;
const byte interrupt_pin = 2;
volatile byte state = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(led_pin,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(interrupt_pin),interrupt_routine,CHANGE);
}

void loop() {

  
}

void interrupt_routine(){
  state = digitalRead(interrupt_pin);
  digitalWrite(led_pin,state);
  if (state)
    Serial.println("MOTION DETECTED");
  else
    Serial.println("No Motion Detected");
}
