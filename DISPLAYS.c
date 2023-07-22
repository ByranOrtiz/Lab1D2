/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */
#include "DISPLAYS.H"

int display_value(int disp, int val){
    if(disp==0) val = val/16; //resultado de division display 1
    if(disp==1) val = val%16; //cociente division display 2
    
    switch (val) {
        case 0:
            val = 0b01000000;
            break;
        case 1:
            val = 0b01111001;
            break;
        case 2:
            val = 0b00100100;
            break;
        case 3:
            val = 0b00110000;
            break;
        case 4:
            val = 0b00011001;
            break;
        case 5:
            val = 0b00010010;
            break;
        case 6:
            val = 0b00000010;
            break;
        case 7:
            val = 0b01111000;
            break;
        case 8:
            val = 0b00000000;
            break;
        case 9:
            val  = 0b00010000;
            break;
        case 10:
            val = 0b00001000;
            break;
        case 11:
            val = 0b00000011;
            break;
        case 12:
            val = 0b01000110;
            break;
        case 13:
            val = 0b00100001;
            break;
        case 14:
            val = 0b00000110;
            break;
        case 15:
            val = 0b00001110;
            break;
    }
    return val;
}