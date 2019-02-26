#include <escornabot.h>
escornabot mirobot;//declara un objeto llamado mirobot de tipo escornabot


void setup() {
  // put your setup code here, to run once:
  /*mueve el robot 8 cm hacia delante a una velocidad de 10 rpm*/
  mirobot.driveD (8, 10);
  /*mueve el robot 8 cm hacia atrás a una velocidad de 10 rpm*/
  mirobot.driveD (-8, 10);
  /*gira el robot 45 grados hacia la derecha a una velocidad de 10 rpm*/
  mirobot.turnA (45, 10);
  /*gira el robot 45 grados hacia la izquierda a una velocidad de 10 rpm*/
  mirobot.turnA (-45, 10);

}

void loop() {
  // put your main code here, to run repeatedly:


}
