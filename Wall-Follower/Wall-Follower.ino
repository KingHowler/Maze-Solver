#include <MPU6050.h>
#include <Wire.h>
#include "L293D-functions.h"
#include "GetData.h"
#include "myGlobals.h"

MPU6050 gyro;
float currentAngle = 0.0;
int16_t gyroX, gyroY, gyroZ;

void setup() {
  
  // L298D
  pinMode( LS , OUTPUT);
  pinMode( LF , OUTPUT);
  pinMode( LB , OUTPUT);
  pinMode( RF , OUTPUT);
  pinMode( RB , OUTPUT);
  pinMode( RS , OUTPUT);
  
  // Front Distance Sensor
  pinMode( FDT , OUTPUT);
  pinMode( FDE , INPUT);

  // Left Distance Sensor
  pinMode( LDT , OUTPUT);
  pinMode( LDE , INPUT);

  // Right Distance Sensor
  pinMode( RDT , OUTPUT);
  pinMode( RDE , INPUT);

  Wire.begin();
  Serial.begin(9600);

  gyro.initialize();
  if (!gyro.testConnection()) {
    Serial.println("Gyro connection failed");
    while (1);
  }

  GetBools();
}

void loop() {
  GetBools();

  FollowWall();
  PrintSensors();

}
bool turn90Degrees() {

  // Reset current angle
  currentAngle = 0.0;

  // Begin turn
  rotateRight();

  while (currentAngle < 105) {
    gyro.getRotation(&gyroX, &gyroY, &gyroZ);
    currentAngle += (gyroZ / 131.0) * 0.01; // Convert raw data to degrees, assuming loop runs every 10ms
    Serial.println(currentAngle);
  }

  // Stop the car after completing the turn
  stopCar();
  return true;
}
bool turn180Degrees() {

  // Reset current angle
  currentAngle = 0.0;

  // Begin turn
  rotateRight();

  while (currentAngle < 105 * 2) {
    gyro.getRotation(&gyroX, &gyroY, &gyroZ);
    currentAngle += (gyroZ / 131.0) * 0.01; // Convert raw data to degrees, assuming loop runs every 10ms
    Serial.println(currentAngle);
  }

  // Stop the car after completing the turn
  stopCar();
  return true;
}
bool turn270Degrees() {

  // Reset current angle
  currentAngle = 0.0;

  // Begin turn
  rotateRight();

  while (currentAngle < 105 * 3) {
    gyro.getRotation(&gyroX, &gyroY, &gyroZ);
    currentAngle += (gyroZ / 131.0) * 0.01; // Convert raw data to degrees, assuming loop runs every 10ms
    Serial.println(currentAngle);
  }

  // Stop the car after completing the turn
  stopCar();
  return true;
}

void rotateRight() {
  analogWrite(RS, 160);   // Set motor speed for motor A
  digitalWrite(RF, HIGH);        // Set motor A forward
  digitalWrite(RB, LOW);

  analogWrite(LS, 160);   // Set motor speed for motor B
  digitalWrite(LF, LOW);         // Set motor B backward
  digitalWrite(LB, HIGH);
}

void stopCar() {
  analogWrite(RS, 0);   // Stop motor A
  digitalWrite(RF, LOW);
  digitalWrite(RB, LOW);

  analogWrite(LS, 0);   // Stop motor B
  digitalWrite(LF, LOW);
  digitalWrite(LB, LOW);
}

void FollowWall() {
  if (!Emptyleft) {
    if (Emptyfront) {
      delay(1000);
      stopCar();
      forward(moveSpeed, moveSpeed);
      stopCar();
    }
    else if (Emptyright) {
      stopCar();
      delay(1000);
      backward(moveSpeed, moveSpeed);
      delay(200);
      if (turn270Degrees()) {
        delay(1000);
      }
      stopCar();
    }
    else {
      stopCar();
      delay(1000);
      backward(moveSpeed, moveSpeed);
      delay(200);
      if (turn180Degrees()) {
        delay(1000);
      }
      stopCar();
    }
  }
  if (Emptyleft) {
    if (Emptyfront) {
      delay(1000);
      stopCar();
      forward(moveSpeed, moveSpeed);
      stopCar();
    }
    else {
      stopCar();
      delay(1000);
      left(moveSpeed, moveSpeed);
      if (turn90Degrees()) {
        delay(1000);
      }
    }
  }
}
