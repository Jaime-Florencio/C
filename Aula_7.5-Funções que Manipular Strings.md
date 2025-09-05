# 📚 Linguagem C -- Aula 7.5

## Funções que Manipulam Strings

**📅 Data de estudo:** 05/09/2025\
**📚 Tema:** Implementação manual de funções para manipulação de strings

------------------------------------------------------------------------

### 🎯 Objetivo da Aula

Aprender a **implementar manualmente** funções clássicas que manipulam
strings em C, entendendo **o que fazem**, **como funcionam** e **sua sintaxe**.

> Obs.: Os nomes `strlen`, `strcpy`, `strcat` e `strcmp` existem na `<string.h>`.
> Aqui estamos estudando **versões feitas à mão** para aprender os algoritmos.

------------------------------------------------------------------------

### 🧰 Funções estudadas

#### 1. `strlen()`

- **Função:** calcula o comprimento da string (quantos caracteres até `'\0'`).
- **Como funciona:** percorre a string somando 1 a cada caractere até achar `'\0'`.
- **Sintaxe:**
```c
int strlen(char *s);
```
- **Exemplo:**
```c
char texto[] = "Linguagem C";
printf("%d\n", strlen(texto));  // Saída: 11
```

---

#### 2. `strvowel()`

- **Função:** conta quantas **vogais** (A, E, I, O, U) existem na string
  (maiúsculas e minúsculas, sem acento).
- **Como funciona:** percorre a string testando se cada caractere é uma vogal.
- **Sintaxe:**
```c
int strvowel(char *s);
```
- **Exemplo:**
```c
char texto[] = "Linguagem C 1234";
printf("%d\n", strvowel(texto));  // Saída: 4
```

---

#### 3. `strcpy()`

- **Função:** copia a string **origem** para a **destino**, incluindo o `'\0'`.
- **Como funciona:** laço copia caractere a caractere até encontrar `'\0'` em `orig`.
- **Atenção:** `dest` deve ter **tamanho suficiente** para receber `orig`.
- **Sintaxe:**
```c
char *strcpy(char *dest, char *orig);
```
- **Exemplo:**
```c
char destino[20];
strcpy(destino, "Kits");
printf("%s\n", destino);  // Saída: Kits
```

---

#### 4. `strcat()`

- **Função:** **concatena** (junta) a string **orig** ao **final** de `dest`.
- **Como funciona:** encontra o final de `dest` (onde está o `'\0'`) e passa a copiar `orig` a partir dali.
- **Atenção:** `dest` precisa ter **espaço livre** para o resultado + `'\0'`.
- **Sintaxe:**
```c
char *strcat(char *dest, char *orig);
```
- **Exemplo:**
```c
char s[50] = "Linguagem ";
strcat(s, "C");
printf("%s\n", s);  // Saída: Linguagem C
```

---

#### 5. `strrev()`

- **Função:** **inverte** a string no próprio vetor (não é padrão da `<string.h>`).
- **Como funciona:** usa dois índices (início e fim) trocando caracteres até o meio.
- **Sintaxe:**
```c
char *strrev(char *str);
```
- **Exemplo:**
```c
char s[] = "ABCD";
strrev(s);
printf("%s\n", s);  // Saída: DCBA
```

---

#### 6. `strcmp()`

- **Função:** compara duas strings **lexicograficamente** (ordem de código).
- **Como funciona:** avança enquanto os caracteres forem iguais; na primeira diferença:
  - retorna **0** se forem iguais,
  - **> 0** se `s1` > `s2`,
  - **< 0** se `s1` < `s2`.
- **Sintaxe:**
```c
int strcmp(char *s1, char *s2);
```
- **Exemplo:**
```c
printf("%d\n", strcmp("ABC","ABC")); // 0
printf("%d\n", strcmp("ABC","ABD")); // negativo
printf("%d\n", strcmp("ABD","ABC")); // positivo
```

---

#### 7. `strnumb()`

- **Função:** conta quantos **dígitos** (0–9) existem na string.
- **Como funciona:** percorre a string e soma quando o caractere for numérico.
- **Sintaxe:**
```c
int strnumb(char *s);
```
- **Exemplo:**
```c
char s[] = "C 1234";
printf("%d\n", strnumb(s));  // Saída: 4
```

> 💡 No código de referência, `strnumb` usa `isdigit`, que requer `#include <ctype.h>`.
> Também havia um detalhe: o índice era incrementado **antes** da checagem, pulando o 1º caractere.
> A lógica correta é verificar e **depois** incrementar.

------------------------------------------------------------------------

### 🧩 Exemplo prático com comandos (usando `strcmp`)

```c
// Supõe que "com" recebeu o texto do usuário (ex.: com fgets)
if (!strcmp(com, "BIP")) {
    putchar('\a');       // beep
} else if (!strcmp(com, "CLS")) {
    system("cls");       // Windows (em Linux/Mac: system("clear"))
} else if (!strcmp(com, "OUT")) {
    // sair do programa
}
```

------------------------------------------------------------------------

### 📊 Resumo das funções

Função      | O que faz                           | Retorno
------------|-------------------------------------|---------------------------
`strlen`    | Conta caracteres até `'\0'`         | Tamanho (int)
`strvowel`  | Conta vogais (A, E, I, O, U)        | Quantidade (int)
`strcpy`    | Copia origem → destino              | Ponteiro para `dest`
`strcat`    | Junta `orig` ao final de `dest`     | Ponteiro para `dest`
`strrev`    | Inverte a string (in-place)         | Ponteiro para a string
`strcmp`    | Compara duas strings                | 0, >0 ou <0
`strnumb`   | Conta dígitos na string             | Quantidade (int)

------------------------------------------------------------------------

### 📌 Conclusão

- Saber implementar essas funções ajuda a **entender o funcionamento interno** das strings em C.\
- Em projetos reais, use as versões da biblioteca padrão (`<string.h>` / `<ctype.h>`) e sempre **garanta espaço de buffer** ao copiar/concatenar.\
- Para ler entradas do usuário, **evite `gets()`** e prefira `fgets()` (como visto na Aula 7.4).

------------------------------------------------------------------------

**Nome sugerido do arquivo:** `Aula_7.5-FuncoesStrings.md`\
**Como linkar no README:**
```
- [Aula 7.4 — Leitura com `fgets`](Aula_7.4-Strings(fgets).md)
- [Aula 7.5 — Funções que Manipulam Strings](Aula_7.5-FuncoesStrings.md)
```
