#include <stdio.h>
#include <string>
#include <SerialStream.h>
#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
#include "ranger.hh"

using namespace LibSerial;
using namespace std;

const string PORT = "/dev/ttyUSB0";

int main(int argc, char *argv[])
{
	create_robot_connection(PORT);

	while (true) {
		usleep(2);
		set_all_lights(0, 0, 255);
		usleep(2);
		lights_off();
		usleep(2);
		set_single_light(1, 0, 255, 0);
		usleep(2);
		single_light_off(1);
		usleep(2);
		move_forward();
		usleep(2);
		stop();
		usleep(2);
		move_backward();
		usleep(2);
		stop();
		usleep(2);
		turn_left();
		usleep(2);
		stop();
		usleep(2);
		turn_right();
		usleep(2);
		stop();
		usleep(2);
		move_forward(250);
		usleep(2);
		stop();
		usleep(2);
		move_backward(250);
		usleep(2);
		stop();
		usleep(2);
		turn_left(250);
		usleep(2);
		stop();
		usleep(2);
		turn_right(250);
		usleep(2);
		stop();
		usleep(2);
		tank_drive(200, -200);
		usleep(2);
		stop();
		usleep(2);
		tank_drive(-200, 200);
		usleep(2);
		stop();
		usleep(2);
		tank_drive(200, 200);
		usleep(2);
		stop();
		usleep(2);
		tank_drive(-200, -170);
		usleep(2);
		stop();
		usleep(2);
		make_noise(1000, 100);
		usleep(2);
		cout << "line sensor: " << read_line_sensor() << endl;
		usleep(2);
		cout << "light sensor: " << read_light_sensor() << endl;
		usleep(2);
		cout << "temperature: " << read_temperature_sensor() << endl;
		usleep(2);
		cout << "sound sensor: " << read_sound_sensor() << endl;
		usleep(2);
		cout << "sonar sensor: " << read_sonar_sensor() << endl;
		usleep(2);
		cout << "Gyro X: " << read_gyroscope_x() << endl;
		usleep(2);
		cout << "Gyro Y: " << read_gyroscope_y() << endl;
		usleep(2);
		cout << "Gyro Z: " << read_gyroscope_z() << endl;
		usleep(2);
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}
