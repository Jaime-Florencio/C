# Módulo 9 — Arquivos em C (Estudo Guiado)

Este material organiza e explica de forma mais didática o conteúdo da aula sobre **manipulação de arquivos em C**.

A linguagem C possui funções poderosas para manipular arquivos, permitindo que os dados de um programa sejam **armazenados permanentemente**, ao invés de desaparecerem quando o programa termina.

Do ponto de vista da linguagem C:

> Um arquivo é uma sequência de bytes armazenados em memória secundária (disco).

Cada byte pode representar:

- caracteres
- números
- dados binários
- qualquer informação.

---

# 1. Conceito de Arquivo em C

Para a linguagem C, um arquivo é tratado como um **fluxo de dados (stream)**.

Imagine um arquivo assim:

```
Curso de C
```

O programa **não lê tudo de uma vez**.

Ele lê **byte por byte**, movendo um **cursor interno**.

Exemplo conceitual:

```
C u r s o   d e   C
^
cursor de leitura
```

Cada leitura move o cursor para frente.

---

# 2. Estrutura básica para trabalhar com arquivos

Todo programa em C que trabalha com arquivos segue esta sequência:

```
1) declarar ponteiro FILE
2) abrir arquivo
3) verificar erro
4) ler ou escrever dados
5) fechar arquivo
```

---

# 3. Tipo FILE

Para manipular arquivos, utilizamos o tipo especial:

```c
FILE
```

Ele é definido na biblioteca:

```c
stdio.h
```

Declaração de ponteiro para arquivo:

```c
FILE *arq;
```

Esse ponteiro irá **apontar para o arquivo aberto**.

---

# 4. Abrindo arquivos

Para abrir um arquivo utilizamos:

```c
fopen()
```

Sintaxe:

```c
FILE *fopen(const char *filename, const char *mode);
```

Exemplo:

```c
FILE *arq;

arq = fopen("dados.txt","r");
```

---

# 5. Modos de abertura de arquivos

| Modo | Significado |
|-----|-----|
| r | abrir para leitura |
| w | criar arquivo para escrita |
| a | acrescentar dados |
| rb | leitura binária |
| wb | escrita binária |
| r+ | leitura e escrita |

Exemplo:

```c
fopen("teste.txt","w");
```

Se o arquivo **não existir**, ele será criado.

---

# 6. Verificação de erro ao abrir arquivo

Sempre devemos verificar se o arquivo foi aberto corretamente.

Exemplo:

```c
FILE *arq;

arq = fopen("teste.txt","r");

if(arq == NULL)
{
    printf("Erro ao abrir arquivo\n");
    exit(1);
}
```

Se `fopen` falhar, ele retorna:

```
NULL
```

---

# 7. Fechando arquivos

Depois de utilizar o arquivo, devemos fechá-lo:

```c
fclose(arq);
```

Isso:

- libera memória
- garante que todos os dados sejam gravados no disco.

---

# 8. Escrevendo em arquivos

Existem várias funções.

## fputc()

Escreve **um caractere**.

```c
fputc('A', arq);
```

Exemplo:

```c
fputc('H',arq);
fputc('e',arq);
fputc('l',arq);
fputc('l',arq);
fputc('o',arq);
```

Isso escreve:

```
Hello
```

no arquivo.

---

## fputs()

Escreve **uma string inteira**.

```c
fputs("Hello world", arq);
```

---

# 9. Lendo arquivos

Para ler um arquivo podemos usar:

## fgetc()

Lê **um caractere**.

```c
char c = fgetc(arq);
```

---

# 10. Leitura até o final do arquivo

Quando o arquivo termina, a função retorna:

```
EOF
```

Significa:

```
End Of File
```

Estrutura clássica de leitura:

```c
int ch;

while((ch = fgetc(arq)) != EOF)
{
    printf("%c", ch);
}
```

Explicação:

1. lê um caractere
2. verifica se chegou ao final
3. imprime
4. continua até acabar o arquivo

---

# 11. Exemplo completo de leitura

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arq;
    int ch;

    arq = fopen("readme.txt","r");

    if(arq == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    while((ch = fgetc(arq)) != EOF)
    {
        printf("%c", ch);
    }

    fclose(arq);

    return 0;
}
```

---

# 12. Copiando arquivos

Podemos copiar um arquivo lendo e escrevendo ao mesmo tempo.

```c
while((ch = fgetc(fr)) != EOF)
{
    fputc(ch, fw);
}
```

Onde:

- `fr` → arquivo de leitura
- `fw` → arquivo de escrita

---

# 13. Exercício proposto

Desenvolver um programa que **criptografe arquivos de texto**.

Regra da criptografia:

```
Deslocar cada caractere 3 posições na tabela ASCII
```

Exemplo:

Mensagem original:

```
Curso de C
```

Mensagem criptografada:

```
Fxuvr#gh#F
```

---

# 14. Entendendo a criptografia

Cada caractere possui um valor ASCII.

Exemplo:

| caractere | ASCII |
|----------|------|
| C | 67 |
| F | 70 |

A criptografia faz:

```
novo = original + 3
```

Exemplo:

```
C -> F
u -> x
r -> u
s -> v
o -> r
```

---

# 15. Estratégia do programa

O programa deve:

1. abrir arquivo original
2. criar arquivo criptografado
3. ler caractere por caractere
4. somar 3 ao valor ASCII
5. gravar no novo arquivo
6. fechar arquivos

---

# 16. Algoritmo (pseudo-código)

```
abrir arquivo original

abrir arquivo criptografado

enquanto não chegar ao EOF
    ler caractere
    criptografar (somar 3)
    escrever no novo arquivo

fechar arquivos
```

---

# 17. Estrutura base do programa

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *entrada;
    FILE *saida;
    int ch;

    entrada = fopen("entrada.txt","r");

    if(entrada == NULL)
    {
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }

    saida = fopen("cripto.txt","w");

    if(saida == NULL)
    {
        printf("Erro ao criar arquivo\n");
        exit(2);
    }

    while((ch = fgetc(entrada)) != EOF)
    {
        ch = ch + 3;

        fputc(ch, saida);
    }

    fclose(entrada);
    fclose(saida);

    printf("Arquivo criptografado criado!\n");

}
```

---

# 18. Exercício complementar

Criar um segundo programa que **descriptografe** o arquivo.

Regra:

```
original = criptografado - 3
```

Fluxo:

```
ler arquivo criptografado
subtrair 3
gerar novo arquivo com texto original
```

---

# 19. Possíveis melhorias

Versões mais avançadas do programa podem:

- pedir nome do arquivo ao usuário
- usar argumentos de linha de comando
- suportar arquivos binários
- usar buffers para maior performance

Exemplo:

```
./cripto entrada.txt saida.txt
```

---

# Conclusão

Manipulação de arquivos é um recurso essencial da linguagem C.

Com ela é possível:

- salvar dados permanentemente
- processar grandes volumes de informação
- criar utilitários de sistema
- desenvolver ferramentas semelhantes às usadas em sistemas Unix/Linux.
