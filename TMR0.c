/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */
#include "TMR0.h"

void tmr0_conf(int assignment, int prescaler, int preload){
    //CONF TMR0
    //assignment de ser 0 o 1
    //prescaler deber ser entre 0 y 7
    //preload deber ser de 0 a 255
    OPTION_REGbits.T0CS = 0;  //bit 5 clock souce select bit FOSC/4
    OPTION_REGbits.PSA =  assignment;  //bit 6 prescaler is to TMR0 
    OPTION_REGbits.PS =  prescaler; //prescaler 1:2
    TMR0 = preload ; //valor de tmr0 va a ser 236
}

void tmr0_interrupt(void){
    INTCONbits.T0IF = 0; //BANDERA DE INTERRUPCION 
    INTCONbits.T0IE = 1;  // periferico
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;  //global
}
