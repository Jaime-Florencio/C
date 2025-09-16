# 📚 Linguagem C -- Aula 8.2

## Aritmética de Ponteiros

**📅 Data de estudo:** 16/09/2025\
**📚 Tema:** Operações de incremento, decremento, comparação e diferença entre ponteiros

------------------------------------------------------------------------

### 🎯 Objetivo da Aula

- Compreender o que significa **aritmética de ponteiros**.  
- Aprender que ponteiros não somam ou subtraem **bytes diretamente**, mas sim em múltiplos do tamanho do tipo que eles apontam.  
- Entender como aplicar incremento (`ptr++`), decremento (`ptr--`), comparação e diferença entre ponteiros.

------------------------------------------------------------------------

### 🧠 Conceito fundamental

Um ponteiro armazena **endereços de memória**.  
Quando fazemos operações como `ptr++`, o valor armazenado no ponteiro é incrementado em **`sizeof(tipo)`**, e não em 1 byte.

Exemplos:

- `char *` → avança de **1 em 1 byte** (pois `sizeof(char) = 1`).  
- `short *` → avança de **2 em 2 bytes** (em arquiteturas comuns, `sizeof(short) = 2`).  
- `int *` → geralmente **4 bytes** (dependendo do compilador/sistema).  
- `double *` → **8 bytes** (em arquiteturas modernas).

👉 Ou seja:  
`ptr++` é equivalente a `ptr = ptr + 1`, mas o quanto ele “anda” depende do tipo de dado.

------------------------------------------------------------------------

### 📍 Exemplo com `short`

```c
#include <stdio.h>

int main() {
    short var = 10;
    short *ptr;

    ptr = &var; // ponteiro aponta para var

    printf("Endereco de var: %p\n", (void*)&var);
    printf("Endereco em ptr: %p\n", (void*)ptr);

    ptr++; // avança sizeof(short) = 2 bytes
    printf("Depois de ptr++: %p\n", (void*)ptr);

    ptr--; // volta 2 bytes
    printf("Depois de ptr--: %p\n", (void*)ptr);

    return 0;
}
```

Saída típica (os valores exatos mudam em cada execução):

```
Endereco de var: 0x7ffdeac2a56c
Endereco em ptr: 0x7ffdeac2a56c
Depois de ptr++: 0x7ffdeac2a56e
Depois de ptr--: 0x7ffdeac2a56c
```

➡️ Note que o endereço variou **2 bytes**, porque `ptr` é um ponteiro para `short`.

------------------------------------------------------------------------

### 🔍 Comparação e diferença entre ponteiros

- É possível **comparar ponteiros** (ex.: `if (ptr1 > ptr2)`).
- É possível **subtrair ponteiros** (`ptr1 - ptr2`) → o resultado é a diferença em **número de elementos**, não em bytes.

Exemplo:

```c
int vec[5] = {10, 20, 30, 40, 50};
int *p1 = &vec[0];
int *p2 = &vec[3];

printf("%ld\n", p2 - p1); // saída: 3 (distância em elementos)
```

------------------------------------------------------------------------

### ⚠️ Observações importantes

- Sempre inicialize ponteiros (ex.: `int *p = NULL;`) para evitar lixo de memória.  
- `ptr++` é idêntico a `ptr = ptr + 1`.  
- O tipo do ponteiro **define o tamanho do salto** ao fazer aritmética.  
- Para imprimir corretamente valores:
  - `short` → `%hd`
  - `int` → `%d`
  - `long` → `%ld`
  - `long long` → `%lld`

------------------------------------------------------------------------

### 📚 Aplicação prática: Pilha de memória (Stack)

Uma **pilha de memória** pode ser implementada com **vetores + ponteiros**.  
A lógica é **LIFO (Last In, First Out)**: o último elemento inserido é o primeiro a sair.

Exemplo simples:

```c
#include <stdio.h>

#define TAM 5

int main() {
    int stack[TAM];
    int *top = stack; // ponteiro para o topo (início da pilha)

    // Inserindo elementos
    *top = 10; top++;
    *top = 20; top++;
    *top = 30; top++;

    // Removendo elementos (LIFO)
    top--;
    printf("Saiu: %d\n", *top); // 30

    top--;
    printf("Saiu: %d\n", *top); // 20

    return 0;
}
```

➡️ Aqui, `top` funciona como um ponteiro que cresce/diminui simulando a pilha.

------------------------------------------------------------------------

### 📊 Resumo

- `ptr++` ou `ptr--` deslocam o ponteiro de acordo com o tamanho do tipo (`sizeof(tipo)`).  
- Aritmética de ponteiros permite percorrer vetores sem usar índices.  
- Impressão correta depende do tipo (`%hd`, `%ld`, etc.).  
- Conceito útil para **pilhas, filas, listas encadeadas e alocação dinâmica**.

------------------------------------------------------------------------

### 📌 Conclusão

- Aritmética de ponteiros é essencial para trabalhar com **estruturas de dados** em C.  
- É necessário entender o impacto de `sizeof(tipo)` para não cometer erros.  
- Saber manipular ponteiros abre caminho para **vetores dinâmicos, estruturas e funções mais avançadas**.

------------------------------------------------------------------------

**Nome sugerido do arquivo:** `Aula_8.2-AritmeticaPonteiros.md`\
**Como linkar no README:**
```
- [Aula 8.2 — Aritmética de Ponteiros](Aula_8.2-AritmeticaPonteiros.md)
```
