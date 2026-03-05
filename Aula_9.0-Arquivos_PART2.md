# Arquivos Binários em C
## Módulo 9 — Aula 1
Curso: Linguagem C – O Curso Definitivo WR Kits  
Autor: Dr. Eng. Wagner Rambo  

---

# 1. O que são Arquivos Binários

Arquivos binários são utilizados para armazenar dados exatamente como eles estão na memória do computador.

Eles podem guardar:

- valores de variáveis
- medições de sensores
- dados de programas
- estruturas
- firmware
- imagens
- logs de sistemas embarcados

Diferente dos **arquivos de texto**, os arquivos binários armazenam **bytes puros**, não caracteres legíveis.

---

# Comparação: Arquivo Texto vs Binário

## Arquivo de texto

Se salvar o número:

100

O arquivo guarda os caracteres:

'1' '0' '0'

Ou seja:

0x31 0x30 0x30

Cada caractere ocupa **1 byte**.

---

## Arquivo binário

Se salvar o número **100 como inteiro (int)**:

100

O arquivo pode guardar:

0x64 0x00 0x00 0x00

Ou seja:

4 bytes diretamente da memória.

---

# Vantagens de Arquivos Binários

- Mais rápidos
- Mais compactos
- Permitem acesso direto a posições
- Muito utilizados em **sistemas embarcados**

Exemplos de uso:

- EEPROM
- EPROM
- Data loggers
- armazenamento de sensores

---

# 2. Função fwrite()

A função `fwrite()` permite **escrever blocos de dados em um arquivo binário**.

## Protótipo

int fwrite(const void *ptr, int size, int n, FILE *arq);

### Parâmetros

ptr → ponteiro para os dados que serão gravados  
size → tamanho em bytes de cada elemento  
n → número de elementos a gravar  
arq → ponteiro do arquivo  

---

# Exemplo: Gravando 10 bytes em um arquivo

```
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq;
    char vec[10] = {8,4,3,1,2,0,3,4,9,4};

    arq = fopen("info.dat","wb");

    if(arq == NULL)
    {
        printf("ERRO\n");
        exit(1);
    }

    fwrite(vec, sizeof(char), 10, arq);

    fclose(arq);
}
```

O vetor possui:

[8][4][3][1][2][0][3][4][9][4]

Cada elemento ocupa:

1 byte

Logo o arquivo terá:

10 bytes.

---

# Alterando o tipo de dado

Se o vetor for:

int vec[10];

Cada valor ocupa:

4 bytes

Então o arquivo terá:

10 × 4 = 40 bytes.

---

# 3. Função fread()

A função `fread()` serve para **ler dados de um arquivo binário para a memória**.

## Protótipo

int fread(const void *ptr, int size, int n, FILE *arq);

Os parâmetros são os mesmos usados em `fwrite()`.

---

# Exemplo de leitura

```
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq;
    register int i;
    char vec[10];

    arq = fopen("info.dat","rb");

    if(arq == NULL)
    {
        printf("ERRO\n");
        exit(1);
    }

    fread(vec, sizeof(char), 10, arq);

    for(i = 0; i < 10; i++)
        printf("%d ", vec[i]);

    fclose(arq);
}
```

Após a leitura:

vec[0] = 8  
vec[1] = 4  
vec[2] = 3  
...  
vec[9] = 4  

---

# 4. Final de Arquivo em Binário

Em arquivos de texto usamos:

EOF

Mas em arquivos binários **não é seguro**, pois esse valor pode aparecer como dado real.

Por isso usamos:

feof()

Ela indica quando o ponteiro chegou ao final do arquivo.

---

# 5. Copiando Arquivos Binários

Programa que copia:

info.dat → arch.bin

