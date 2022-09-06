#include "MEF.h"

void mef(){
	static estado_t estado_actual; // SON DE TIPO STATIC PARA QUE CUANDO ENTRE AL SWITCH ESTE CON EL VALOR ANTERIOR
	static estado_t estado_proximo=Estado_inicial;// INICIALIZADA SOLAMENTE PARA EL PRINCIPIO DEL PROGRAMA O
	static int CA=0,AV=0,Temp=0;//CUANDO SE RESETEE

	estado_actual=estado_proximo;

	switch (estado_actual){
	 case Estado_inicial: //INICIALIZA LOS ESTADOS PARA QUE EL PRIMERO EN VERDE SEA AVENIDA,
		 //Y EL TEMPORIZADOR ESTE EN 0
		 Temp=0;
		 AV=1;
		 CA=0;
		 estado_proximo = Semaforo;
		 break;

	 case Semaforo: // ESTADO QUE DECIDE QUE SEMAFORO HAY QUE PONER EN VERDE Y CUAL EN ROJO
		 if(AV==1){
			 LED_VERDE_ON;
			 //APAGAR LED ROJO AVENIDA NO HAY led en la placa
			 estado_proximo = Avenida;
			 break;
		 }
		 if(CA==1){
			 LED_ROJO_ON; //VERDE
			 //APAGAR LED ROJO CALLE NO HAY led en la placa
			 estado_proximo = Calle;
			 break;
		 }


	 case Avenida: // ESTADO CUANDO LA AVENIDA ESTA EN VERDE Y CALLE EN ROJO
		Temp++;//SUMA EL TEMPORIZADOR HASTA LLEGAR A T_ENC
		if(Temp == T_ENC){ //SE MANTIENE EN ESTE ESTADO HASTA QUE SE CUMPLA EL TIEMPO, PASA A PRENDER EL OTRO SEMAFORO
			LED_VERDE_OFF;
			AV=0;
			CA=1;
			Temp=0;//REINICIA TEMPORIZADOR
			estado_proximo=Semaforo;
			break;
		}
		if(pulsadorSw1_get()==1){ // EN CASO DE PULSAR SW1(SIMULA QUE ESTA PASANDO EL TREN) PONE AMBOS SEMAFOROS EN ROJO
			LED_VERDE_OFF;
			LED_ROJO_OFF;
			estado_proximo=Tren;
			break;
		}
		break;
	 case Calle:// ESTADO CUANDO LA CALLE ESTA EN VERDE Y AVENIDA EN ROJO
			Temp++;
			if(Temp == T_ENC){
				LED_ROJO_OFF;
				AV=1;
				CA=0;
				Temp=0;
				estado_proximo=Semaforo;
				break;
			}
			if(pulsadorSw1_get()==1){
				LED_VERDE_OFF;
				LED_ROJO_OFF;
				estado_proximo=Tren;
				break;
			}
			break;

	 case Tren:// ESTADO MIENTRAS SW1 ESTE PULSADO (TREN PASANDO), CUANDO SE DESPULSE PRENDERA EL SEMAFORO EN VERDE
		 // EL QUE ANTERIORMENTE ESTABA EN ROJO
		 if(pulsadorSw1_get()==0 && AV==1){// SI AVENIDA ESTABA EN VERDE
			 CA=1;
			 AV=0;
			 Temp=0;
			 LED_ROJO_ON;
			 estado_proximo=Calle;
				break;
		 }
		 if(pulsadorSw1_get()==0 && CA==1){// SI CALLE ESTABA EN VERDE
			 CA=0;
			 AV=1;
			 Temp=0;
			 LED_VERDE_ON;
			 estado_proximo=Avenida;
			 break;
				 }
	}

}
