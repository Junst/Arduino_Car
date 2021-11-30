int distance;

int triggerPin = 12;
int echoPin = 11;
int led =8;
int btn = 2;

void setup(){
    Serial.begin(9600);
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(led, OUTPUT);
    pinMode(btn, INPUT);
}

void loop() {
  long duration, inches, cm;

    digitalWrite (triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite (triggerPin, LOW);
    
    
    distance = pulseIn(echoPin, HIGH) / 50;
   

    if ((digitalRead(btn))>0) {
      digitalWrite (triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite (triggerPin, LOW);
      Serial.println("Distance(cm) = " + String(distance));
      delay(20);
      Serial.println("Distance(cm) = " + String(distance));
      delay(20);
      Serial.println("Distance(cm) = " + String(distance));
      delay(20);
      Serial.println("Distance(cm) = " + String(distance));
      delay(20);
      Serial.println("Distance(cm) = " + String(distance));
      
      delay(100);
      }

    if(distance <=10){
        digitalWrite(led, HIGH);
        delay(10);
        digitalWrite(led, LOW);        
     }
     else{
         digitalWrite(led,LOW);
     }

}