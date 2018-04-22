#include <escornabot.h>

escornabot mirobot;
boolean buzz = false;

void setup() {
  Serial.begin (9600);
}

void loop() {
  //prueba de librería

  if (mirobot.blueT() == 'A') {
    mirobot.driveD (10, 15);
  }
  else if (mirobot.blueT() == 'R') {
    mirobot.driveD (-10, 15);
  }
  else if (mirobot.blueT() == 'D') {
    mirobot.turnA (45, 15);
  }
  else if (mirobot.blueT() == 'I') {
    mirobot.turnA (-45, 15);
  }
  else if (mirobot.blueT() == 'C') {
    mirobot.turnA (360, 15);
  }
  else if (mirobot.blueT() == '5') {
    buzz = ¡buzz;
    if (buzz == true) {
      mirobot.buzzON();
    }
    else {
      mirobot.buzzOFF();
    }
  }



}
