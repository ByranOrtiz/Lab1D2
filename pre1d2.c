/*
 * File:   Pre1.c
 * Author: Bryan Ortiz
 *
 * Created on July 18, 2023, 2:37 PM
 * Contador 8 bits con 2 botones
 */

//Palabra de configuracion
#pragma config FOSC = INTRC_NOCLKOUT// Oscillator Selection bits (INTOSCIO oscillator: I/O function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = ON        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

#include <xc.h>

//Librerias
//Prototipos de funcion
void setup(void);
//Variables globales
//ISR
void __interrupt() isr (void){
    if(INTCONbits.RBIF){            //Interrupcion ONCHANGE PORTB
        PORTB = PORTB;
        INTCONbits.RBIF = 0;
        if(RB0==0)
           PORTA++;
        if(RB1==0)
           PORTA=PORTA-1;
    }
}

//Funcion principal
void main(void) {
    setup();
    //Loop infinito ************************************************************
    while(1){
        //if(RB0=0)
          //  PORTA++;
        //if(RB1=0)
          //  PORTA--;
    }
    return;
}

//Funciones
void setup(void){
    ANSEL = 0;
    ANSELH = 0;
    TRISB = 7; //PUERTO B COMO ENTRADA
    TRISA = 0; //PUERTO A COMO SALIDA
    PORTB = 0;
    PORTA = 0; //LED APAGADOS
    OPTION_REGbits.nRBPU = 0;   // Activo pull ups generales
    WPUBbits.WPUB0 = 1;         // Activo pull up B0
    WPUBbits.WPUB1 = 1;         // Activo pull up B1
    WPUBbits.WPUB2 = 1;         // Activo pull up B2

    INTCONbits.GIE = 1;
    INTCONbits.RBIE = 1;        // Activo interrupción de botón
    INTCONbits.RBIF = 0;        // Apago bandera de interrupción
    IOCBbits.IOCB0 = 1;         // INTERRUPCIÓN PORTB activada
    IOCBbits.IOCB1 = 1;         // INTERRUPCIÓN PORTB activada
}