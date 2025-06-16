#include <Arduino.h>

/*==========================================================================
// Author : Handson Technology
// Project : Arduino Uno
// Description : L298N Motor Driver
// Source-Code : L298N_Motor.ino
// Program: Control 2 DC motors using L298N H Bridge Driver
//==========================================================================
*/
// Definitions Arduino pins connected to input H Bridge
int IN1 = 0;
int IN2 = 1;

void setup()
{
// Set the output pins
pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
}

void loop()
{
// Rotate the Motor A clockwise
digitalWrite(IN1, HIGH);
digitalWrite(IN2, LOW);
delay(2000);
// Motor A
digitalWrite(IN1, LOW);
digitalWrite(IN2, HIGH);
delay(2000);
// Rotates the Motor A counter-clockwise
// digitalWrite(IN1, LOW);
// digitalWrite(IN2, HIGH);
// delay(2000);
// Motor A
// digitalWrite(IN1, HIGH);
// digitalWrite(IN2, HIGH);
// delay(500);
}