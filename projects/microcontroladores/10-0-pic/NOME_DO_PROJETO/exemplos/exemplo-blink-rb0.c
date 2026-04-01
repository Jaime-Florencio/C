/*
 * Exemplo isolado de blink em RB0.
 * Pode ser usado para testes rápidos sem toda a estrutura do projeto.
 */

#include <xc.h>
#define _XTAL_FREQ 4000000UL

void main(void)
{
    CMCON = 0x07;
    TRISBbits.TRISB0 = 0;

    while (1)
    {
        PORTBbits.RB0 = 1;
        __delay_ms(500);
        PORTBbits.RB0 = 0;
        __delay_ms(500);
    }
}
