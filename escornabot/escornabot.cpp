/*
Librería escornabot por Prudencio Luna y Pedro Ruiz
V 0.1 (8/11/2017): primera versión del programa, incorpora control de motores paso a paso (avances, retrocesos, giros, parada)
, elección del tipo de excitación de bobinas, control de leds, zumbador y botonera.
*/

#include "Arduino.h"
#include "escornabot.h"

// Declaración y asignación de variables privadas
	
int step [4][4] =//matriz que describe puesta en marcha de bobinas por defecto (4 posiciones)
		{
	  	{1, 0, 0, 0},
	  	{0, 1, 0, 0},
	  	{0, 0, 1, 0},
	  	{0, 0, 0, 1}
		};	

	int stepsLap=2048;//nº de pasos que da en una vuelta
	int stepsDone=0;//cuenta los pasos dados
	int coilPosition=0;// devuelve la posición de la bobina en cada paso (4 posiciones)      

/*Pinout*/
const int pinMotor[8]={2,3,4,5,6,7,8,9};//pines de motores
const int buzz = 10; //pin del zumbador
const int led[4] = {14,15,16,17}; // 1 Azul, blue;2 Rojo, red;3 Amarillo, yellow;4 Verde, green
const int pushButtons = A7; //Es una variable analógica. En un circuito paralelo que en función de la tecla que pulsemos obtenemos un valor analógico distinto

/*Valores aproximados que se obtienen al accionar los pulsadores*/
int up = 768; 
int down = 512;
int left = 882;
int right = 683;
int center = 819;



/*
 escornabot constructor sin pasar parámetros
 */

escornabot::escornabot() //si no se pasan prámetros al constructor por defecto coge el paso 1 (1 sóla bobina a la vez)
{
//se inicializa las comunicaciones serie a 9600 baudios (para bluetooth)
	Serial.begin (9600);//iniciamos las comunicaciones 
//se definen los pines de motores de escornabot como de salida
	for (int i=0;i<8;i++) {
		pinMode(pinMotor [i],OUTPUT); 
	}
//se definen los pines de los leds como salida
	for(int i=0; i<4; i++){
    pinMode(led[i], OUTPUT);
  	}
//se define el pin del zumbador como salida
    pinMode(buzz, OUTPUT);
// se define el pin analógico de entrada de pulsadores tipo PULL UP
  	pinMode(pushButtons,INPUT_PULLUP);

}//escornabot

/*
 escornabot constructor pasando tipo de paso de bobina 1 o 2.
 */

escornabot::escornabot(int kindStep) //aquí se construye el objeto escornabot con el tipo de paso (excitación de bobinas) 1 o 2
{
//se inicializa las comunicaciones serie a 9600 baudios (para bluetooth)
	Serial.begin (9600);//iniciamos las comunicaciones 
//se definen los pines de motores de escornabot como de salida
	for (int i=0;i<8;i++) {
		pinMode(pinMotor [i],OUTPUT); 
	}
//se definen los pines de los leds como salida
	for(int i=0; i<4; i++){
    pinMode(led[i], OUTPUT);
  	}
//se define el pin del zumbador como salida
    pinMode(buzz, OUTPUT);
// se define el pin analógico de entrada de pulsadores tipo PULL UP
  	pinMode(pushButtons,INPUT_PULLUP);
//comprueba el parámetro pasado de tipo de paso de bobina	

	if (kindStep==1) {// se excita una bobina cada vez
		int step [4][4] =//matriz que describe orden de excitación de bobinas (4 posiciones)
		{
	  	{1, 0, 0, 0},
	  	{0, 1, 0, 0},
	  	{0, 0, 1, 0},
	  	{0, 0, 0, 1}
		};
	}
	if (kindStep==2) {// se excitan dos bobinas a la vez
		int step [4][4] =//matriz que describe orden de excitación de bobinas (4 posiciones)
		{
	  	{1, 1, 0, 0},
	  	{0, 1, 1, 0},
	  	{0, 0, 1, 1},
	  	{1, 0, 0, 1}
		};
	}
}//escornabot


/*
dirve procedimiento para avanzar y retroceder
*/

