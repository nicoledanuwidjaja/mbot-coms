# Robot See... Robot Do - Extra Credit Attempt
Get two mBots to communicate with each other using Bluetooth

This repository provides a handful of useful scripts for communicating with the mBot subsystem interfaces. With an infrared receiver, this establishes a stable connection between two mBot robots connected via serial communication. In doing so, this establishes two different roles for the robots: Master and Slave.

The purpose of this repository is to establish a connection between the two robots so that they can work alongside each other to solve the maze. Our goal for this is to have the Master robot be able to send commands to the Slave, as the Master robot would follow the control program provided and send periodic updates and commands to the Slave.

[`/SerialComms`](https://github.com/nicoledanuwidjaja/robot-see-robot-do/tree/comms/ranger/SerialComms) contains code for setting up connectivity as well as functionality for operating on the different sensors.

`run.cpp` sets up Arduino control program and instantiates all helper files and deesignates the bots to their roles.

`commands.cpp/h` provides available commands for the master bot to send to the slave bot.

`SerialController.cpp/h` establishes a serial connection between mBots and the app, including functions for reading sensor data and reading/writing data to the serial port.

`subsystems.cc/h` provides callable functions for supporting motion, infrared, color, and gyroscope sensors.

Further supplementation: With an i2c Bus, we can use the i2c protocol to communicate with the master-slave connection.

## Setup
(Standard procedures for connecting Arduino programs)

Install Arduino IDE.

Select Arduino Mega 2560 for the ME Auriga Makeblock board.

Upload Firmware for Auriga via Serial Port (dev/ttyUSB0).


### Attributions

[Research Paper](http://www.eecs.ucf.edu/seniordesign/fa2014sp2015/g28/docs/SD2Report.pdf)

[Base Code](https://github.com/nbock/cs5335-nm/tree/ranger-library)


### Research

https://forum.arduino.cc/index.php?topic=419320.0

https://www.instructables.com/I2C-InfraRed-Remote-Control-With-the-Arduino/

https://www.arduino.cc/en/Tutorial/LibraryExamples/RobotRemoteControl

https://forum.makeblock.com/t/makeblock-robots-talking-to-each-other/10253

https://forum.makeblock.com/t/multiple-robot-communication-through-wifi/10238

https://forum.makeblock.com/t/communication-between-two-mbots/2778/17

https://www.robotshop.com/community/forum/t/makeblock-mbot-commands-from-another-arduino-device/26381/2

https://howtomechatronics.com/tutorials/arduino/how-i2c-communication-works-and-how-to-use-it-with-arduino/

