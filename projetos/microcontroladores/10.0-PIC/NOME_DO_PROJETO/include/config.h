#ifndef CONFIG_H
#define CONFIG_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

// Ajuste a frequência de clock de acordo com sua configuração real.
#ifndef _XTAL_FREQ
#define _XTAL_FREQ 4000000UL
#endif

// Mapeamento didático de pinos usados no projeto base.
#define LED_TESTE_PORT PORTBbits.RB0
#define LED_TESTE_TRIS TRISBbits.TRISB0

void mcu_init(void);

#endif // CONFIG_H
