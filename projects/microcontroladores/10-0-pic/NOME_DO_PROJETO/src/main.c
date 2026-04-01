/* ============================================================================

    Linguagem C, o curso definitivo
    Módulo 10 Aula 0
    Linguagem C para PIC mid-range

    MCU: PIC16F628A
    Clock: externo 4MHz

============================================================================ */


/* ========================================================================= */
/* --- Mapeamento de Hardware --- */
#define      RS       PORTB.B0                             /* pino register select do LCD */
#define      EN       PORTB.B1                             /* pino enable do LCD */
#define      D4       PORTB.B4                             /* pino de dados DB4 do LCD */
#define      D5       PORTB.B5                             /* pino de dados DB5 do LCD */
#define      D6       PORTB.B6                             /* pino de dados DB6 do LCD */
#define      D7       PORTB.B7                             /* pino de dados DB7 do LCD */


/* ========================================================================= */
/* --- Protótipo das Funções --- */
void disp_number(unsigned num, char row, char col);        /* converte um inteiro de até 5 dígitos para exibir no display, remove zeros à esquerda */
void disp_wr_po(unsigned char chr, char row, char col);    /* função para escrever caracteres no LCD na posição indicada */
void disp_text(char *str, char row, char col);             /* função para escrever uma string no LCD */
void disp_write(unsigned char chr);                        /* função para escrever caracteres no LCD */
void disp_cmd(unsigned char cmd);                          /* função para enviar comandos para o LCD*/
void disp_init();                                          /* função para inicializar o LCD */
void disp_clear();                                         /* função para limpar o LCD */
void send_nibble(unsigned char nib, char rsel);            /* envia cada nibble separadamente e gera pulso em enable */


/* ========================================================================= */
/* --- Variáveis Globais --- */
unsigned counter = 0;                          /* auxiliar para teste de envio de números para o display */


/* ========================================================================= */
/* --- Função Principal --- */
void main()
{
  CMCON   = 0x07;                              /* desabilita os comparadores internos */
  TRISB   = 0x0C;                              /* configura IOs no PORTB */
  PORTB   = 0x0C;                              /* inicializa o PORTB */

  disp_init();                                 /* inicializa o display */
  disp_cmd(0x0C);                              /* desliga o cursor e o blink */

  disp_wr_po('W',0,0);                         /* escreve 'W' linha 0, coluna 0 */
  disp_write('R');                             /* escreve 'R' linha 0, coluna 1 */
  disp_text("Kits Projects",1,0);              /* envia string para linha 1, coluna 0 */

  while(1)                                     /* loop infinito */
  {

     disp_number(counter,0,4);                 /* mostra o conteúdo de counter, linha 0, coluna 4 */
     counter++;                                /* incrementa counter */
     delay_ms(741);                            /* taxa de atualização */


  } /* end while */

} /* end main */


/* ========================================================================= */
/* --- Desenvolvimento das Funções --- */

/* ========================================================================= */
/* --- disp_number --- */
/* Converte um inteiro para exibir no display, remove zeros à esquerda */
void disp_number(unsigned num, char row, char col)
{
  char  dem, mil, cen, dez, uni;               /* variáveis para cálculo de cada dígito */
  short  no_zero = 0;                          /* variável local para limpeza de zeros à esquerda */

  dem = (char)(num/10000);                     /* calcula dezenas de milhares */
  mil = (char)(num%10000/1000);                /* calcula milhares */
  cen = (char)(num%1000/100);                  /* calcula centenas */
  dez = (char)(num%100/10);                    /* calcula dezenas */
  uni = (char)(num%10);                        /* calcula unidades */

  if(!dem && !no_zero)                         /* dígito das dezenas de milhares é zero e no_zero está limpa? */
    disp_wr_po(' ',row,col);                   /* sim, imprime um espaço em branco */
  else                                         /* não... */
  {
    disp_wr_po(dem+0x30,row,col);              /* imprime o dígito calculado */
    no_zero = 1;                               /* seta no_zero */
  } /* end else */

  if(!mil && !no_zero)                         /* dígito dos milhares é zero e no_zero está limpa? */
    disp_write(' ');                           /* sim, imprime um espaço em branco */
  else                                         /* não... */
  {
    disp_write(mil+0x30);                      /* imprime o dígito calculado */
    no_zero = 1;                               /* seta no_zero */
  } /* end else */

  if(!cen && !no_zero)                         /* dígito das centenas é zero e no_zero está limpa? */
    disp_write(' ');                           /* sim, imprime um espaço em branco */
  else                                         /* não... */
  {
    disp_write(cen+0x30);                      /* imprime o dígito calculado */
    no_zero = 1;                               /* seta no_zero */
  } /* end else */

  if(!dez && !no_zero)                         /* dígito das dezenas é zero e no_zero está limpa? */
    disp_write(' ');                           /* sim, imprime um espaço em branco */
  else                                         /* não... */
  {
    disp_write(dez+0x30);                      /* imprime o dígito calculado */
    no_zero = 1;                               /* seta no_zero */
  } /* end else */

  disp_write(uni+0x30);                        /* imprime dígito calculado */


} /* end disp_number */


