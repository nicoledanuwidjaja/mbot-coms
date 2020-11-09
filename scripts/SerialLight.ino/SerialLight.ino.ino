#include <MeAuriga.h>

MeRGBLed led(0, 12);

int enable = 0;
int curr = 0;
char temp[16];


void setup() {
  // set control pin
  led.setpin(44);
  // setup serial connection
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    memset(temp, 0, 16);
    Serial.readBytesUntil('\n', temp, 16);
    Serial.print("Received: ");
    Serial.println(temp);
  }

  if (strcmp("on", temp) == 0) {
    enable = 1;
  } else {
    enable = 0;
  }

  for (int i = 0; i < 12; ++i) {
    if (i == curr && enable > 0) {
      led.setColorAt(i, 0, 100, 0);
    } else {
      led.setColorAt(i, 0, 0, 0);
    }
  }

  led.show();
  curr = (curr + 1) % 12;
  delay(100);

}
