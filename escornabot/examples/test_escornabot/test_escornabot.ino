#include <escornabot.h>

escornabot mirobot;

//const int echoPin = 12;
//const int triggerPin = 11;
boolean funciona = false;

void setup() {
  //Serial.begin(9600);
  mirobot.us(11,12);
 }

void loop() {

  compruebaBoton();

  if (funciona == true) {

    
    if (mirobot.distance()> 15) {
      mirobot.driveD(-5, 12);

    }
    else if (mirobot.distance()<= 15) {

      mirobot.driveD (5, 12);
      mirobot.turnA (-45, 12);

    }


  }

  else if (funciona == false) {
    mirobot.Stop();
  }

}

void compruebaBoton () {
  if (mirobot.pushButton() == right) {
    funciona = !funciona;
    delay (300);
  }
}
