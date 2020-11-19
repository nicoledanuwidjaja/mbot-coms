#include "Arduino.h"
#include "BitbloqBot.h"



BitbloqMBot::BitbloqMBot(int lineFollowerPort, int USPort):
        BitbloqMCore(),
        usSensor(NULL),
        leftLineFollowerPin(-1),
        rightLineFollowerPin(-1),
        usTriggerPin(-1),
        usEchoPin(-1)
{
	if (lineFollowerPort != -1){
		rightLineFollowerPin = ports[lineFollowerPort][1];
		leftLineFollowerPin = ports[lineFollowerPort][1];
	}
	
	if (USPort != -1){
		usTriggerPin = ports[USPort][2]; /// this is weird. There are two components, but only one signal.
		usEchoPin = ports[USPort][2];
	}
    
    leftDCMotor = new Bitbloq::DCMotor(DCMotor2Dir,DCMotor2PWM);
    rightDCMotor = new Bitbloq::DCMotor(DCMotor1Dir,DCMotor1PWM);
}


BitbloqMBot::~BitbloqMBot(){
	
	//check that all of them are not NULL pointers, delete and set to NULL
	
    if(usSensor!=NULL){
        delete usSensor;
        usSensor=NULL;
    }
    
    if(leftDCMotor!=NULL){
        delete leftDCMotor;
        leftDCMotor=NULL;
    }
    
    if(rightDCMotor!=NULL){
        delete rightDCMotor;
        rightDCMotor=NULL;
    }
}

void BitbloqMBot::setLineFollowerPort(int port){
    rightLineFollowerPin = ports[port][1];
    leftLineFollowerPin = ports[port][2];
}

void BitbloqMBot::setUSPort(int port){
    usTriggerPin = ports[port][2]; /// this is weird. There are two components, but only one signal.
    usEchoPin = ports[port][2];
}

void BitbloqMBot::setup(){
    BitbloqMCore::setup();

	//set PinMode if pins are defined (otherwise pins = -1)
    
    if (leftLineFollowerPin != -1 && rightLineFollowerPin != -1){
		pinMode(leftLineFollowerPin,INPUT);
		pinMode(rightLineFollowerPin, INPUT);
    }
    
    if (usTriggerPin != -1){
		//initialize usSensor
		usSensor = new BitbloqUltrasound(usTriggerPin,usEchoPin);
		usSensor->setup();
	}
        
    //dc motors setup
    leftDCMotor->setup();
    rightDCMotor->setup();
}

int BitbloqMBot::readLeftLineFollowerSensor() const{
    return (leftLineFollowerPin != -1 ? digitalRead(leftLineFollowerPin) : -1) ;
}

int BitbloqMBot::readRightLineFollowerSensor() const{
    return (leftLineFollowerPin != -1 ? digitalRead(rightLineFollowerPin) : -1 );
}


int BitbloqMBot::readUSMeasuredDistanceCM() const{
	return (usSensor != NULL ? usSensor->readDistanceInCM(): - 1 ); //in centimeters
}

int BitbloqMBot::readUSMeasuredDistanceIN() const{
	return (usSensor != NULL ? usSensor->readDistanceInInches() : -1); //in inches
}
    
void BitbloqMBot::move(int direction, int speed){
	int leftSpeed = 0;
	int rightSpeed = 0;
	if(direction == 1){
		leftSpeed = speed; //forward 
		rightSpeed = -speed;
		
	}else if(direction == 2){//backward
		leftSpeed = -speed;
		rightSpeed = speed;
		
	}else if(direction == 3){
		leftSpeed = -speed; //right
		rightSpeed = -speed;
	}else if(direction == 4){
		
		leftSpeed = speed; //left
		rightSpeed = speed;
	}
	
    leftDCMotor->setSpeed(leftSpeed);
    rightDCMotor->setSpeed(rightSpeed);
}

void BitbloqMBot::setRightMotorSpeed(int speed){
    rightDCMotor->setSpeed(speed);
}

void BitbloqMBot::setLeftMotorSpeed(int speed){
    leftDCMotor->setSpeed(speed);
}