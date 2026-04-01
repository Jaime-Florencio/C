# NOME_DO_PROJETO (PIC16F628A)

Projeto didático para estudo de microcontroladores **PIC16F628A**, com foco em:
- configuração de portas digitais;
- desativação de comparadores via `CMCON`;
- organização de código para reutilização;
- base para expansão com LCD HD44780U em modo 4 bits.

## Objetivo
Criar uma base limpa para testar periféricos e conceitos fundamentais de firmware em PIC:
1. configuração inicial do MCU;
2. mapeamento de pinos e registradores;
3. laço principal simples e fácil de entender;
4. exemplos isolados para estudo incremental.

## Estrutura do projeto
- `src/`: código principal (`main.c` e módulos de inicialização);
- `include/`: headers com protótipos, defines e mapeamentos;
- `docs/`: anotações técnicas e mapeamento de registradores/pinos;
- `datasheets/`: PDFs e referências oficiais (placeholder);
- `exemplos/`: variações pequenas para testes de conceitos;
- `sim/`: esquemas, simulações e imagens do circuito;
- `TODO.md`: pendências, próximos passos e checklist de aprendizado.

## Dependência de hardware
- Microcontrolador: **PIC16F628A**
- Ferramentas sugeridas: XC8 + MPLAB X
- Clock: definir conforme montagem (interno/externo)
- Componentes mínimos para teste inicial:
  - 1 LED + resistor (teste em `RB0`)
  - fonte 5V estável
  - gravador compatível com PIC

## Mapeamento inicial de registradores e pinos
### Registradores usados na base
- `TRISA` / `TRISB`: direção dos pinos (1 = entrada, 0 = saída)
- `PORTA` / `PORTB`: leitura/escrita digital
- `CMCON`: desativa comparadores (`CMCON = 0x07`) para uso digital

### Pinos do exemplo base
- `RB0`: saída digital para LED de teste

> Observação: ajuste os fuses e clock conforme sua placa/bancada.

## Como evoluir este projeto
1. confirmar blink em `RB0`;
2. adicionar camada de GPIO utilitária;
3. integrar driver de LCD HD44780U (4 bits);
4. criar exemplos separados por tema em `exemplos/`.