/* ========================================================================= */
/* --- disp_wr_po --- */
/* função para escrever caracteres no LCD na posição indicada */
void disp_wr_po(unsigned char chr, char row, char col)
{
  if(!row)                                     /* linha 0? */
  {                                            /* sim */
    disp_cmd(0x80|col);                        /* envia comando para posicionar na coluna correta */
    disp_write(chr);                           /* escreve o caractere */
  } /* end if */
  else                                         /* senão... */
  {                                            /* linha 1 */
    disp_cmd(0xC0|col);                        /* envia comando para posicionar linha e coluna corretas */
    disp_write(chr);                           /* escreve o caractere */
  } /* end else */

} /* end disp_write */


/* ========================================================================= */
/* --- disp_text --- */
/* função para escrever uma string no LCD */
void disp_text(char *str, char row, char col)
{
  register int i;                              /* variável local para iterações */

  for(i=0; str[i]!='\0';i++,col++)             /* executa até encontrar o caractere nulo */
    disp_wr_po(str[i],row,col);                /* imprime caractere atual da string passada como parâmetro */

} /* end disp_text */


/* ========================================================================= */
/* --- disp_write --- */
/* função para escrever caracteres no LCD */
void disp_write(unsigned char chr)
{
  send_nibble(chr, 1);                         /* envia o nibble mais significativo do caractere, RS em high */
  chr <<= 4;                                   /* atualiza chr para enviar nibble menos significativo */
  send_nibble(chr, 1);                         /* envia o nibble menos significativo do caractere, RS em high */

} /* end disp_write */


/* ========================================================================= */
/* --- disp_cmd --- */
/* função para enviar comandos para o LCD */
void disp_cmd(unsigned char cmd)
{
  send_nibble(cmd, 0);                         /* envia o nibble mais significativo do comando, RS em low */
  cmd <<= 4;                                   /* atualiza chr para enviar nibble menos significativo */
  send_nibble(cmd, 0);                         /* envia o nibble menos significativo do comando, RS em low */

} /* end disp_cmd */


/* ========================================================================= */
/* --- disp_init --- */
/* função para inicializar o LCD */
void disp_init()
{
  delay_ms(48);                                /* tempo para estabilização (datasheet recomenda no mínimo 40ms) */
  send_nibble(0x30,0);                         /* protocolo de inicialização */
  delay_ms(5);                                 /* tempo acima do sugerido pelo datasheet pag.46) */
  send_nibble(0x30,0);                         /* protocolo de inicialização */
  delay_us(150);                               /* tempo acima do sugerido pelo datasheet pag.46) */
  send_nibble(0x30,0);                         /* protocolo de inicialização */
  send_nibble(0x20,0);                         /* lcd no modo de 4 bits */
  disp_cmd(0x28);                              /* 5x8 pontos por caractere, duas linhas */
  disp_cmd(0x0F);                              /* liga display, cursor e blink */
  disp_cmd(0x06);                              /* modo de incremento de endereço para direita */
  disp_clear();                                /* limpa LCD */

} /* end disp_init*/


/* ========================================================================= */
/* --- Limpa LCD --- */
/* função para limpar o LCD */
void disp_clear()
{
  disp_cmd(0x02);                              /* return home */
  disp_cmd(0x01);                              /* limpa o display */

} /* end disp_clear */


/* ========================================================================= */
/* --- send_nibble --- */
/* função para envio de cada nibble separadamente e gerar pulso em enable */
void send_nibble(unsigned char nib, char rsel)
{
  D4 = (nib>>4)&0x01;                          /* envia bit 4 de comando no barramento */
  D5 = (nib>>5)&0x01;                          /* envia bit 5 de comando no barramento */
  D6 = (nib>>6)&0x01;                          /* envia bit 6 de comando no barramento */
  D7 = (nib>>7)&0x01;                          /* envia bit 7 de comando no barramento */
  RS = rsel;                                   /* atualiza RS (1 para envio de dados, 0 para envio de comandos */

  /* -- Pulse Enable -- */
  EN = 1;                                      /* seta EN */
  delay_us(1200);                              /* aguarda 1200µs */
  EN = 0;                                      /* limpa EN */
  delay_us(1200);                              /* aguarda 1200µs */

} /* end send nibble */

/* --- Final do Programa --- */
