int pirPin = 2;    
int ledPin = 3;   

void setup()
  
{
  Serial.begin(9600);
  pinMode(pirPin, INPUT);   
  pinMode(ledPin, OUTPUT);  
}

void loop()
{
  int pirState = digitalRead(pirPin);  

  if (pirState == HIGH) {   
    digitalWrite(ledPin, HIGH);  
    Serial.println("Motion Detected");
  } else {
    digitalWrite(ledPin, LOW);    
  }
  
  delay(100);   
}
