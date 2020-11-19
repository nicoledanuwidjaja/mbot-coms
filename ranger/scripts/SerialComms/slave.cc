// Arduino Serial Example #4 Remote Control Blink Using Software Serial - Slave

#include <SoftwareSerial.h> 
SoftwareSerial SoftSerial(11, 12); // RX, TX
 
 
char c  = ' ';
byte LED1 = 2;
byte LED2 = 3;
 
void setup() 
{
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
 
   SoftSerial.begin(9600);
}
 
 
void loop()
{
   if(SoftSerial.available())
   {
      char c = SoftSerial.read();
      if (c=='0') { digitalWrite(LED1, LOW); }
      if (c=='1') { digitalWrite(LED1, HIGH); }
      if (c=='2') { digitalWrite(LED2, LOW); }
      if (c=='3') { digitalWrite(LED2, HIGH); }
   }
 
}