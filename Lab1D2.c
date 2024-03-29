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
#include "botones.h"
#include "ADC.h"
#include "TMR0.h"

//Librerias
//Prototipos de funcion
void setup(void);
//Variables globales
int tmr0_count;
uint8_t contadorB;
//ISR
void __interrupt() isr (void){
    if(INTCONbits.RBIF){            //Interrupcion ONCHANGE PORTB
        PORTB = PORTB;
        INTCONbits.RBIF = 0;
        if(RB0==0)
           PORTD++;
           //contadorB++;
        if(RB1==0)
           PORTD=PORTD-1;
           //contadorB--;
        contadorB=PORTD;
    }
    
    if(T0IF){
        tmr0_count++;
        TMR0 = 177; // se le vuelve a cargar el valor al tmr0
        T0IF = 0; //se apaga la bandera
    }
}

//Funcion principal
void main(void) {
    setup();
    //Loop infinito ************************************************************
    while(1){
        int adcValue;
        adcValue = adc_read();
        if(adcValue > contadorB){
            PORTEbits.RE2 = 0;
        }
        if(adcValue < contadorB){
            PORTEbits.RE2 = 1;
        }
        PORTEbits.RE0 = 0;
        PORTEbits.RE1 = 0;
        
        if(tmr0_count%2 == 0){
            PORTC = display_value(0,adcValue);
            PORTEbits.RE0 = 1;
            PORTEbits.RE1 = 0;
           
        }
        if(tmr0_count%2 == 1){
            PORTC = display_value(1,adcValue);
            PORTEbits.RE0 = 0;
            PORTEbits.RE1 = 1;
        }
    }
    return;
}

//Funciones
void setup(void){
    ANSEL = 0;
    ANSELH = 0;
    TRISA = 1;
    TRISB = 7; //PUERTO B COMO ENTRADA
    TRISC = 0; //PUERTO A COMO SALIDA
    TRISD = 0;
    TRISE = 0;
    PORTB = 0;
    PORTC = 0; //LED APAGADOS
    PORTD = 0;
    PORTE = 0;
    ioc_init(0);    //Portb0 BOTON LISTO
    ioc_init(1);    //Portb1 BOTON LISTO
    adc_init(0);    
    
    tmr0_conf(0, 7, 177);
    tmr0_interrupt();
    
    
}