void escornabot::drive (float laps, int speed) {//vueltas son el nº de vueltas a dar (+ avanza o - retrocede) y velocidad en rpm

	stepsDone=0;
	if (laps>=0) {//si las vueltas son positivas las bobinas se excitan en el sentido de avance
		while (int(laps*stepsLap)>=stepsDone)  {
     		stepsDone ++;
     		coilPosition=stepsDone % 4;//calcula el resto para saber en la posición de bobina que está
      		digitalWrite(pinMotor[0], step[coilPosition][3]);
      		digitalWrite(pinMotor[4], step[coilPosition][0]);
      		digitalWrite(pinMotor[1], step[coilPosition][2]);
      		digitalWrite(pinMotor[5], step[coilPosition][1]);
      		digitalWrite(pinMotor[2], step[coilPosition][1]);
      		digitalWrite(pinMotor[6], step[coilPosition][2]);
      		digitalWrite(pinMotor[3], step[coilPosition][0]);
      		digitalWrite(pinMotor[7], step[coilPosition][3]);
      		delayMicroseconds(29297/speed);//velocidad en rpm 29297 es el nº de microsegundos que tardaría en dar 2048 pasos (una vuelta) en un minuto
    	}
	}

	else {//si las vueltas son negativas las bobinas se excitan en el sentido de retroceso
		while (int(-laps*stepsLap)>=stepsDone)  {
     		stepsDone ++;
     		coilPosition=stepsDone % 4;
      		digitalWrite(pinMotor[0], step[coilPosition][0]);
      		digitalWrite(pinMotor[4], step[coilPosition][3]);
      		digitalWrite(pinMotor[1], step[coilPosition][1]);
      		digitalWrite(pinMotor[5], step[coilPosition][2]);
      		digitalWrite(pinMotor[2], step[coilPosition][2]);
      		digitalWrite(pinMotor[6], step[coilPosition][1]);
      		digitalWrite(pinMotor[3], step[coilPosition][3]);
      		digitalWrite(pinMotor[7], step[coilPosition][0]);
      		delayMicroseconds(29297/speed);
    	}
  
	}

}//drive


/*
stop procedimiento de paro de los motores
 */

void escornabot::stop () {

	for (int i=0; i<8; i++) {
	digitalWrite (pinMotor[i],LOW);
	}

}//stop

/*
turn procedimiento para girar
*/

void escornabot::turn (float laps, int speed) {//vueltas son el nº de vueltas a girar (+ en un sentido o - en el otro) y velocidad en rpm

	stepsDone=0;
	if (laps>=0) {//si las vueltas son positivas provoca giro a la derecha moviendo rueda izquierda adelante y derecha atrás
		while (int(laps*stepsLap)>=stepsDone)  {
			stepsDone ++;
			coilPosition=stepsDone % 4;
			digitalWrite(pinMotor[0], step[coilPosition][0]);
			digitalWrite(pinMotor[4], step[coilPosition][0]);
			digitalWrite(pinMotor[1], step[coilPosition][1]);
			digitalWrite(pinMotor[5], step[coilPosition][1]);
			digitalWrite(pinMotor[2], step[coilPosition][2]);
			digitalWrite(pinMotor[6], step[coilPosition][2]);
			digitalWrite(pinMotor[3], step[coilPosition][3]);
			digitalWrite(pinMotor[7], step[coilPosition][3]);
			delayMicroseconds(29297/speed);
		}

	}

	else {//si las vueltas son negativas provoca giro a la izquierda moviendo rueda derecha adelante e izquierda atrás
		while (int(-laps*stepsLap)>=stepsDone)  {
			stepsDone ++;
			coilPosition=stepsDone % 4;
			digitalWrite(pinMotor[0], step[coilPosition][3]);
			digitalWrite(pinMotor[4], step[coilPosition][3]);
			digitalWrite(pinMotor[1], step[coilPosition][2]);
			digitalWrite(pinMotor[5], step[coilPosition][2]);
			digitalWrite(pinMotor[2], step[coilPosition][1]);
			digitalWrite(pinMotor[6], step[coilPosition][1]);
			digitalWrite(pinMotor[3], step[coilPosition][0]);
			digitalWrite(pinMotor[7], step[coilPosition][0]);
			delayMicroseconds(29297/speed);
		}
  
	}

}//turn

/*
 *ledON procedimiento para encender leds 
 * */
void escornabot::ledON(int ledNumber){
  digitalWrite(led[ledNumber-1], HIGH);
}//ledON

/*
 * ledOFF procedimiento para apagar leds
 * */
void escornabot::ledOFF(int ledNumber){
  digitalWrite(led[ledNumber-1], LOW);
}//ledOFF

/*
 * buzzON procedimiento para encender zumbador
 * */
void escornabot::buzzON(void){
  digitalWrite(buzz,HIGH);
}//buzzON

/*
 * buzzOFF procedimiento para apagar zumbador
 * */
void escornabot::buzzOFF(void){
  digitalWrite(buzz,LOW);
}//buzOFF

/*
 * pushButton procedimiento para determinar el pulsador pulsado
 * */
int escornabot::pushButton(void){
  if(analogRead(pushButtons)>= 748 && analogRead(pushButtons)<=788) {//adelante
    return 3;
  }
  if(analogRead(pushButtons)>= 492 && analogRead(pushButtons)<=532) {//atrás
    return 1;
  }
  if(analogRead(pushButtons)>= 862 && analogRead(pushButtons)<=902) {//izquierda
    return 4;
  }
  if(analogRead(pushButtons)>= 663 && analogRead(pushButtons)<=703) {//derecha
    return 2;
  }
  if(analogRead(pushButtons)>= 799 && analogRead(pushButtons)<=839) {//centro
    return 5;
  }
  else {
    return 0;     
  }
}//pushButton

/*
 * blueT procedimiento para saber el caracter que me han mandado por Bluetooth
 * */
int escornabot::blueT(void){
if (Serial.available()>0) {
	    int dato=Serial.read();
		return dato;
	}
else return 0;

}//blueT

/*
  version() procedimiento que devuelve la versión de la librería
*/
int escornabot::version(void)
{
  return 0.1;
}
