# TODO - NOME_DO_PROJETO

## Setup inicial
- [ ] Definir clock/fuses do PIC16F628A no projeto MPLAB X
- [ ] Compilar `src/main.c` sem warnings
- [ ] Gravar firmware e validar blink em `RB0`

## Próximos estudos
- [ ] Criar `gpio.c`/`gpio.h` com funções utilitárias
- [ ] Adicionar delay baseado em timer (evitar delay fixo longo)
- [ ] Implementar LCD HD44780U em 4 bits
- [ ] Criar exemplo de leitura de botão em `RA0`

## Validação de hardware
- [ ] Confirmar alimentação estável (5V)
- [ ] Verificar resistor do LED (220Ω a 1kΩ)
- [ ] Validar aterramento comum entre gravador e placa

## Documentação
- [ ] Inserir datasheet oficial em `datasheets/`
- [ ] Completar tabela de pinos e funções em `docs/pinagem-e-mapeamento.md`
