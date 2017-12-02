# Autoría
*Prudencio Luna* y *Pedro Ruiz*

# Control de Versiones
- 0.11 (19/11/2017): se añade procedimiento blueT(), para conocer el datos recibido por bluetooth.
- 0.1 (8/11/2017): primera versión del programa, incorpora control de motores paso a paso (avances, retrocesos, giros, parada), elección del tipo de excitación de bobinas, control de leds, zumbador y botonera.
# Librería para arduino Escornabot
Repositorio para albergar librería para manejar de forma amigable los motores paso a paso de Escornabot.

![](images/escornabot.jpg "escornabot")
## Antecedentes
Unos de los problemas de escornabot es la ausencia de instrucciones amigables en arduino para controlar sus elementos (motores paso a paso, botonera, leds y zumbador), todo ello pensando en el acercamiento del uso de dicho robot para estudiantes de secundaria. Por este motivo desde el club de Tecnología, programación y robótica de Granada nos planteamos desarrollar una librería para dicho fin.
## Librería
La librería debemos cargar en arduino por los métodos tradicionales, incluyendo el zip o copiandola descomprimida en la carpeta "libraries" de arduino.
### procedimientos
- **drive (vueltas, velocidad)**: Sirve para avanzar o retroceder. Se mueve el número de vueltas indicado, si son negativas va en el sentido contrario. La velocidad se da rpm
- **turn (vueltas, velocidad)**: Sirve para girar. Se indica como antes el número de vueltas o fracción a girar, si son positivas gira en un sentido y negativas en el contrario. La velocidad se da en rpm.
- **stop ()**: detiene los dos motores.
- **ledON (número de led)**: sirve para encender los leds de escornabot. Los leds son: 3(ambar, posición delantera), 1 (azul, posición trasera), 2 (rojo, posición derecha), y 4 (verde, posición izquierda).
- **ledOFF (número de led)**: sirve para apagar los leds de escornabot.
- **buzzON ()**: enciende el zumbador.
- **buzzOFF ()**: apaga el zumbador.
- **pushButton()**: devuelve el valor del botón pulsado. 3 delantero, 1 trasero, 2 derecha, 4 izquierda, 5 central.
- **blueT()**: devuelve el valor numérico correspondiente a el carácter enviado por bluetooth a escornabot.

### Ejemplo de código de test
~~~
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

		case 3: //si pulsamos el botón delantero, se enciende led delantero, se mueve 1/4 de vuelta hacia delante, y se apaga el led delantero
    		mirobot.ledON (3);
		    mirobot.drive (0.25, 10);
    		mirobot.ledOFF (3);
			break;  		

		case 1://si pulsamos el botón trasero, se enciende led trasero, se mueve 1/4 de vuelta hacia atrás, y se apaga el led trasero
    		mirobot.ledON (1);
    		mirobot.drive (-0.25, 10);
    		mirobot.ledOFF (1);
  			break;

  		case 2://si pulsamos el botón derecho, se enciende led derecho, se mueve 1/8 de vuelta hacia la derecha, y se apaga el led derecho
    		mirobot.ledON (2);
    		mirobot.turn (0.125, 10);
    		mirobot.ledOFF (2);
		    break;

  	   case 4://si pulsamos el botón izquierdo, se enciende led izquierdo, se mueve 1/8 de vuelta hacia la izquierda, y se apaga el led izquierdo
    	 	mirobot.ledON (4);
    		mirobot.turn (-0.125, 10);
		    mirobot.ledOFF (4);
			break;

	  case 5://si pulsamos el botón central, suena le zumbador y se enciende todos los leds durante un segundo, después se apagan el zumbador y los leds
    		mirobot.buzzON ();
    		for (int i = 1; i < 5; i++)
    		{
      		mirobot.ledON(i);
    		}
		    delay (1000);
		    mirobot.buzzOFF();

    		for (int i = 1; i < 5; i++)
    		{
      		mirobot.ledOFF(i);
    		}

  }

  switch (mirobot.blueT()) {
  	case 'A':
    	mirobot.drive (0.25,12);
    	break;
  	case 'R':
    	mirobot.drive (-0.25,12);
    	break;
  	case 'D':
    	mirobot.turn (0.125,12);
    	break;
  	case 'I':
    	mirobot.turn (-0.125,12);
    	break;
  	case '1':
    	led1 = !led1;
    	  if(led1) {
    	    mirobot.ledON(1);
    	  }
    	  else {
    	    mirobot.ledOFF(1);
    	  }    
    	break;
  	case '2':
    	led2 = !led2;
    	  if(led2) {
    	    mirobot.ledON(2);
    	  }
    	  else {
    	    mirobot.ledOFF(2);
    	  }
    	break;
  	case '3':
    	led3 = !led3;
    	  if(led3) {
    	    mirobot.ledON(3);
    	  }
    	  else {
    	    mirobot.ledOFF(3);
    	  }
    	break;
  	case '4':
    	led4 = !led4;
    	  if(led4) {
    	    mirobot.ledON(4);
    	  }
    	  else {
    	    mirobot.ledOFF(4);
    	  }
    	break;
  	case '5':
    	buzz = !buzz;
    	  if(buzz) {
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
~~~
