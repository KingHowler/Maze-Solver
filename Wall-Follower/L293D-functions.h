#include "myGlobals.h"

void forward(int L_Speed, int R_Speed) {
  analogWrite(LS, L_Speed);
  analogWrite(RS, R_Speed);
  digitalWrite(LF , HIGH);
  digitalWrite(LB , LOW);
  digitalWrite(RF , HIGH);
  digitalWrite(RB , LOW);
}

void backward(int L_Speed, int R_Speed) {
  analogWrite(LS, L_Speed);
  analogWrite(RS, R_Speed);
  digitalWrite(LF , LOW);
  digitalWrite(LB , HIGH);
  digitalWrite(RF , LOW);
  digitalWrite(RB , HIGH);
}

void right(int L_Speed, int R_Speed) {
  analogWrite(LS, L_Speed);
  analogWrite(RS, R_Speed);
  digitalWrite(LF , HIGH);
  digitalWrite(LB , LOW);
  digitalWrite(RF , LOW);
  digitalWrite(RB , HIGH);
}

void left(int L_Speed, int R_Speed) {
  analogWrite(LS, L_Speed);
  analogWrite(RS, R_Speed);
  digitalWrite(LF , LOW);
  digitalWrite(LB , HIGH);
  digitalWrite(RF , HIGH);
  digitalWrite(RB , LOW);
}