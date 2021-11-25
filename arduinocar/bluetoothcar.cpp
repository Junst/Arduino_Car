/*  Hey guys! So the wiring here is really easy.  Your bluetooth module
    wiring is as follows: Vcc goes to 5v, GND goes to GND, Tx goes to
    D2, and RX goes to D3.
*/

#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>
int enR = 10;   //These are the pins for our motor driver IC
int inAR = 8;
int inBR = 9;
int enL = 5;
int inAL = 6;
int inBL = 7;

void setup()
{
  pinMode(enR, OUTPUT);
  pinMode(inAR, OUTPUT);
  pinMode(inBR, OUTPUT);
  pinMode(enL, OUTPUT);
  pinMode(inAL, OUTPUT);
  pinMode(inBL, OUTPUT);
  Serial.begin(250000);    // Set your Serial Monitor is set at 250000
  Dabble.begin(9600);      // This is the baude rate of the HM-10
}

bool joystick_isDirection() {
  if (GamePad.getXaxisData() < -1 || GamePad.getXaxisData() > 1) {
    return true;
  }
  return false;
}

bool joystick_isRight() {
  if (joystick_isDirection()) {
    if (0 <= GamePad.getAngle() && GamePad.getAngle() < 90) {
      return true;
    } else if (270 < GamePad.getAngle()) {
      return true;
    }
  }
  else if (GamePad.isRightPressed()) {
    return true;
  }
  return false;
}

bool joystick_isLeft() {
  if (joystick_isDirection()) {
    if (90 < GamePad.getAngle() && GamePad.getAngle() < 270) {
      return true;
    }
  } else if (GamePad.isLeftPressed()) {
    return true;
  }
  return false;
}

void loop() {
  Dabble.processInput();  // This line is crucial in grabbing our data

  Serial.println(GamePad.getAngle());

  if (GamePad.isCrossPressed())
  {
    Serial.println("Forward");
    analogWrite(enR, 255);
    digitalWrite(inAR, LOW);
    digitalWrite(inBR, HIGH);
    analogWrite(enL, 255);
    digitalWrite(inAL, LOW);
    digitalWrite(inBL, HIGH);
  } else if (GamePad.isCirclePressed())
  {
    Serial.println("Backward");
    analogWrite(enR, 255);
    digitalWrite(inAR, HIGH);
    digitalWrite(inBR, LOW);
    analogWrite(enL, 255);
    digitalWrite(inAL, HIGH);
    digitalWrite(inBL, LOW);
  } else if (joystick_isRight())
  {
    Serial.println("Right");
    analogWrite(enR, 255);
    digitalWrite(inAR, LOW);
    digitalWrite(inBR, HIGH);
    analogWrite(enL, 255);
    digitalWrite(inAL, HIGH);
    digitalWrite(inBL, LOW);
  }

  else if (joystick_isLeft())
  {
    Serial.println("Left");
    analogWrite(enR, 255);
    digitalWrite(inAR, HIGH);
    digitalWrite(inBR, LOW);
    analogWrite(enL, 255);
    digitalWrite(inAL, LOW);
    digitalWrite(inBL, HIGH);
  }
  else
  {
    Serial.println("Stopped");
    analogWrite(enR, 0);
    digitalWrite(inAR, LOW);
    digitalWrite(inBR, LOW);
    analogWrite(enL, 0);
    digitalWrite(inAL, LOW);
    digitalWrite(inBL, LOW);
  }
}