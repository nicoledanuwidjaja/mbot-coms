/* 
* Instantiates subsystems, commands, and serial controller.
* Handles command controls for robot.
* https://github.com/sumsted/roboplayground/blob/master/roboplayground.cpp
*/

#include <Arduino.h>
#include <MeAuriga.h>
#include "subsystems.h"
#include "commands.h"
#include "SerialController.h"

boolean is_master = false;
boolean last_is_master = false;
boolean previous_button_state = false;
boolean current_button_state = false;
String last_command = String("");

SubSystems ss;
Commands cmd(ss);
SerialController sc(ss);

void button_handler()
{
    // Toggle master slave setting if on board button pressed
    // current_button_state = ss.is_button_pressed();
    // Serial.println("Button: " + current_button_state);   

    // if (current_button_state != previous_button_state)
    // {
        // previous_button_state = current_button_state;
        current_button_state = true;
        if (current_button_state == true)
        {
            is_master = is_master ? false : true;
            if (is_master == true)
            {
                ss.show_color(RED);
            }
            else
            {
                ss.show_color(BLUE);
            }
        }
    // }
}

void ir_remote_handler()
{
    // Listen for command, remote for master and bot 2 bot for slave
    uint32_t value = 0;
    // if (ss.get_remote_button(&value))
    if (current_button_state == true)
    {

        Serial.println("Value: " + String(value));
        switch (value)
        {
        
        // Transmit commands
        case "A":
            cmd.master_command(String("A"));
            cmd.command_a(is_master);
            break;
        case "B":
            cmd.master_command(String("B"));
            cmd.command_b(is_master);
            break;
        case "C":
            cmd.master_command(String("C"));
            cmd.command_c();
            break;

        // Movement commands
        case "UP":
            ss.move(BOT_FORWARD, FAST);
            break;
        case "DOWN":
            ss.move(BOT_BACKWARD, FAST);
            break;
        case "LEFT":
            ss.move(BOT_FORWARD_LEFT, FAST);
            break;
        case "RIGHT":
            ss.move(BOT_FORWARD_RIGHT, FAST);
            break;
        case "ROTATE LEFT":
            ss.move(BOT_ROTATE_LEFT, FAST);
            break;
        case "ROTATE RIGHT":
            ss.move(BOT_ROTATE_RIGHT, FAST);
            break;
        case "BACK LEFT":
            ss.move(BOT_BACKWARD_LEFT, FAST);
            break;
        case "BACK RIGHT":
            ss.move(BOT_BACKWARD_RIGHT, FAST);
            break;
        case "STOP":
            ss.move(BOT_STOP, STOP);
            break;
        }
    }
}

/* Remote control commands sent from master robot to slave robot. */
void command_handler()
{
    // The slave bot (blue) listens for IR commands from master
    String command = ss.get_cmd_string();
    if (command != "" && command != last_command)
    {
        // Serial.println("command: "+command);
        if (command.endsWith("A") == true)
        {
            cmd.command_a(is_master);
        }
        else if (command.endsWith("B") == true)
        {
            cmd.command_b(is_master);
        }
        else if (command.endsWith("C") == true)
        {
            cmd.command_c();
        }
        last_command = String(command);
    }
}

/*
 * Setup and Loop for Arduino control program
 */
void setup()
{
    Serial.println("setup");

    Serial.begin(9600);
    cmd.startup_sequence();
    ss.show_color(BLUE);
}

void loop()
{
    button_handler();
    if (last_is_master != is_master)
    {
        last_is_master = is_master;
        Serial.println("master: " + String(is_master));
    }

    if (is_master)
    {
        sc.serial_handler();
        // ir_remote_handler();
    }
    else
    {
        command_handler();
    }

}