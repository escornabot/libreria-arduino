#include <escornabot.h>


int acciones[20];
escornabot mirobot;
int pulsaciones = 0;
int n;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (mirobot.pushButton() == forward) {
    acciones[pulsaciones] = 1;
    pulsaciones = pulsaciones + 1;
    delay (200);
  }
  else if (mirobot.pushButton() == backward) {
    acciones[pulsaciones] = 2;
    pulsaciones = pulsaciones + 1;
    delay (200);
  }
  else if (mirobot.pushButton() == left) {
    acciones[pulsaciones] = 3;
    pulsaciones = pulsaciones + 1;
    delay (200);
  }
  else if (mirobot.pushButton() == right) {
    acciones[pulsaciones] = 4;
    pulsaciones = pulsaciones + 1;
    delay (200);
  }
  else if (mirobot.pushButton() == central) {

    for (n = 0; n < pulsaciones; n++) {
      if (acciones[n] == 1) {
        mirobot.driveD(10, 12);
      }
      else if (acciones[n] == 2) {
        mirobot.driveD(-10, 12);
      }
      else if (acciones[n] == 3) {
        mirobot.turnA(90, 12);
      }
      else if (acciones[n] == 4) {
        mirobot.turnA(-90, 12);
      }
      Serial.println (acciones[n]);
    }
    delay (200);
    pulsaciones = 0;
  }


}
