# Linear Actuator Controller Stack

This stack provides a rudimentary method of controlling an Actuonix P16 or similar linear actuator (other linear actuators may be used as well, so long as potentiometer feedback is present). This stack is uploaded to a microcontroller (the Seeeduino XIAO was used for this project) that is used to control an L298N motor driver.

Regarding dependencies, the stack requires many of the Arduino software functionalities which may need to be installed. Additionally,CAN communication with an external controller was used to enable to the control of multiple linear actuators simultaneously. autowp's arduino-mcp2515 library was utilized for this can communication. You can clone the library by running the following command in terminal:

```
git clone https://github.com/autowp/arduino-mcp2515
```

The method for reading the desired leg lengths from the CAN bus line is written in the canCommunication.cpp file. If another method of receiving position commands is desired, this file can be removed or modified.

The controller algorithm is written in actuatorController.cpp. This file defines an error tolerance and a stroke length (or maximum extension) that should be adjusted based on your actuator specification. By default, an error tolerance of 1 mm and a stroke length of 200 mm are defined. The controller behaves very simply; providing the linear actuator with full power (maximum velocity) in the appropriate direction whenever the error tolerance is not reached. Since servo-like linear actuators like the Actuonix P16 rarely experience notable overshoot, such a simple control method is generally preferable.