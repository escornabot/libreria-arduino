#include <escornabot.h>
escornabot mirobot;//declara un objeto llamado mirobot de tipo escornabot


void setup() {
  // put your setup code here, to run once:
  /*mueve el robot 1/4 de vuelta hacia delante a una velocidad de 10 rpm*/
  mirobot.drive (0.25, 10);
  /*mueve el robot 1/4 de vuelta hacia detrás a una velocidad de 10 rpm*/
  mirobot.drive (-0.25, 10);
  /*gira el robot 1/8 de vuelta hacia delante a una velocidad de 10 rpm*/
  mirobot.turn (0.125, 10);
  /*gira el robot 1/8 de vuelta hacia delante a una velocidad de 10 rpm*/
  mirobot.turn (-0.125, 10);

}

void loop() {
  // put your main code here, to run repeatedly:


}
