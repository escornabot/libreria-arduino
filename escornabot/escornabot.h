/*
Librería escornabot por Prudencio Luna y Pedro Ruiz
V 0.15 (16/04/2019): quinta versión, se puede mover los motores mediante procedimiento de medio paso (tipo 3) y se corrigen fallos en constructor con parámetros para elegir modos de paso.
V 0.14 (14/04/2019): cuarta versión del programa, cambiado nombre de procedimiento stop por Stop, se arregla procedimineto versión en .h, cambios en procedimiento pushButton, cambios en archivo de ejemplo.
V 0.13 (07/03/2018): tercera versión del programa, incorpora control de motores paso a paso (avances, retrocesos, giros, parada)
, elección del tipo de excitación de bobinas, control de leds, zumbador, botonera y bluetooth.
*/

#ifndef escornabot_h
#define escornabot_h

enum buttonLed {forward=1,left=2,backward=3,right=4,central=5};

// Descripción de la clase Escornabot
class escornabot {
  //Definición de elementos públicos
  public:
  // constructor:
 	escornabot();//sin pasar parámetros
	escornabot(int kindStep);// pasa el tipo de paso 1 (un sola bobina a la vez), paso 2 (dos bobinas a la vez)

	const static int numberButtons=5;
	const static int numberLeds=5;

	// procedimiento para mover los motores:
    	void drive (float laps, int speed);
	//procedimiento para mover los motores por distancia
	void driveD (float distance, int speed); 
	//procemiento para girar con vueltas:
	void turn (float laps, int speed);
	//procedimiento para girar con ańgulo:    
	void turnA (float angle, int speed);
    	// procedimiento para parar:
  	void Stop();
	//procedimiento para encender y apagar leds, y saber estado
  	void ledON(int ledNumber);
  	void ledOFF(int ledNumber);
  	int ledState(int ledNumber);
	//procedimiento para encender y apagar el zumbador
	void buzzON();
	void buzzOFF();
	//procedimiento para saber el botón que se ha pulsado
	int pushButton();
	//procedimiento que devuelve valor enviado por bluetooth
	int blueT();
	//procedimiento que devuelve la versión de la librería
	float version();
  protected:


  //Definición de elementos privados
  private:


};

#endif //escornabot_h
