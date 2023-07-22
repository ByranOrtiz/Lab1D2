/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */
#include "botones.h"

void ioc_init(char pin){
    INTCONbits.GIE = 1;         //Interrupcioes globales
    INTCONbits.RBIE = 1;        // Activo interrupción de botón
    INTCONbits.RBIF = 0;        // Apago bandera de interrupción
    OPTION_REGbits.nRBPU = 0;   // Activo pull ups generales
    switch (pin){
        case 0:
            IOCBbits.IOCB0 = 1;         // INTERRUPCIÓN PORTB activada
            WPUBbits.WPUB0 = 1;         // Activo pull up B0
            break;
        case 1:
            IOCBbits.IOCB1 = 1;         // INTERRUPCIÓN PORTB activada
            WPUBbits.WPUB1 = 1;         // Activo pull up B1
            break;
        case 2:
            IOCBbits.IOCB2 = 1;         // INTERRUPCIÓN PORTB activada
            WPUBbits.WPUB2 = 1;         // Activo pull up B2
            break;
        case 3:
            IOCBbits.IOCB3 = 1;         // INTERRUPCIÓN PORTB activada
            WPUBbits.WPUB3 = 1;         // Activo pull up B3
            break;
        case 4:
            IOCBbits.IOCB4 = 1;         // INTERRUPCIÓN PORTB activada
            WPUBbits.WPUB4 = 1;         // Activo pull up B4
            break;
        case 5:
            IOCBbits.IOCB5 = 1;         // INTERRUPCIÓN PORTB activada
            WPUBbits.WPUB5 = 1;         // Activo pull up B5
            break;
        case 6:
            IOCBbits.IOCB6 = 1;         // INTERRUPCIÓN PORTB activada
            WPUBbits.WPUB6 = 1;         // Activo pull up B6
            break;
        case 7:
            IOCBbits.IOCB7 = 1;         // INTERRUPCIÓN PORTB activada
            WPUBbits.WPUB7 = 1;         // Activo pull up B7
            break;
    }
}
