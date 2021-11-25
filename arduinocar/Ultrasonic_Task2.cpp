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

    for (int i = 0; i < 5; i++) {
    digitalWrite (triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite (triggerPin, LOW);

    distance = pulseIn(echoPin, HIGH) / 50;

    Serial.println("Distance(cm) = " + String(distance));
    delay(100);
    }

    Serial.println("---");

    delay(5000);



}