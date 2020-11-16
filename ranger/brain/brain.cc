#include <stdio.h>
#include <string>
#include <SerialStream.h>
#include <iostream>
#include <unistd.h>
#include <thread>
#include <chrono>
#include "ranger.hh"
#include "robot.hh"

using namespace LibSerial;
using namespace std;

const string PORT = "/dev/ttyUSB0";

void callback(Robot* robot) {
	float speed = 6 * clamp(0.0, robot->get_range() - 0.25, 1.0);
	cout << "Speed: " << speed << endl;
	robot->set_vel(speed, speed);
}

int main(int argc, char *argv[])
{
	Robot* robot = 0;

	std::string bname(basename(argv[0]));
	cout << "bin: [" << bname << "]" << endl;

	if (bname == "gz_brain") {
		cout << "Gazebo mode" << endl;
		robot = new GzRobot(argc, argv, callback);
	}

	if (bname == "rg_brain") {
		cout << "Ranger mode" << endl;
		robot = new RgRobot(argc, argv, callback);
	}

	robot->do_stuff();

	create_robot_connection(PORT);

	while (true) {
		cout << "Robot begins doing things" << endl;
		usleep(2);
		set_all_lights(0, 0, 255);
		cout << "Do something" << endl;
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
