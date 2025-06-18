#include <Arduino.h>
#include "actuatorController.h"

// Define the Pin Numbers

// Left Actuator Pins (from the Perspective of the MCU)
int RILI = 4; // Left Internal Logic Input
int RELI = 5; // Left External Logic Input
int RPotPin = 6; // Left Potentiometer Feedback Pin

// Right Actuator Pins (from the Perspective of the MCU)
int LILI = 9; // Right Internal Logic Input
int LELI = 8; // Right External Logic Input
int LPotPin = 7; // Right Potentiometer Feedback Pin

// Create Instances of the Actuator Controller Class for the Left and Right Actuators
ActuatorController leftActuatorController(LPotPin, LILI, LELI);
ActuatorController rightActuatorController(RPotPin, RILI, RELI);

void setup()
{
// Set the output pins

// Left Actuator Pins (from the Perspective of the MCU)
pinMode(LILI, OUTPUT);
pinMode(LELI, OUTPUT);
pinMode(LPotPin, INPUT);

// Right Actuator Pins (from the Perspective of the MCU)
pinMode(RILI, OUTPUT);
pinMode(RELI, OUTPUT);
pinMode(RPotPin, INPUT);

Serial.begin(9600); // Start Serial Communication for Debugging
leftActuatorController.setTargetPosition(180.0f); // Set the Left Actuator's Target Position
rightActuatorController.setTargetPosition(180.0f); // Set the Right Actuator's Target Position
}

void loop()
{
leftActuatorController.update(); // Continuously Update the Left Actuator Controller
rightActuatorController.update(); // Continuously Update the Right Actuator Controller
delay(100);
}