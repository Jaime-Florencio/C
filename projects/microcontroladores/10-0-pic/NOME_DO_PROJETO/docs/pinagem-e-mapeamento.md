# Pinagem e mapeamento - PIC16F628A

## Objetivo deste documento
Centralizar o mapeamento de pinos e registradores usados nos exemplos.

## Registradores principais
| Registrador | Função | Observação |
|---|---|---|
| `TRISA` | Define direção da PORTA | `1 = entrada`, `0 = saída` |
| `TRISB` | Define direção da PORTB | `1 = entrada`, `0 = saída` |
| `PORTA` | Leitura/escrita digital na PORTA | depende da configuração de TRISA |
| `PORTB` | Leitura/escrita digital na PORTB | depende da configuração de TRISB |
| `CMCON` | Controle dos comparadores | `0x07` desativa comparadores |

## Mapeamento inicial do projeto
| Pino | Uso | Tipo |
|---|---|---|
| `RB0` | LED de teste (blink) | Saída |

## Notas de estudo
- Se os comparadores não forem desativados, parte da PORTA pode não funcionar como digital.
- Ajuste o clock antes de validar delays com `__delay_ms()`.
