#include<lpc17xx.h>
#include "LCDLIBRARY.h"

int main()
{
unsigned char val;

LPC_SC->PCONP |= (1<<3);
LPC_SC->PCLKSEL0 |= (1<<6);
LPC_PINCON->PINSEL0 |= (1<<4)|(1<<6);
//config 80 bit ode
LPC_UART0->LCR |= (1<<0)|(1<<1)|(1<<7);
//config baud rate
LPC_UART0->DLL = 24;
LPC_UART0->DLM = 0;
LPC_UART0->FDR |= (15<<4)|(1<<0);
LPC_UART0->LCR &=~(1<<7);
lcd_config();
while(1)
{
while(!(LPC_UART0->LSR &(1<<0)));
val = LPC_UART0->RBR;
lcd_data(val);
while(!LPC_UART0->LSR &(1<<5));
LPC_UART0->THR=val;
}
}
