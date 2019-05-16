#include <escornabot.h>

escornabot mirobot;

void setup() {
  Serial.begin (9600);
}

void loop() {
  //prueba de librería

  switch (mirobot.pushButton()) {

    case forward://si pulsamos el botón delantero, se enciende led delantero, se mueve 7 cm hacia delante, y se apaga el led delantero
      mirobot.ledON (forward);
      mirobot.driveD (7, 10);
      mirobot.ledOFF (forward);
      break;

    case backward://si pulsamos el botón trasero, se enciende led trasero, se mueve 7 cm hacia atrás, y se apaga el led trasero
      mirobot.ledON (backward);
      mirobot.driveD (-7, 10);
      mirobot.ledOFF (backward);
      break;

    case right://si pulsamos el botón derecho, se enciende led derecho, gira 45º hacia la derecha, y se apaga el led derecho
      mirobot.ledON (right);
      mirobot.turnA (45, 10);
      mirobot.ledOFF (right);
      break;

    case left://si pulsamos el botón izquierdo, se enciende led izquierdo, gira 45º hacia la izquierda, y se apaga el led izquierdo
      mirobot.ledON (left);
      mirobot.turnA (-45, 10);
      mirobot.ledOFF (left);
      break;

    case central://si pulsamos el botón central, suena el zumbador y se enciende todos los leds durante un segundo, después se apagan el zumbador y los leds
      mirobot.buzzON ();
      for (int i = 1; i < mirobot.numberLeds; i++)//La constante mirobot.numberLeds esta definida en la librera y vale 5
      {
        mirobot.ledON(i);
      }
      delay (1000);
      mirobot.buzzOFF();

      for (int i = 1; i < mirobot.numberLeds; i++)
      {
        mirobot.ledOFF(i);
      }
      break;

    default:
      mirobot.driveD(0,0);
      break;
  }

}
