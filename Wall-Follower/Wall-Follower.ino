#include <MPU6050_light.h>
#include "Wire.h"
#include "L293D-functions.h"
#include "GetData.h"
#include "myGlobals.h"
#include "Orientation-Code.h"

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

  byte status = mpu.begin();
  Serial.print(F("MPU6050 status: "));
  Serial.println(status);
  while (status != 0) {}
  
  mpu.update();
  inital_angle_x = mpu.getAngleX();
  inital_angle_y = mpu.getAngleY();
  inital_angle_z = mpu.getAngleZ();
  Serial.println("X " + String(inital_angle_x) + "  Y " + String(inital_angle_y) + "  Z " + String(inital_angle_z));

  GetBools();
}

void loop() {
  GetBools();

  FollowWall();
  PrintSensors();

}

void FollowWall() {
  if (Emptyleft) {
    left(moveSpeed, moveSpeed);
    GpZ = 0;
    inital_angle_z = 0;
    while(GpZ > -90) {
      GetOrientation();
      delay(10);
    }
  }
  if (!Emptyleft) {
    if (Emptyfront) {
      forward(moveSpeed, moveSpeed);
    } 
    else {
      backward(moveSpeed, moveSpeed);
      delay(200);
      while (!Emptyfront) {
        GetBools();
        right(moveSpeed, moveSpeed);
        delay(10);
      }
    }
  }
}
