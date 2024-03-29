/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef TMR0_H
#define	TMR0_H

#include <xc.h> // include processor files - each processor file is guarded.  

void tmr0_conf(int assignment, int prescaler, int preload);
void tmr0_interrupt(void);

#endif	/* TRM0_H */

