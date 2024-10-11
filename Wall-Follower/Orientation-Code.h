void GetOrientation() {
  mpu.update();
  x = mpu.getAngleX();
  y = mpu.getAngleY();
  z = mpu.getAngleZ();
  timer = millis();
  GpX = inital_angle_x - x;
  GpY = inital_angle_y - y;
  GpZ = inital_angle_z - z;
}