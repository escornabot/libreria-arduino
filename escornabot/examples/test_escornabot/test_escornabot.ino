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

  switch (mirobot.pushButton()) {

    case forward://si pulsamos el botón delantero, se enciende led delantero, se mueve 1/4 de vuelta hacia delante, y se apaga el led delantero
      mirobot.ledON (forward);
      mirobot.drive (0.25, 10);
      mirobot.ledOFF (forward);
      break;

    case backward://si pulsamos el botón trasero, se enciende led trasero, se mueve 1/4 de vuelta hacia atrás, y se apaga el led trasero
      mirobot.ledON (backward);
      mirobot.drive (-0.25, 10);
      mirobot.ledOFF (backward);
      break;

    case right://si pulsamos el botón derecho, se enciende led derecho, se mueve 1/8 de vuelta hacia la derecha, y se apaga el led derecho
      mirobot.ledON (right);
      mirobot.turn (0.125, 10);
      mirobot.ledOFF (right);
      break;

    case left://si pulsamos el botón izquierdo, se enciende led izquierdo, se mueve 1/8 de vuelta hacia la izquierda, y se apaga el led izquierdo
      mirobot.ledON (left);
      mirobot.turn (-0.125, 10);
      mirobot.ledOFF (left);
      break;

    case central://si pulsamos el botón central, suena el zumbador y se enciende todos los leds durante un segundo, después se apagan el zumbador y los leds
      mirobot.buzzON ();
      for (int i = 1; i < mirobot.numberLeds; i++)
      {
        mirobot.ledON(i);
      }
      delay (1000);
      mirobot.buzzOFF();

      for (int i = 1; i < mirobot.numberLeds; i++)
      {
        mirobot.ledOFF(i);
      }

  }

  switch (mirobot.blueT()) {//en función del caracter emitido por bluetooth hace varias acciones
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
      /*led1 = !led1;
      if (led1) {
        mirobot.ledON(forward);
      }
      else {
        mirobot.ledOFF(forward);
      }*/
      invierteLed(forward);
      break;
    case '2':
      led2 = !led2;
      if (led2) {
        mirobot.ledON(left);
      }
      else {
        mirobot.ledOFF(left);
      }
      break;
    case '3':
      led3 = !led3;
      if (led3) {
        mirobot.ledON(backward);
      }
      else {
        mirobot.ledOFF(backward);
      }
      break;
    case '4':
      led4 = !led4;
      if (led4) {
        mirobot.ledON(right);
      }
      else {
        mirobot.ledOFF(right);
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

void invierteLed(int i){
  if (mirobot.ledState(i)) {
		mirobot.ledOFF(i);
	} else {
		mirobot.ledON(i);
	}
}
