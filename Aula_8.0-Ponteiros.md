# 📚 Linguagem C -- Aula 8.0

## Ponteiros

**📅 Data de estudo:** 05/09/2025\
**📚 Tema:** Introdução a ponteiros e manipulação de memória

------------------------------------------------------------------------

### 🎯 Objetivo da Aula

Compreender o conceito de **ponteiros**, aprender como funcionam e como
são usados para acessar e manipular **endereços de memória** em C.

------------------------------------------------------------------------

### 🧠 O que são ponteiros?

- São **variáveis especiais que armazenam endereços de memória**.
- Permitem acessar diretamente onde os dados estão guardados.
- Usados para:
  - **alocação dinâmica de memória**,
  - **passagem eficiente de parâmetros**,
  - **manipulação de vetores e strings**,
  - acesso direto ao **hardware**.

------------------------------------------------------------------------

### 🧩 Declaração de ponteiros

A sintaxe básica é:

```c
tipo *nome_do_ponteiro;
```

- `*` → operador de indireção (diz que a variável é ponteiro).
- Exemplo:

```c
int *ptr;   // ponteiro para inteiro
float *pf;  // ponteiro para float
char *pc;   // ponteiro para char
```

------------------------------------------------------------------------

### 📍 Operador de endereço `&`

- O operador **`&`** retorna o **endereço de memória** de uma variável.

```c
int var = 15;
printf("%p\n", &var);  // mostra o endereço de var
```

- `%p` → formata o endereço de acordo com a arquitetura da máquina.
- `%x` ou `%X` → mostra o endereço em hexadecimal (não é o mais recomendado, mas funciona).

------------------------------------------------------------------------

### 🔄 Ponteiro apontando para uma variável

```c
int var = 15;
int *ptr;

ptr = &var;   // ponteiro recebe o endereço de var

printf("%p\n", &var);  // endereço de var
printf("%p\n", ptr);   // endereço de var (mesmo resultado)
```

⚡ Ambos mostram o mesmo número porque `ptr` aponta para `var`.

------------------------------------------------------------------------

### 🔍 Diferença entre endereço do ponteiro e endereço da variável

```c
int var = 15;
int *ptr = &var;

printf("%p\n", &var);  // endereço de var
printf("%p\n", &ptr);  // endereço do ponteiro (diferente!)
```

👉 O ponteiro também ocupa um espaço na memória, por isso `&ptr` é diferente de `&var`.

------------------------------------------------------------------------

### 📖 Operador de indireção `*`

- O operador `*` acessa o **conteúdo da memória** apontada pelo ponteiro.

```c
int var = 15;
int *ptr = &var;

printf("%d\n", var);   // imprime 15
printf("%d\n", *ptr);  // também imprime 15
```

👉 `*ptr` acessa o valor que está em `var`.

------------------------------------------------------------------------

### ✏️ Alterando valores através de ponteiros

```c
int var = 15;
int *ptr = &var;

printf("%d\n", var);   // 15
*ptr = 8;              // altera o valor de var através do ponteiro
printf("%d\n", var);   // 8
```

📌 Isso prova que ponteiros permitem manipular a memória diretamente.

------------------------------------------------------------------------

### ⚠️ Boas práticas

- Sempre **inicialize ponteiros**.
- Se não souber para onde apontar, use:

```c
int *ptr = NULL;
```

👉 `NULL` significa que o ponteiro **não aponta para lugar nenhum**.  
Isso evita **comportamento indefinido** (acessar lixo de memória).

------------------------------------------------------------------------

### 📊 Resumo

- Ponteiros armazenam **endereços de memória**.
- `&` → pega o endereço.  
- `*` → acessa o valor armazenado nesse endereço.  
- Ponteiros permitem alterar variáveis indiretamente.  
- Usados para **eficiência, flexibilidade e acesso direto à memória**.  
- Devem ser sempre **inicializados** (de preferência com `NULL`).

------------------------------------------------------------------------

### 📌 Conclusão

- Ponteiros são um dos recursos mais poderosos da linguagem C.  
- São a razão de C ser chamada de **linguagem de médio nível**:  
  conseguem manipular tanto estruturas de alto nível quanto a memória bruta.  
- Dominar ponteiros é essencial para avançar em **alocação dinâmica, vetores, strings, structs e funções**.

------------------------------------------------------------------------

**Nome sugerido do arquivo:** `Aula_8.0-Ponteiros.md`\
**Como linkar no README:**
```
- [Aula 8.0 — Ponteiros](Aula_8.0-Ponteiros.md)
```
