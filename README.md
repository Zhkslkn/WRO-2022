# Arduino robot for Future Engineerings, WRO-2022.

This file contains main codes, prototype and design, photos of team members and video of a driving mode of a robot.

## Usage 

Use the package [wro_robot_code.ino] to get the full source of a code of a robot in arduino.

## Explanation

This design is a prototype of an artificial intelligence machine that allows you to bypass various obstacles such as:
1. Determine the color and by color bypass obstacles both on the left side and on the right side.
2. Keep a relative distance in relation to the sides of the field
The program of this prototype is written in the Arduino IDE language, which uses various algorithms such as looping, branching, etc.

The design itself uses sensors such as an ultrasonic sensor, a color sensor. Ultrasonic Distance Sensor - HC-SR04 module uses acoustic radiation to determine the distance to an object. This non-contact sensor ensures high accuracy and stability of measurements. The measurement range is from 2 cm to 400 cm. The sensor readings are practically unaffected by solar radiation and electromagnetic noise. The module is sold complete with a transmitter and receiver.

Technical characteristics of HC-SR04
Supply voltage: +5V – DC;
Quiescent current: < 2 mA;
Working current: 15mA;
Effective working angle: < 15°;
Measuring distance: from 2 cm to 400 cm (1 – 13 inches);
Resolution: 0.3cm;
Measuring angle: 30 degrees;
Trigger pulse width: 10 microseconds;
Dimensions: 45 mm x 20 mm x 15 mm.Technical characteristics of HC-SR04
Supply voltage: +5V – DC;
Quiescent current: < 2 mA;
Working current: 15mA;
Effective working angle: < 15°;
Measuring distance: from 2 cm to 400 cm (1 – 13 inches);
Resolution: 0.3cm;
Measuring angle: 30 degrees;
Trigger pulse width: 10 microseconds;
Dimensions: 45 mm x 20 mm x 15 mm.

If the HC-SR04 does not read the echo signal, the output signal is never converted to LOW. Devantec and Parallax sensors provide a delay time of 36 milliseconds to 28 milliseconds, respectively. If you use the sketch above, the program will "hang" for 1 second. Therefore, it is advisable to specify a delay parameter.

The HC-SR04 sensor does not work well when measuring distances over 10 feet. The pulse return time is about 20 milliseconds, so it is recommended in such cases to set a delay time of more than 20, for example, 25 or 30 milliseconds.

You can connect the HC-SR04 ultrasonic distance sensor to only one Arduino pin. To do this, it is necessary to install a 2.2 kOhm resistor between the Trigger pins and the Echo and connect only the Trigger pin to the Arduino.

The gearbox of this motor contains gears made of durable plastic. However, it is not recommended to use it to manage massive structures. The silicone clamp prevents the engine from falling out of the gear housing, but it can be manually unfastened. This approach makes it easy to replace the engine with a similar one when the latter fails.

This class of motors with a gearbox is available in 4 types, namely:

Straight single-axis gear motor;
Direct two-axis gear motor;
Angular single-axis gear motor;
Angular two-axis gear motor.
In relation to these gear motors, the following technical characteristics can be distinguished:

Supply voltage range: 3V – 8V;
Rated consumption current at 3.6V: 240 mA;
Gear ratio: 1/48;
Rotation speed at 3.6V without load: 170 rpm.
Torque at 6V voltage: 800 g/cm;
Shaft diameter: 5.4 mm;
Dimensions (for direct modification): 64mm x 20mm x 20mm;
Weight: 26 grams.

Below is a list of the outputs of the L298N module with a brief description of each of them:

IN1, IN2 – these contacts are designed to control Motor No. 1 (A). Depending on the logic levels installed on these contacts, the motor will rotate in one direction or another. To obtain rotation, the logic levels on these contacts must be opposite to each other. For example: IN1=1, IN2=0 → the motor rotates clockwise; IN1=0, IN2=1 → the motor rotates counterclockwise.
IN2, IN3 – the functionality of the contacts is similar to IN1 and IN2, but only for Motor No. 2 (B).
The ENA – logical "1" on this pin allows the rotation of Motor No. 1 (A). Also, a PWM signal can be applied to this contact, which will allow controlling the speed of rotation of the motor.
ENB – contact functionality is similar to ENA, but only for Motor No. 2 (B).
OUT1, OUT2 – pad for connecting Motor No. 1 (A).
OUT3, OUT4 – pad for connecting Motor No. 2 (B).

For the transmitter , the relevant commands will be the following:

moving forward;
moving backwards;
movement to the right;
movement to the left;
changing the speed of movement from 0 to 100%
Engines are very often used in Arduino projects. They power the wheels, spin the propellers, rotate the manipulators of an industrial robot and move the carriage of a 3D printer.

Every novice roboticist faces the problem of connecting the motor to the microcontroller. The motor has only two pins, and it seems that the motor can be connected to the digital pins of the Arduino, and then turn on and off according to the program. But it was not there. Even a small motor, often used in various kinds of toys, requires a current of 200 mA to 1 Ampere for its operation.
