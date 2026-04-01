# 📚 Linguagem C -- Aula 8.1

## Ponteiros e Vetores

**📅 Data de estudo:** 16/09/2025\
**📚 Tema:** Relação entre ponteiros, vetores e strings

------------------------------------------------------------------------

### 🎯 Objetivo da Aula

- Entender como **vetores** e **strings** se relacionam com ponteiros.  
- Compreender que o **nome de um vetor** pode ser usado como um **ponteiro para seu primeiro elemento**.  
- Aprender a **navegar pelos elementos** do vetor usando aritmética de ponteiros.

------------------------------------------------------------------------

### 📍 Vetores como ponteiros

Quando declaramos um vetor:

```c
int vec[10] = {5, 8, 9};
```

- O **nome do vetor (`vec`)** já é convertido para um **ponteiro constante** que aponta para o **índice zero**.  
- Por isso:

```c
printf("%p\n", vec);     // Endereço do índice 0
printf("%p\n", &vec[0]); // Mesmo endereço do índice 0
```

👉 Ambos imprimem o mesmo endereço.

⚠️ Importante:  
- `vec` **não é uma variável ponteiro comum**, é um **ponteiro constante**.  
- Você pode usar `ptr = vec;` mas **não pode fazer `vec = ptr;`**.

------------------------------------------------------------------------

### 📌 Usando ponteiros para acessar o vetor

```c
int vec[10] = {5, 8, 9};
int *ptr;

ptr = &vec[0];  // ou simplesmente:
ptr = vec;

printf("%p\n", vec);  // endereço do primeiro elemento
printf("%p\n", ptr);  // mesmo endereço
```

- Se usarmos `%d` em `*ptr`, veremos o conteúdo do índice 0 (nesse caso, **5**):

```c
printf("%d\n", *ptr);   // imprime 5
printf("%d\n", vec[0]); // também imprime 5
```

➡️ `*ptr` é equivalente a `vec[0]`.

------------------------------------------------------------------------

### ✏️ Alterando valores via ponteiro

```c
int vec[10] = {5, 8, 9};
int *ptr = vec;

*ptr = 78;  // altera o primeiro elemento (índice 0)

printf("%d\n", vec[0]); // imprime 78
```

✅ Aqui o ponteiro foi usado para **alterar o conteúdo da posição 0** do vetor.

------------------------------------------------------------------------

### 🔄 Aritmética de ponteiros

- Ponteiros permitem **navegar pelo vetor** com operações de soma/subtração.
- `ptr + 1` aponta para o próximo elemento, `ptr + 2` para o segundo, etc.

Exemplo com `float`:

```c
float valores[15];
float *ptr = valores;  // aponta para o primeiro índice

valores[0] = 15.7;
valores[1] = 64.1;
valores[7] = 111.78;

*(ptr + 7) = 644.5;    // altera o índice 7

printf("%.2f\n", valores[0]);  // 15.70
printf("%.2f\n", valores[1]);  // 64.10
printf("%.2f\n", valores[7]);  // 644.50
```

➡️ `*(ptr + i)` é equivalente a `valores[i]`.

---

#### ❓ Por que inicializar com `NULL`?

```c
float *ptr = NULL;
```

- `NULL` significa que o ponteiro **não aponta para lugar nenhum**.  
- É uma **medida de segurança**: evita que você use o ponteiro acidentalmente para acessar lixo de memória.

------------------------------------------------------------------------

### 📝 Ponteiros e Strings (vetores de `char`)

Strings em C são vetores de `char` terminados com **caractere nulo `'\0'`**.

```c
char str[31] = "linguagem c";
printf("%s\n", str);  // imprime "linguagem c"
```

- O compilador automaticamente coloca o `'\0'` no final da string.  
- Esse `'\0'` é essencial para o `printf("%s")` saber **onde a string termina**.

---

#### ❓ Exemplo que você escreveu:

```c
char str[31] = "linguagem c";
char *ptr;

ptr = str;  // ptr aponta para o primeiro caractere

printf("%c\n", *ptr);  // imprime 'l' (primeiro caractere)
```

⚠️ Observação: você havia escrito `ptr = *str;`, mas isso está **errado**.  
- `*str` acessa o **conteúdo do índice 0** (ou seja, o caractere `'l'`).  
- O correto é **`ptr = str;`**, assim o ponteiro aponta para o início da string.  

------------------------------------------------------------------------

### 📊 Resumo

- `vec` é convertido automaticamente para **ponteiro do primeiro elemento** (`&vec[0]`).  
- `*ptr` acessa o **conteúdo** do endereço.  
- `*(ptr + i)` é equivalente a `vec[i]`.  
- Strings são vetores de `char` terminados com `'\0'`.  
- Sempre inicialize ponteiros (ex.: `ptr = NULL;`) para evitar erros.

------------------------------------------------------------------------

### 📌 Conclusão

- Ponteiros e vetores estão intimamente ligados em C.  
- O nome do vetor funciona como ponteiro para o índice zero.  
- É possível **ler, alterar e percorrer** os elementos tanto com `[]` quanto com `*`.  
- Em strings, o `'\0'` garante que funções como `printf("%s")` saibam onde parar.  

------------------------------------------------------------------------
