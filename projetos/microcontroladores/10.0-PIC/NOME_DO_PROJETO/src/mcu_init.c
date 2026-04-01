#include "config.h"

/*
 * Inicialização mínima para laboratório didático.
 */
void mcu_init(void)
{
    // Desativa comparadores para usar pinos como digitais.
    CMCON = 0x07;

    // Todas as portas começam em nível baixo.
    PORTA = 0x00;
    PORTB = 0x00;

    // Direção dos pinos:
    // 1 = entrada, 0 = saída
    TRISA = 0xFF;   // Mantém PORTA como entrada no exemplo inicial
    TRISB = 0x00;   // PORTB como saída

    // Garante que RB0 é saída para o LED de teste.
    LED_TESTE_TRIS = 0;
}
