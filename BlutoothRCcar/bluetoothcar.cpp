#include <SoftwareSerial.h>

#define enA 5
#define in1 6
#define in2 7
#define in3 8
#define in4 9
#define enB 10
#define BT_RXD 2
#define BT_TXD 3
#define ledPin 12

double SPEED1 = 0;
double SPEED2 = 128;
double initialSpdL = 180;
double initialSpdR = 180;

double speedL;
double speedR;

SoftwareSerial bluetooth(BT_RXD, BT_TXD);

enum lastPatternEnum
{
    FRONT,
    LEFT,
    RIGHT
};

lastPatternEnum lastPattern = FRONT;

void setup()
{
    Serial.begin(9600);
    bluetooth.begin(9600);
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);

    pinMode(ledPin,OUTPUT);
    digitalWrite(ledPin,LOW);
   
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}

void leftFront() {
     digitalWrite(in1, HIGH);
     digitalWrite(in2, LOW);
}

void leftBack() {
     digitalWrite(in1, LOW);
     digitalWrite(in2, HIGH);
}

void rightFront() {
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

void rightBack() {
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

int state = 0;
int readLength = 0;
int readStat = 0;
int readNumber = 0;
int readSpeed = 0;
int readX = 0;
int readY = 0;

void loop()
{
    if (bluetooth.available()) {
        // Serial.print(bluetooth.read());
        int readNumber=bluetooth.read();

        if (readLength == 0) {
            if (readNumber == '1') {
                readStat = 1;
            } else if (readNumber == '2') {
                readStat = 2;
            }
        } else if (readLength == 1) {
            if (readStat == 1) {
                readX = readNumber;
            } else if (readStat == 2) {
                readSpeed = readNumber;
            }
        } else if (readLength == 2) {
            readY = readNumber;
        }

        if (readNumber > -1) {
            readLength++;
        }

        if (readLength == 2 && readStat == 2) {
                    Serial.print(readStat);
        Serial.print(" ");
        Serial.print(readX);
        Serial.print(" ");
        Serial.println(readY);
            readLength = 0;
        }
        if (readLength > 2) {
                    Serial.print(readStat);
        Serial.print(" ");
        Serial.print(readX);
        Serial.print(" ");
        Serial.println(readY);
            readLength = 0;
        }

    }

    if(Serial.available()){
        bluetooth.write(Serial.read());
    }

/* if(state=='0'){
    digitalWrite(ledPin,LOW);
    Serial.println("LED:OFF");
    state=1;
}
else if(state == '1'){
    digitalWrite(ledPin, HIGH);
    Serial.println("LED:ON");;
    state=0;
} */

    speedL = initialSpdL;
    speedR = initialSpdR;

    leftFront();
    rightFront();

    analogWrite(enA, speedR);
    analogWrite(enB, speedL);

    delay(1000);

    leftBack();
    rightBack();

    analogWrite(enA, speedR);
    analogWrite(enB, speedL);

    delay(1000);
}