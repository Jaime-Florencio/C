#include "config.h"

/*
 * Exemplo inicial:
 * - Configura o PIC16F628A para uso digital
 * - Pisca LED em RB0
 */
int main(void)
{
    mcu_init();

    while (1)
    {
        LED_TESTE_PORT = 1;
        __delay_ms(300);

        LED_TESTE_PORT = 0;
        __delay_ms(300);
    }

    return 0;
}
