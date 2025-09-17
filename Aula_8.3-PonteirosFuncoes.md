# 📚 Linguagem C -- Aula 8.3

## Ponteiros para Funções

**📅 Data de estudo:** 08/09/2025\
**📚 Tema:** Passagem de vetores para funções e ponteiros para funções

------------------------------------------------------------------------

### 🎯 Objetivo da Aula

- Aprender a passar **vetores como parâmetros** para funções.  
- Entender a diferença entre usar `v[]` e `*v` como parâmetro.  
- Explorar funções que manipulam strings (`strsize` e `letter`).  
- Compreender o uso de **ponteiros para funções** — como passar uma função como argumento para outra.  

------------------------------------------------------------------------

### 📍 Passando vetores para funções

Um vetor pode ser passado para uma função de duas formas equivalentes:

```c
void func(int v[], int n);
void func(int *v, int n);
```

➡️ Ambos significam: “a função `func` recebe o **endereço do primeiro elemento do vetor**”.

---

#### Exemplo

```c
#include <stdio.h>
#include <stdlib.h>

void func(int v[], int n);

int main() {
    int vec[10] = {45, 98, 32, 85, 12};
    func(vec, 10);  // ou func(&vec[0], 10);
    return 0;
}

void func(int v[], int n) {
    register int i;
    for (i = 0; i < n; i++)
        printf("v[%d] = %d\n", i, v[i]);
}
```

📌 `vec` e `&vec[0]` são equivalentes nesse contexto.

------------------------------------------------------------------------

### 🧠 `strsize` — tamanho de uma string

```c
int strsize(char *str) {
    register int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}
```

- Conta quantos caracteres existem até o `'\0'`.  
- É como uma versão simples do `strlen()` da `<string.h>`.  
- Exemplo:

```c
char s1[41] = "wr kits";
printf("%d\n", strsize(s1));  // Saída: 7
```

------------------------------------------------------------------------

### 🧠 `letter` — quantidade de letras na string

```c
#include <ctype.h>  // para isalpha()

int letter(const char *str) {
    register int i = 0, letters = 0;

    while (str[i] != '\0') {
        if (isalpha(str[i])) letters++;
        i++;
    }
    return letters;
}
```

- Conta **apenas letras do alfabeto** (ignora espaços, números e símbolos).  
- `isalpha()` é função da `<ctype.h>` que retorna **true se o caractere é uma letra (A–Z ou a–z)**.  

📌 Diferença:
- `strsize("wr kits")` → 7 (todos os caracteres, incluindo espaço).  
- `letter("wr kits")` → 6 (conta apenas `w r k i t s`).

------------------------------------------------------------------------

### ⚡ Variáveis locais, `register` e `static`

- **Variável local normal:** criada quando a função começa, destruída ao sair da função.  
- **`register`:** dica ao compilador para guardar a variável em **registradores da CPU** (mais rápido que memória RAM).  
- **`static`:**
  - Faz a variável **manter seu valor entre chamadas da função**.
  - Continua existindo após a função terminar, mas só é visível dentro dela.

Exemplo:

```c
void exemplo() {
    static int x = 0; // preserva valor
    x++;
    printf("%d\n", x);
}

int main() {
    exemplo(); // 1
    exemplo(); // 2
    exemplo(); // 3
}
```

------------------------------------------------------------------------

### 📌 Ponteiros para funções

Uma função também tem um **endereço na memória**.  
Podemos criar um ponteiro que armazene esse endereço e chamá-la indiretamente.

#### Exemplo 1 — função simples

```c
#include <stdio.h>

int strsize(char *str);

void trata_str(char *s, int (*func)(char *)) {
    printf("Resultado: %d\n", func(s));
}

int main() {
    char s1[41] = "wr kits";
    trata_str(s1, strsize);  // passa a função como parâmetro
    return 0;
}
```

- O parâmetro `int (*func)(char *)` significa:  
  “um ponteiro para uma função que recebe `char*` e retorna `int`”.  
- Dentro de `trata_str`, chamamos `func(s)` → isso executa a função recebida.

---

#### Exemplo 2 — usando `letter`

```c
#include <stdio.h>
#include <ctype.h>

int strsize(char *str) {
    int i = 0;
    while (str[i] != '\0') i++;
    return i;
}

int letter(const char *str) {
    int i = 0, letters = 0;
    while (str[i] != '\0') {
        if (isalpha(str[i])) letters++;
        i++;
    }
    return letters;
}

void trata_str(char *s, int (*func)(char *)) {
    printf("Resultado: %d\n", func(s));
}

int main() {
    char s1[41] = "wr kits";
    trata_str(s1, strsize); // conta tamanho total (7)
    trata_str(s1, letter);  // conta apenas letras (6)
    return 0;
}
```

➡️ Aqui `trata_str` pode receber diferentes funções, tornando o código mais **genérico e reutilizável**.

------------------------------------------------------------------------

### 📊 Resumo

- Vetores podem ser passados para funções como `int v[]` ou `int *v`.  
- `strsize` conta todos os caracteres até o `'\0'`.  
- `letter` conta apenas letras (usando `isalpha`).  
- Variáveis locais:
  - `register` → pode ser otimizada em registrador.  
  - `static` → mantém valor entre chamadas.  
- Ponteiros para funções permitem passar **funções como parâmetros**, aumentando a flexibilidade.  

------------------------------------------------------------------------

### 📌 Conclusão

- Vetores e strings são passados para funções **por referência** (como ponteiros).  
- Ponteiros para funções permitem construir **funções genéricas** que recebem outras funções como argumento.  
- Esse conceito é base para **callbacks, bibliotecas de ordenação (ex.: `qsort`) e APIs modernas em C**.  

------------------------------------------------------------------------