```
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq_dat, *arq_bin;
    int ch;

    arq_dat = fopen("info.dat","rb");

    if(arq_dat == NULL)
    {
        printf("ERRO\n");
        exit(1);
    }

    arq_bin = fopen("arch.bin","wb");

    if(arq_bin == NULL)
    {
        printf("ERRO\n");
        exit(2);
    }

    while(!feof(arq_dat))
    {
        ch = fgetc(arq_dat);

        if(!feof(arq_dat))
            fputc(ch, arq_bin);
    }

    fclose(arq_dat);
    fclose(arq_bin);

    printf("Arquivo copiado com sucesso\n");
}
```

Funções usadas:

fgetc() → lê um byte  
fputc() → grava um byte  

---

# 6. Função ftell()

A função `ftell()` retorna **a posição atual do ponteiro no arquivo**.

## Exemplo

```
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq_bin;

    arq_bin = fopen("arch2.bin","wb");

    if(arq_bin == NULL)
    {
        printf("ERRO\n");
        exit(2);
    }

    fputc(0xAA, arq_bin);
    fputc(0xAB, arq_bin);
    fputc(0xAC, arq_bin);
    fputc(0xAD, arq_bin);

    printf("End.Atual: %ld\n", ftell(arq_bin));
}
```

Resultado:

End.Atual: 4

Porque já foram gravados **4 bytes**.

---

# 7. Função rewind()

A função `rewind()` retorna o ponteiro **para o início do arquivo**.

Exemplo:

```
rewind(arq_bin);

printf("End.Atual: %ld\n", ftell(arq_bin));
```

Agora o resultado será:

End.Atual: 0

---

# 8. Função fseek()

A função `fseek()` permite **mover o ponteiro para qualquer posição do arquivo**.

## Protótipo

int fseek(FILE *arq, long offset, int org);

### Parâmetros

arq → arquivo  
offset → número de bytes a mover  
org → origem do movimento  

---

# Tipos de origem

SEEK_SET → início do arquivo  
SEEK_CUR → posição atual  
SEEK_END → final do arquivo  

---

# Exemplo: Descobrindo o tamanho do arquivo

```
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq_bin;

    arq_bin = fopen("arch.bin","rb");

    if(arq_bin == NULL)
    {
        printf("ERRO\n");
        exit(2);
    }

    fseek(arq_bin, 0, SEEK_END);

    printf("%ld bytes\n", ftell(arq_bin));

    fclose(arq_bin);
}
```

Aqui fazemos:

1) ir até o final do arquivo  
2) verificar a posição  

Essa posição corresponde ao **tamanho do arquivo em bytes**.

---

# 9. Criando Partições em Arquivo Binário

Podemos pular posições dentro do arquivo.

Exemplo:

```
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq_bin;

    arq_bin = fopen("arch3.bin","wb");

    if(arq_bin == NULL)
    {
        printf("ERRO\n");
        exit(2);
    }

    fputc(0xBC, arq_bin);
    fputc(0x3C, arq_bin);

    fseek(arq_bin, 0x0B, SEEK_SET);

    fputc(0xA1, arq_bin);
    fputc(0x73, arq_bin);

    fclose(arq_bin);
}
```

Isso grava:

Endereço 00h → BC  
Endereço 01h → 3C  

Depois pula para:

Endereço 0Bh

E grava:

A1  
73

Esse tipo de técnica é comum em:

- firmware
- memória EEPROM
- mapas de memória

---

# 10. Exercício Proposto

Uma aplicação comum de arquivos em sistemas embarcados é o **datalogger**.

Um datalogger registra dados de sensores ao longo do tempo.

Exemplo:

sensor de temperatura.

---

# Exercício

Desenvolver um programa em C que:

1) Leia o arquivo **celsius.dat**
2) Mostre **10 temperaturas na tela**
3) Peça ao usuário **10 novos valores**
4) Atualize o arquivo com os novos dados
5) Se o arquivo não existir, ele deve ser **criado automaticamente**

---

# Bibliografia

DAMAS, Luís  
Linguagem C – Décima edição  

SCHILDT, Herbert  
C Completo e Total – Terceira edição
