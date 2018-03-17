#include <escornabot.h>

escornabot mirobot;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
for (int n=1; n<5;n++) {

  mirobot.ledON (n);
  delay (125);
  mirobot.ledOFF (n);
  delay (125);
}


mirobot.buzzON();
delay (200);
mirobot.buzzOFF();

}
