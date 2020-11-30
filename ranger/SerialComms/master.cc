/* Test master state with SoftwareSerial. */
#include <SoftwareSerial.h> 
SoftwareSerial SoftSerial(2, 3); // RX, TX
 
 
byte buttonSwitch1 = 14; 
byte buttonSwitch2 = 15; 
 
boolean buttonState1 = false;
boolean buttonState2 = false;
boolean buttonState3 = false;
 
boolean buttonSwitch1_State_old = false;
boolean buttonSwitch2_State_old = false; 
 
 
void setup() 
{
    SoftSerial.begin(9600);
}
 
void loop() 
{
  // simple debounce
  buttonState1 = digitalRead(buttonSwitch1); delay(1);
  buttonState2 = digitalRead(buttonSwitch1); delay(1);
  buttonState3 = digitalRead(buttonSwitch1); delay(1);
 
  if ( (buttonState1 == buttonState2) && (buttonState1 == buttonState3) )
  {
     // has the button switch state changed?
     if (buttonState1 != buttonSwitch1_State_old)
     {
        buttonSwitch1_State_old = buttonState1;
        if (buttonSwitch1_State_old == HIGH) { SoftSerial.print(1);}  else  { SoftSerial.print(0);}
     }
  }
 
 
 
  buttonState1 = digitalRead(buttonSwitch2); delay(1);
  buttonState2 = digitalRead(buttonSwitch2); delay(1);
  buttonState3 = digitalRead(buttonSwitch2); delay(1);
 
  if ( (buttonState1 == buttonState2) && (buttonState1 == buttonState3) )
  {
     // has the button switch state changed?
     if (buttonState1 != buttonSwitch2_State_old)
     {
        buttonSwitch2_State_old = buttonState1;
        if (buttonSwitch2_State_old == HIGH) { SoftSerial.print(3);} else { SoftSerial.print(2);}
 
     }
  }
 
 
 
 
}