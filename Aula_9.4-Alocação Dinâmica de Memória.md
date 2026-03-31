# 🧠 Alocação Dinâmica de Memória em C (Guia Prático para Embarcados)

> Sem enrolação. Só o que você precisa usar de verdade.

---

# 📌 1. Problema que isso resolve

❌ Errado:

```c
char buffer[1000];
```

👉 Você reserva memória fixa mesmo sem usar tudo.

👉 Em microcontrolador isso é crítico.

✔️ Solução:
👉 Alocar memória só quando precisar

---

# ⚙️ 2. malloc (o mais importante)

```c
void *malloc(size_t size);
```

👉 Retorna ponteiro para memória
👉 Retorna `NULL` se falhar 

---

## ✅ Uso correto

```c
char *ptr;

ptr = (char *) malloc(10);

if (ptr == NULL) {
    // erro
}
```

---

# 🚨 3. REGRA DE OURO

Sempre faça isso:

```c
if (ptr == NULL)
```

👉 Se não fizer → crash, bug ou comportamento aleatório

---

# 🧪 4. Exemplo real (string)

```c
char s[100];
char *copy;

gets(s);

copy = (char *) malloc(strlen(s) + 1);

if (!copy) {
    // erro
}

strcpy(copy, s);

free(copy);
```

👉 Aloca exatamente o necessário 

---

# 🔥 5. free (OBRIGATÓRIO)

```c
free(ptr);
```

👉 Libera memória

---

## ❌ Se não usar:

* Memory leak
* Travamento
* Sistema instável

---

# ⚠️ 6. Regra crítica

Nunca faça:

```c
free(ptr);
free(ptr); // ERRO GRAVE
```

---

# 📦 7. calloc (malloc melhorado)

```c
void *calloc(size_t num, size_t size);
```

👉 Aloca e já inicializa com zero 

---

## ✅ Uso

```c
int *v;

v = (int *) calloc(10, sizeof(int));
```

👉 Cria vetor de 10 ints zerados

---

# 🔄 8. realloc (redimensionar)

```c
void *realloc(void *ptr, size_t size);
```

👉 Aumenta ou reduz memória 

---

## ✅ Uso

```c
ptr = realloc(ptr, novo_tamanho);
```

---

## ⚠️ Cuidado REAL

```c
char *temp = realloc(ptr, novo_tamanho);

if (temp != NULL) {
    ptr = temp;
}
```

👉 Se realloc falhar, você não perde o ponteiro original

---

# 🧠 9. Exemplo real (crescendo buffer)

```c
char *buffer;
buffer = malloc(10);

buffer = realloc(buffer, 20);
```

---

# 📁 10. Caso real (ler arquivo)

```c
FILE *f;
char *data;
int size = 0;
int c;

f = fopen("file.txt", "r");

while ((c = fgetc(f)) != EOF)
    size++;

rewind(f);

data = malloc(size);

for (int i = 0; i < size; i++)
    data[i] = fgetc(f);

free(data);
```

👉 Aloca exatamente o tamanho do arquivo 

---

# 🧠 11. Quando usar isso?

✔️ Use quando:

* Tamanho desconhecido
* Dados dinâmicos
* Leitura de arquivo
* Protocolos
* Buffers variáveis

---

# ❌ Quando NÃO usar (muito importante)

❌ Em microcontrolador pequeno (AVR, etc):

* Fragmenta memória
* Pode quebrar o sistema

👉 Prefira:

* buffers fixos
* pools de memória

---

# 🔥 12. Mentalidade de firmware

malloc NÃO é padrão em embarcados críticos.

Você precisa saber:

* quando usar
* quando evitar

---

# 🚀 13. Versão profissional (safe malloc)

```c
void *safe_malloc(size_t size) {
    void *ptr = malloc(size);

    if (!ptr) {
        // tratamento real
        while(1); // trava sistema
    }

    return ptr;
}
```

---

# 📌 14. Resumo rápido

| Função  | Uso           |
| ------- | ------------- |
| malloc  | aloca memória |
| calloc  | aloca e zera  |
| realloc | redimensiona  |
| free    | libera        |

---

# 🧠 15. Erros clássicos

❌ esquecer free
❌ usar ponteiro NULL
❌ double free
❌ usar após free
❌ realloc errado

---

# 🔧 16. Boas práticas

✔️ Sempre verificar NULL
✔️ Sempre liberar memória
✔️ Usar sizeof
✔️ Evitar em sistemas críticos

---

# 💣 17. Verdade que poucos falam

Em embarcados:

👉 malloc pode ser perigoso
👉 Fragmenta heap
👉 Pode falhar em tempo real

---

# 🧠 Dica final

Se você domina isso, você consegue:

* trabalhar com buffers dinâmicos
* manipular dados complexos
* escrever firmware mais flexível

Mas…

👉 Saber QUANDO NÃO usar é o que diferencia um engenheiro bom de um excelente

---

# ✍️ Autor

Jaime Florencio
Engenharia Elétrica — Sistemas Embarcados

---
