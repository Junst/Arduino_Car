int distance;

int triggerPin = 12;
int echoPin = 11;
int led =8;

void setup(){
    Serial.begin(9600);
    pinMode(triggerPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(led, OUTPUT);
}
 
void loop() {
  long duration, inches, cm;

    digitalWrite (triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite (triggerPin, LOW);

    distance = pulseIn(echoPin, HIGH) / 50;

    Serial.println("Distanc(cm) = " + String(distance));
    delay(100);


    if(distance <=10){
        digitalWrite(led,HIGH);
        delay(10);
        digitalWrite(led, LOW);        
     }
     else{
         digitalWrite(led,LOW);
     }

}
