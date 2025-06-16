#include <Arduino.h>
#include "actuatorController.h"

// Define the Pin Numbers
int ILI = 0; // Internal Logic Input
int ELI = 1; // External Logic Input
int potPin = 2; // Potentiometer Feedback Pin

// Create an Instance of the ActuatorController Class
ActuatorController actuatorController(potPin, ILI, ELI);

void setup()
{
// Set the output pins
pinMode(ILI, OUTPUT);
pinMode(ELI, OUTPUT);
pinMode(potPin, INPUT);

Serial.begin(9600); // Start Serial Communication for Debugging
actuatorController.setTargetPosition(50.0f); // Set the Target Position to 50mm
}

void loop()
{

}