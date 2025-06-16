#include "actuatorController.h"
#include <Arduino.h>

// Define Error Tolerance
#define errorTolerance 5.0f // 5mm Tolerance for Position Control

// ActuatorController class implementation

ActuatorController::ActuatorController(int potPin, int ILI, int ELI)
    : potPin(potPin), ILI(ILI), ELI(ELI), targetPosition(0.0f) {
    pinMode(ILI, OUTPUT);
    pinMode(ELI, OUTPUT);
    stop(); // Initially Stop Actuator
}

// Define the setTargetPosition Function to Set the Commanded Position
void ActuatorController::setTargetPosition(float target) {
    targetPosition = target;
}

// Define the readPosition Function to Read the Position of the Linear Actuator
float ActuatorController::readPosition() {
    // Read the potentiometer value and map it to a position in mm
    int potValue = analogRead(potPin);
    // Assuming the potentiometer gives a range of 0-1023 corresponding to 0-100mm
    float position = map(potValue, 0, 1023, 0, 200); // Adjust the mapping as per your setup
    Serial.print("Actuator Position: ");
    Serial.println(position);
    return position;
}

// Define the Update Function to Constantly Update the Controller with New Feedback
void ActuatorController::update() {
    float currentPosition = readPosition();
    
    if (currentPosition < targetPosition - errorTolerance) { // If Current Position is 5mm Below Target
        extend();
    } else if (currentPosition > targetPosition + errorTolerance) { // If Current Position is 5mm Above Target
        retract();
    } else {
        stop(); // If Within 5mm of Target, Stop
    }
}

// Extension Function
void ActuatorController::extend() {
    digitalWrite(ILI, HIGH); // Set Internal Logic Input High
    digitalWrite(ELI, LOW);  // Set External Logic Input Low
}

// Retraction Function
void ActuatorController::retract() {
    digitalWrite(ILI, LOW);  // Set Internal Logic Input Low
    digitalWrite(ELI, HIGH); // Set External Logic Input High
}

// Stop Function
void ActuatorController::stop() {
    digitalWrite(ILI, LOW);  // Set Internal Logic Input Low
    digitalWrite(ELI, LOW);  // Set External Logic Input Low
}