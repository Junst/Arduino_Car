#define enA 9
#define enB 10
int L = A0;
int M = A1;
int R = A2;

int in1 = 7;
int in2 = 6;
int in3 = 5;
int in4 = 4;

void setup() {
  pinMode(L, INPUT);
  pinMode(R, INPUT);
  pinMode(M, INPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}
void loop() {
  if (digitalRead(L) == HIGH && digitalRead(M) == HIGH && digitalRead(R) == HIGH) {
    forward();
  }
  if (digitalRead(L) == HIGH && digitalRead(M) == HIGH && digitalRead(R) == LOW) {
    forward();
  }
  if (digitalRead(L) == HIGH && digitalRead(M) == LOW && digitalRead(R) == HIGH) {
    forward();
  }
  if (digitalRead(L) == HIGH && digitalRead(M) == LOW && digitalRead(R) == LOW) {
    //좌회전
    Bleft();
  }
  if (digitalRead(L) == LOW && digitalRead(M) == HIGH && digitalRead(R) == HIGH) {
    //직진
    forward();
  }
  if (digitalRead(L) == LOW && digitalRead(M) == LOW && digitalRead(R) == HIGH) {
    //우회전
    Bright();
  }
  if (digitalRead(L) == LOW && digitalRead(M) == HIGH && digitalRead(R) == LOW) {
    forward();
  }
  if (digitalRead(L) == LOW && digitalRead(M) == LOW && digitalRead(R) == LOW) {
    
  }
}
void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 93);
  analogWrite(enB, 98);
}
void Bright() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  analogWrite(enA, 99);
  analogWrite(enB, 0);
}
void Bleft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 0);
  analogWrite(enB, 99);
}
