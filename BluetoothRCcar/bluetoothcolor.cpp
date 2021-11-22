#define ledPin 12
int state=0;

void setup(){
    pinMode(ledPin,OUTPUT);
    digitalWrite(ledPin,LOW);
    Serial.begin(9600);
}

void loop(){
    if(Serial.available()>0){
        state=Serial.read();
    }1

if(state=='0'){
    digitalWrite(ledPin,LOW);
    Serial.println("LED:OFF");
    state=1;
}
else if(state == '1'){
    digitalWrite(ledPin, HIGH);
    Serial.println("LED:ON");;
    state=0;
}
}