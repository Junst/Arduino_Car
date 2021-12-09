#include <NewPing.h>

int trigPin1 = A4;
int echoPin1 = A5;
int trigPin2 = A2;
int echoPin2 = A3;
int trigPin3 = A0;
int echoPin3 = A1;
int max_distance = 200;

int EN1 = 6;
int EN2 = 7;
int ENA = 5;  //왼쪽
int EN3 = 8;
int EN4 = 9;
int ENB = 10; //오른쪽
int Speed;

NewPing sonar[3] = {
  NewPing(trigPin1, echoPin1, max_distance),
  NewPing(trigPin2, echoPin2, max_distance),
  NewPing(trigPin3, echoPin3, max_distance),
};
void setup() {
  Serial.begin(9600);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(EN3, OUTPUT);
  pinMode(EN4, OUTPUT);
  pinMode(ENB, OUTPUT);
}

int k = 0;

void loop() {
  Serial.print("1 :");
  Serial.print(sonar[0].ping_cm());
  Serial.println(" cm");

  Serial.print("2 :");
  Serial.print(sonar[1].ping_cm());
  Serial.println(" cm");

  Serial.print("3 :");
  Serial.print(sonar[2].ping_cm());
  Serial.println(" cm");
  //delay (1000);

  // 거리측정
  int distance0 = sonar[0].ping_cm(); //왼쪽
  //delay (100);
  int distance1 = sonar[1].ping_cm(); //가운데
  //delay (100);
  int distance2 = sonar[2].ping_cm(); //오른쪽
  //delay (100);

  // 장애물 감지
  int D = 18.5;
  int m = 15;
  Speed = 200;

  if (distance2 <= 4) {
    TURN_LEFT(Speed);
    delay(200);
    GO_FRONT(Speed);
    delay(1000);
    TURN_RIGHT(Speed);
    delay(500 + ( k * 50xxxxxxxxxx));
    GO_FRONT(Speed);
    delay(1000);
    k++;
    if (k > 3) {
      GO_BACK(Speed);
      delay(1500); 
      TURN_RIGHT(Speed);
      delay(500);
      GO_FRONT(Speed);
    delay(1000);
    k=0;
    }
  } else {
    k = 0;
    if (distance0 > 10) {
      if (distance1 > 10) {
        GO_FRONT(Speed);
        delay(200);
        TURN_LEFT(Speed);
        delay(120);
      } else if (distance1 <= 10) {
        TURN_LEFT(Speed);
        delay(100);
      }
    } else if (distance0 <= 10) {
      if (distance1 > 10) {
        GO_FRONT(Speed);
        delay(300);
        TURN_RIGHT(Speed);
        delay(200);
      } else if (distance1 <= 10) {
        if (distance0 < distance1) {
          TURN_RIGHT(Speed);
          delay(100);
        } else {
          TURN_LEFT(Speed);
          delay(100);
        }
      }
    }

//    if (distance2 < 3) {
//      GO_BACK(Speed);
//    }
  }
  //
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, HIGH);
  digitalWrite(EN3, HIGH);
  digitalWrite(EN4, HIGH);
  delay(100);
  //  if (distance0 < 2 || distance1 < 2 || distance2 < 2) {
  //    GO_BACK(Speed);
  //    delay(100);
  //  }
  //
  //  if (distance1 > D) // 가운데 거리가 D보다 크면
  //   {
  //    if(distance0 < m && distance2 > m) // 왼쪽 거리가 m보다 작고 오른쪽 거리가 m보다 크면
  //    {
  //      GO_BACK(Speed); // 오른쪽으로 도세요
  //     }
  //    if(distance2 < m && distance0 > m) // 오른쪽 거리가 m보다 작고 왼쪽 거리가 m 보다 크면
  //    {
  //      TURN_LEFT(Speed); // 왼쪽으로 도세요
  //     }
  //    else if( distance0 < m && distance2 < m ) // 오른쪽 거리와 왼쪽거리가 m보다 작으면
  //    {
  //      GO_BACK(Speed); // 뒤로가세요
  //      delay(1000); // 1초동안
  //      TURN_LEFT(Speed); // 오른쪽으로 도세요
  //      delay(500); // 0.5초동안
  //    }
  //    else if (distance0 <= 3 || distance1 <= 3 || distance2 <= 3) {
  //      GO_BACK(Speed);
  //      delay(100);
  //      TURN_LEFT(Speed); // 오른쪽으로 도세요
  //      delay(500); // 0.5초동안
  //    }
  //
  //    else // 오른쪽 거리와 왼쪽거리가 m보다 크면
  //    {
  //      GO_FRONT(Speed); // 앞으로 가세요
  //     }
  //   }
  //
  //   else if(distance1 <= D) // 만약 가운데 거리가 D보다 작으면
  //   {
  //    if(distance0 < distance2) // 왼쪽 거리 < 오른쪽거리 라면
  //    {
  //      GO_BACK(Speed); // 오른쪽으로 도세요
  //     }
  //    if (distance0 > distance2) // 왼쪽거리 > 오른쪽거리 라면
  //    {
  //      TURN_LEFT(Speed); // 왼쪽으로 도세요
  //      delay(100); // 0.1초동안
  //     }
  //    else if ( distance1 <= 10) // 가운데 거리가 10보다 작다면
  //    {
  //      GO_BACK(Speed); // 뒤로가세요
  //      delay(1000); // 1초동안
  //      TURN_LEFT(Speed); // 오른쪽으로 도세요
  //      delay(1000); // 0.5초동안
  //
  //     }
  //    else
  //    {
  //      GO_BACK(Speed); // 뒤로가세요
  //      delay(100); // 0.1초동안
  //      TURN_LEFT(Speed); // 오른쪽으로 도세요
  //      delay(1500); // 0.5초동안
  //      }
  //   }
  //
}

void GO_FRONT(int Speed)
{
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, HIGH);
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, HIGH);
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed);
}

void GO_BACK(int Speed)
{
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, LOW);
  digitalWrite(EN3, HIGH);
  digitalWrite(EN4, LOW);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
}

void TURN_LEFT(int Speed)
{
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, HIGH);
  digitalWrite(EN3, HIGH);
  digitalWrite(EN4, LOW);
  //  digitalWrite(EN3,LOW);
  //  digitalWrite(EN4,HIGH);
  analogWrite(ENA, Speed - 20);
  analogWrite(ENB, Speed + 20);
}

void TURN_RIGHT(int Speed)
{
  //  digitalWrite(EN1,LOW);
  //  digitalWrite(EN2,HIGH);
  digitalWrite(EN1, HIGH);
  digitalWrite(EN2, LOW);
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, HIGH);
  analogWrite(ENA, Speed + 20);
  analogWrite(ENB, Speed - 20);
}

void GO_LEFT(int Speed)
{
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, HIGH);
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, HIGH);
  analogWrite(ENA, Speed * 3 / 4);
  analogWrite(ENB, Speed);
}

void GO_RIGHT(int Speed)
{
  digitalWrite(EN1, LOW);
  digitalWrite(EN2, HIGH);
  digitalWrite(EN3, LOW);
  digitalWrite(EN4, HIGH);
  analogWrite(ENA, Speed);
  analogWrite(ENB, Speed * 3 / 4);
}
