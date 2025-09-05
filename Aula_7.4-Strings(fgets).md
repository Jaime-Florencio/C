# 📚 Linguagem C -- Aula 7.4

## Leitura de Strings com `fgets()`

**📅 Data de estudo:** 06/08/2025\
**📚 Tema:** Entrada de Strings no Teclado

------------------------------------------------------------------------

### 🎯 Objetivo da Aula

Aprender como **ler uma string (texto) do teclado em linguagem C**,
incluindo espaços, de forma **segura**.

------------------------------------------------------------------------

### ⚠️ Problemas com métodos antigos

#### 1. Usando `scanf("%s", nome);`

-   Lê apenas até o **primeiro espaço em branco**.\
-   Exemplo: se digitar `Jaime Florencio`, ele só guarda `"Jaime"`.

#### 2. Usando `gets()`

-   Lê tudo até o ENTER, incluindo espaços.\
-   ❌ Mas é **perigosa**: não limita quantos caracteres vão ser lidos.\
-   Pode ultrapassar o tamanho do vetor → causa erros graves.\
-   Foi **removida dos padrões modernos de C**.

------------------------------------------------------------------------

### ✅ A solução correta: `fgets()`

É a forma **segura** de ler textos do teclado, com limite de caracteres.

**Sintaxe:**

``` c
fgets(variavel, tamanho, stdin);
```

**Significado de cada parte:** - `variavel` → onde será guardado o texto
digitado.\
- `tamanho` → limite máximo de caracteres (conta também o `\0`).\
- `stdin` → entrada padrão, ou seja, o **teclado**.

------------------------------------------------------------------------

### 🧩 Exemplo prático

``` c
#include <stdio.h>

int main() {
    char nome[32];

    printf("Digite seu nome: ");
    fgets(nome, 32, stdin);

    // Remove o ENTER (\n) da string
    for (int i = 0; nome[i] != '\0'; i++) {
        if (nome[i] == '\n') {
            nome[i] = '\0';
            break;
        }
    }

    printf("Ola, %s!\n", nome);
    return 0;
}
```

------------------------------------------------------------------------

### 🧠 Como funciona na memória

-   Quando você declara `char nome[32];`, o compilador reserva **32
    caixinhas de 1 byte** na memória.\

-   Se digitar `Jaime Florencio`, o teclado envia os caracteres:

        J  a  i  m  e     F  l  o  r  e  n  c  i  o  \n  \0

-   O `\n` vem do ENTER.\

-   O `\0` é colocado automaticamente pelo `fgets()` no final, para
    marcar onde a string termina.\

-   O laço `for` substitui o `\n` por `\0`, deixando a string pronta
    para uso.

------------------------------------------------------------------------

### 📊 Resumo comparativo

  Função          Lê espaços?   Limita tamanho?   Segura?
  --------------- ------------- ----------------- ------------
  `scanf("%s")`   ❌ Não        ✅ Sim            ⚠️ Parcial
  `gets()`        ✅ Sim        ❌ Não            ❌ Não
  `fgets()`       ✅ Sim        ✅ Sim            ✅ Sim

------------------------------------------------------------------------

### 📌 Conclusão

Sempre prefira **`fgets()`** para ler textos com espaço de forma
segura.\
Ele protege a memória e é a forma moderna e correta de capturar strings
do teclado.

------------------------------------------------------------------------
