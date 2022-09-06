/*
 * IA_board_KL43.h
 *
 *  Created on: 19 jul. 2022
 *      Author: franc
 */

#ifndef IA_BOARD_KL43_H_
#define IA_BOARD_KL43_H_


#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL43Z4.h"
#include "fsl_debug_console.h"
/*==================[cplusplus]==============================================*/
#ifdef __cplusplus
extern "C" {
#endif

void board_init(void);

#define LED_ROJO_TOGGLE		GPIOE->PTOR |= (1 << 31)
#define LED_ROJO_OFF		PTE->PSOR   |= (1 << 31)
#define LED_ROJO_ON			GPIOE->PCOR |= (1 << 31)

#define LED_VERDE_TOGGLE	GPIOD->PTOR |= (1 << 5)
#define LED_VERDE_OFF		GPIOD->PSOR |= (1 << 5)
#define LED_VERDE_ON		GPIOD->PCOR |= (1 << 5)

void ledRojo_init(void);
// inicializacion del LED Rojo
void ledVerde_init(void);
// inicializacion del LED Verde

//SW1
#define SW1_PIN 	4
#define SW1_GPIO 	PTA
#define SW1_PORT 	PORTA
#define SW1_CLOCK 	SIM->SCGC5              |= SIM_SCGC5_PORTA_MASK
#define	SW1_MODE 	SW1_PORT->PCR[SW1_PIN]  |= PORT_PCR_MUX(1)
#define SW1_INPUT	SW1_GPIO->PDDR 			&= ~( 1<<SW1_PIN )

//SW3
#define SW3_PIN 3
#define SW3_GPIO PTC
#define SW3_PORT PORTC
#define SW3_CLOCK SIM->SCGC5                |= SIM_SCGC5_PORTC_MASK								//Asigno clock al puerto
#define	SW3_MODE SW3_PORT->PCR[SW3_PIN]     |= PORT_PCR_MUX(1)										//Configuro el mux para GPIO
#define SW3_INPUT SW3_GPIO->PDDR 		    &= ~( 1<<SW3_PIN )										//Pulsador como entrada


void pulsadorSw1_init(void);
//inicializacion del pulsador SW1
void pulsadorSw3_init(void);
//inicializacion del pulsador SW3

int8_t pulsadorSw1_get(void);

int8_t pulsadorSw3_get(void);

#endif /* IA_BOARD_KL43_H_ */
