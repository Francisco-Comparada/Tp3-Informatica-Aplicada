#include "IA_board_KL43.h"

void board_init(void){
	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
    /* Init FSL debug console. */
    BOARD_InitDebugConsole();
#endif
}

void ledRojo_init(void){
	/* Activacion de clock para el puerto utilizado */
	SIM->SCGC5 |= SIM_SCGC5_PORTE_MASK;

	/* asigna funcionalidad gpio a PTE29 (pag.: 193) */
	PORTE->PCR[31] = PORT_PCR_MUX(1);

	LED_ROJO_OFF;

	/* PTE29 como salida -> led rojo (pag.: 835) */
	GPIOE->PDDR |= (1 << 31);
}

void ledVerde_init(void){
	/* Activacion de clock para el puerto utilizado */
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;

	/* asigna funcionalidad gpio a PTD5 */
	PORTD->PCR[5] = PORT_PCR_MUX(1);

	LED_VERDE_OFF;

	/* PTD5 como salida -> led verde */
	GPIOD->PDDR |= (1 << 5);
}

void pulsadorSw1_init(void){
	// Configuramos los relojes
		SW1_CLOCK;
	// Configuramos los mux de los pines
		SW1_MODE;
	// Configuramos redistencias Pull Up
		SW1_PORT->PCR[SW1_PIN]  |= (1 << PORT_PCR_PE_SHIFT) | (1 << PORT_PCR_PS_SHIFT);
		SW1_GPIO->PDDR 			&= ~( 1<<SW1_PIN );				//Configuramos como entrada
}

void pulsadorSw3_init(void){
	// Configuramos los relojes
		SW3_CLOCK;
	// Configuramos los mux de los pines
		SW3_MODE;
	// Configuramos redistencias Pull Up
		SW3_PORT->PCR[SW3_PIN]  |= (1 << PORT_PCR_PE_SHIFT) | (1 << PORT_PCR_PS_SHIFT);
		SW3_GPIO->PDDR 			&= ~( 1<<SW3_PIN );				//Configuramos como entrada
}


int8_t pulsadorSw1_get(void){
	return ((SW1_GPIO->PDIR & (1<<SW1_PIN))?0:1);
}

int8_t pulsadorSw3_get(void){
	return ((SW3_GPIO->PDIR & (1<<SW3_PIN))?0:1);
}
