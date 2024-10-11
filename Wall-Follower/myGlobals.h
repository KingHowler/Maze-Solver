#pragma once

// L298D Motor Driver Pins
const int LS = 3;       // Left Speed
const int LF = 2;       // Left Forward
const int LB = 4;       // Left Backward
const int RF = 7;       // Right Forward
const int RB = 6;       // Right Backward
const int RS = 5;       // Right Speed

// Ultrasonic Sensors Pins
const int FDT = A1;     // Front Distance Trig
const int FDE = A0;     // Front Distance Echo
const int LDT = A2;     // Left Distance Trig
const int LDE = A3;     // Left Distance Echo
const int RDT = 8;      // Right Distance Trig
const int RDE = 9;     // Right Distance Echo

// Constants
const int FRSD = 12.5;
const int LESD = 4;
const int RISD = 4;
const int moveSpeed = 200;

// Boolean Info
bool Emptyfront;
bool Emptyleft;
bool Emptyright;

// Distances
long Front_Dist;
long Left_Dist;
long Right_Dist;

// Orientation
MPU6050 mpu(Wire);
unsigned long timer = 0;
int inital_angle_x, inital_angle_y, inital_angle_z;
int x, y, z, GpX, GpY, GpZ;