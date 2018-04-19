#include <escornabot.h>

escornabot mirobot;

void setup() {
  Serial.begin (9600);
}

void loop() {
  //prueba de librería

  if (mirobot.pushButton() == forward) {
    mirobot.driveD (10, 15);
  }
  else if (mirobot.pushButton() == backward) {
    mirobot.driveD (-10, 15);
  }
  else if (mirobot.pushButton() == right) {
    mirobot.turnA (90, 15);
  }
  else if (mirobot.pushButton() == left) {
    mirobot.turnA (-90, 15);
  }
  else if (mirobot.pushButton() == central) {
    mirobot.turnA (360, 15);
  }
}





