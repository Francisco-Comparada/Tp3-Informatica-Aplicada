/*
 * MEF.h
 *
 *  Created on: 19 jul. 2022
 *      Author: franc
 */

#ifndef MEF_H_
#define MEF_H_

#include "IA_board_KL43.h"

#define T_ENC 700000 //TIEMPO DE PRENDIDO DE LOS LEDS

typedef enum{//ESTADOS POSIBLES DE LA MEF
	Estado_inicial,
	Semaforo,
	Avenida,
	Calle,
	Tren
}estado_t;

void mef (void);

#endif /* MEF_H_ */
