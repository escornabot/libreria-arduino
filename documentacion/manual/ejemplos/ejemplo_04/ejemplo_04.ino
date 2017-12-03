#include <escornabot.h>

escornabot mirobot;
boolean led1 = false;
boolean led2 = false;
boolean led3 = false;
boolean led4 = false;
boolean buzz = false;

void setup() {
  Serial.begin (9600);
}

void loop() {
  //prueba de librería

  switch (mirobot.blueT()) {
    case 'A':
      mirobot.drive (0.25, 12);
      break;
    case 'R':
      mirobot.drive (-0.25, 12);
      break;
    case 'D':
      mirobot.turn (0.125, 12);
      break;
    case 'I':
      mirobot.turn (-0.125, 12);
      break;
    case '1':
      led1 = !led1;
      if (led1) {
        mirobot.ledON(1);
      }
      else {
        mirobot.ledOFF(1);
      }
      break;
    case '2':
      led2 = !led2;
      if (led2) {
        mirobot.ledON(2);
      }
      else {
        mirobot.ledOFF(2);
      }
      break;
    case '3':
      led3 = !led3;
      if (led3) {
        mirobot.ledON(3);
      }
      else {
        mirobot.ledOFF(3);
      }
      break;
    case '4':
      led4 = !led4;
      if (led4) {
        mirobot.ledON(4);
      }
      else {
        mirobot.ledOFF(4);
      }
      break;
    case '5':
      buzz = !buzz;
      if (buzz) {
        mirobot.buzzON();
      }
      else {
        mirobot.buzzOFF();
      }
      break;
      //default:
      // statements
  }


}

