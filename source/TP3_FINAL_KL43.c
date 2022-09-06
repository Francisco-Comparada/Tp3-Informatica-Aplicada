#include <stdio.h>
#include "IA_board_KL43.h"
#include "MEF.h"
int main(void) {
	//INICIALIZACION PLACA
	 /* Init board hardware. */
		board_init();
		ledRojo_init();//INICIALIZACION LED ROJO-APAGADO
		ledVerde_init();//INICIALIZACION LED VERDE-APAGADO
		pulsadorSw1_init();//INICIALIZACION PULSADOR 1
		//pulsadorSw3_init(); //no usamos

	while(1){
		mef();//LLAMO A LA FUNCION

}
    return 0 ;
}
