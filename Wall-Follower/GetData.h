#include "myGlobals.h"

long distance(int Check_trig,  int Check_echo) {
  long duration, distance;

  // Clear the trigger
  digitalWrite(Check_trig, LOW);
  delayMicroseconds(2);

  // Set the trigger high for 10 microseconds
  digitalWrite(Check_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Check_trig, LOW);

  // Read the echo pin, duration of the pulse
  duration = pulseIn(Check_echo, HIGH) / 2;

  // Calculate distance in cm (speed of sound = 34300 cm/s)
  distance = duration * 0.0343;

  return distance;
}

void GetBools() {
  Front_Dist = distance(FDT, FDE);
  Left_Dist = distance(LDT, LDE);
  Right_Dist = distance(RDT, RDE);

  Emptyfront = ((Front_Dist >= 20) && (Front_Dist < 380));
  Emptyleft = ((Left_Dist >= 30) && (Left_Dist < 380));
  Emptyright = ((Right_Dist >= 30) && (Right_Dist < 380));
}

void PrintSensors() {
  Serial.print(Left_Dist);
  Serial.print("   ");
  Serial.print(Front_Dist);
  Serial.print("   ");
  Serial.print(Right_Dist);
  Serial.print("          ");
  Serial.print(Emptyleft);
  Serial.print("   ");
  Serial.print(Emptyfront);
  Serial.print("   ");
  Serial.println(Emptyright);
}