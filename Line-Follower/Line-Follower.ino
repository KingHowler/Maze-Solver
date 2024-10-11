// Motor Connections
const int RF =  7;     // Left Forward
const int RS =  5;     // Left Speed
const int RB =  6;     // Left Backward
const int LF =  2;     // Right Forward
const int LS =  3;     // Right Speed
const int LB =  4;     // Right Backward

// IR Array Connections
const int LH_IR = 8;     // Very Left IR   
const int LM_IR = 9;     // Slight Left IR
const int M_IR  = 10;    // Middle IR
const int RM_IR = 11;    // Slight Right IR
const int RH_IR = 12;    // Very Right IR

// IR Value containers
int LH_V;
int LM_V;
int M_V;
int RM_V;
int RH_V;

//Motor Speed Values
const int Max = 255; //Maximum Speed
int TurnSpeed = 150;
int t1;


void setup() {
  pinMode(LF , OUTPUT);
  pinMode(LB , OUTPUT);
  pinMode(LS , OUTPUT);
  pinMode(RF , OUTPUT);
  pinMode(RB , OUTPUT);
  pinMode(RS , OUTPUT);
}

void loop() {
  LH_V = digitalRead(LH_IR);
  LM_V = digitalRead(LM_IR);
  M_V  = digitalRead(M_IR );
  RM_V = digitalRead(RM_IR);
  RH_V = digitalRead(RH_IR); // 0 means Black

    if (LM_V == 0 && !(LH_V == 0)) {                      // Slight Left IR is on track
      while ((!(M_V == 0) && !(LH_V == 0)) || LM_V == 0) {
        left(TurnSpeed, TurnSpeed);
        LH_V = digitalRead(LH_IR);
        LM_V = digitalRead(LM_IR);
        M_V  = digitalRead(M_IR );
      }
    }
    if (RM_V == 0 && !(RH_V == 0)) {                      // Slight Right IR is on track
      while ((!(M_V == 0) && !(RH_V == 0)) || RM_V == 0) {
        right(TurnSpeed, TurnSpeed);
        M_V  = digitalRead(M_IR );
        RM_V = digitalRead(RM_IR);
        RH_V = digitalRead(RH_IR);
      }
    }
    if (LH_V == 0) {                      // Very Left IR is on track
      while(!(M_V == 0) || LH_V ==0 ) {
        M_V  = digitalRead(M_IR );
        LH_V = digitalRead(LH_IR);
        left(Max, Max);
      }
    }
    if (RH_V == 0) {                      // Very Right IR is on track
      while(!(M_V == 0) || RH_V ==0 ) {
        M_V  = digitalRead(M_IR );
        RH_V = digitalRead(RH_IR);
        right(Max, Max);
      }
    } 
  forward(Max, Max);                      // Go forward once all errors have been corrected
}

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

void left(int L_Speed, int R_Speed) {
  analogWrite(LS, L_Speed);
  analogWrite(RS, R_Speed);
  digitalWrite(LF , HIGH);
  digitalWrite(LB , LOW);
  digitalWrite(RF , LOW);
  digitalWrite(RB , HIGH);
}

void right(int L_Speed, int R_Speed) {
  analogWrite(LS, L_Speed);
  analogWrite(RS, R_Speed);
  digitalWrite(LF , LOW);
  digitalWrite(LB , HIGH);
  digitalWrite(RF , HIGH);
  digitalWrite(RB , LOW);
}