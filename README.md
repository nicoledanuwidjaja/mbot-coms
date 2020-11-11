# Robot See... Robot Do
Get two mBots to communicate with each other using Bluetooth

## Setup
Install Arduino IDE.

Select Arduino Mega 2560 for the ME Auriga Makeblock board.

Upload Firmware for Auriga via Serial Port (dev/ttyUSB0).

## Proposal
Our project will be to have two robots collaborate together to solve a maze while using two different maze-solving algorithms. Each robot will start at the same starting point but in separate, identical mazes, and will use an assigned maze-solving algorithm to find the destination. The robots will be able to communicate with each other via Bluetooth to send and receive messages in order to find an optimal path.

Because the two robots will be using different maze-solving algorithms, one mBot will likely finish before the other mBot. Our project will use this completion time difference to assign one mBot as the Guide and the other mBot as the Follower. As the robots traverse the maze, they will store each turn made until the robot has reached its destination. This will be stored as an array representing Follower’s current path. The Guide will store its optimal path solution in a separate array. Both robots will traverse according to their algorithms until the Guide has completed, in which the solution array will contain the complete optimized path.

Once an mBot has reached its destination, it will emit a sound that will notify the other robot to begin to receive transmitted messages using the Me Auriga board. The Guide will begin to communicate with beeping signals to send a sequence that will indicate the correct path to the Follower until it reaches the destination.

[Research Paper](http://www.eecs.ucf.edu/seniordesign/fa2014sp2015/g28/docs/SD2Report.pdf)

