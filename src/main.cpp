#include <Arduino.h>
#include "actuatorController.h"
#include "mcp2515.h" // Include the MCP2515 library for CAN communication

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

// Create Instance of the MCP2515 CAN Controller and Initialize
MCP2515 mcp2515(10); // Assuming CS Pin is 10
mcp2515.reset();
mcp2515.setBitrate(CAN_125KBPS, MCP_8MHZ); // Set the CAN Bitrate to 125 kbps with a 8 MHz Clock
mcp2515.setLoopbackMode();

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
leftActuatorController.setTargetPosition(100.0f); // Set the Left Actuator's Target Position
rightActuatorController.setTargetPosition(100.0f); // Set the Right Actuator's Target Position
}

void loop()
{
leftActuatorController.update(); // Continuously Update the Left Actuator Controller
rightActuatorController.update(); // Continuously Update the Right Actuator Controller
delay(100);
}