# Estruturas em C — Explicação Prática (Estilo Paulo Freire)

## 1. Primeiro vamos pensar no problema

Antes de falar de código, pense comigo.

Imagine que você está criando um sistema de cadastro de clientes.

Cada cliente possui:

- nome
- endereço
- cidade
- telefone
- CEP

Agora imagine tentar guardar isso em variáveis separadas:

char nome[30];
char endereco[40];
char cidade[30];
char telefone[11];
int cep;

Funciona.

Mas agora pense:

Se você tiver 100 clientes, vai ter que criar 500 variáveis.

Isso vira um caos.

Então surge a pergunta:

Como podemos agrupar informações que pertencem à mesma coisa?

A resposta é:

Estruturas (struct).

---

# 2. O que é uma struct

Uma struct é uma forma de agrupar variáveis diferentes em um único tipo de dado.

É como se você criasse uma caixinha de informações.

Exemplo:

struct cliente
{
    char nome[30];
    char endereco[40];
    char cidade[30];
    char telefone[11];
    int cep;
};

Aqui criamos um modelo de cliente.

Ainda não criamos um cliente, apenas o molde.

---

# 3. Criando uma variável da estrutura

Agora precisamos criar um cliente real usando o molde.

struct cliente infos;

Agora existe um cliente chamado infos.

Ele tem dentro dele:

infos.nome  
infos.endereco  
infos.cidade  
infos.telefone  
infos.cep  

Perceba a lógica:

variavel_da_struct.membro

Isso usa o operador ponto (.).

---

# 4. Guardando dados na estrutura

Agora vamos preencher os dados.

gets(infos.nome);
gets(infos.endereco);
gets(infos.cidade);
gets(infos.telefone);
scanf("%d",&infos.cep);

Aqui estamos colocando dados dentro da estrutura.

Depois podemos imprimir:

printf("%s", infos.nome);
printf("%s", infos.endereco);
printf("%s", infos.cidade);
printf("%s", infos.telefone);
printf("%d", infos.cep);

---

# 5. Pensamento importante

Pare um momento.

Pergunta importante:

A estrutura é um tipo de variável ou um modelo?

Resposta:

Ela é um modelo de variável complexa.

É como um projeto de casa.

Primeiro você faz o projeto.

Depois constrói várias casas iguais.

---

# 6. Passando dados da estrutura para funções

Você pode pegar um elemento da estrutura e enviar para uma função.

Exemplo:

f_test(charlie.alpha);

Aqui estamos passando apenas um membro da estrutura.

Isso é comum quando queremos processar um valor específico.

---

# 7. Passando o endereço de um membro

Se quisermos modificar o valor dentro da função, usamos ponteiro.

Exemplo:

func(&charlie.bravo);

Aqui passamos o endereço da variável.

Isso permite que a função altere o valor original.

---

# 8. Passando a estrutura inteira

Também podemos passar a estrutura inteira para uma função.

Exemplo:

void f1(struct clock var)
{
    printf("%d", var.hours);
}

A função recebe uma cópia da estrutura.

Isso funciona, mas pode ser mais pesado se a estrutura for grande.

---

# 9. Ponteiros para estruturas

Agora chegamos em algo muito usado em sistemas embarcados.

Podemos criar ponteiros para estruturas.

Exemplo:

struct drinks *cheers;

Isso significa:

cheers aponta para uma estrutura drinks.

Depois fazemos:

cheers = &open_bar;

Agora o ponteiro aponta para a estrutura.

---

# 10. Acessando estrutura usando ponteiro

Existem duas formas.

Forma difícil:

(*cheers).margarita

Funciona, mas é confusa.

Forma correta:

cheers->margarita

Esse operador -> é chamado de operador seta.

Ele significa:

acessar membro através de ponteiro.

---

# 11. Por que usar ponteiro de struct

Porque é mais eficiente.

Se você passar uma struct grande para uma função:

struct gigante

O computador precisa copiar toda a estrutura.

Se usar ponteiro:

struct gigante *

Ele passa apenas o endereço na memória.

Muito mais rápido.

---

# 12. O que é union

Agora aparece outro conceito importante.

A union é parecida com struct, mas funciona diferente.

Struct:

cada variável tem seu espaço na memória.

Union:

todas compartilham o mesmo espaço.

Exemplo:

union teste
{
    short val1;
    char val2;
};

Aqui:

val1 e val2 usam o mesmo endereço.

Ou seja:

Se mudar um, o outro muda também.

---

# 13. Para que serve union

Ela é usada quando queremos:

- economizar memória
- manipular bytes
- converter tipos

Exemplo clássico:

Separar um número em bytes para enviar em comunicação serial.

---

# 14. Enum

Agora imagine o seguinte.

Você quer representar carros:

ford  
honda  
volks  
renault  

Poderia usar números.

Mas isso é confuso.

Então usamos enum.

enum carros
{
    ford,
    honda,
    volks,
    renault
};

Automaticamente:

ford = 0  
honda = 1  
volks = 2  
renault = 3  

Isso deixa o código mais legível.

---

# 15. Typedef

Agora imagine que você usa muito:

float

Mas quer chamar de reais.

Pode fazer:

typedef float reais;

Agora:

reais valor;

É o mesmo que:

float valor;

Isso não cria um tipo novo, apenas um apelido.

---

# 16. Typedef com struct

Isso é muito comum.

Em vez de escrever:

struct cliente pessoa;

Podemos fazer:

typedef struct
{
    char nome[30];
} cliente;

Agora basta:

cliente pessoa;

Muito mais limpo.

---

# 17. Resumo geral

Struct

Agrupa várias variáveis relacionadas.

Exemplo:

cliente  
    nome  
    endereço  
    telefone  

---

Ponteiro de struct

Permite acessar struct de forma eficiente.

Operador usado:

->

---

Union

Várias variáveis compartilham a mesma memória.

Usado para:

- manipulação de bytes
- otimização de memória

---

Enum

Define conjunto de constantes inteiras.

Exemplo:

enum estados

---

Typedef

Cria apelido para tipos.

Exemplo:

typedef float reais;

---

# 18. Reflexão final (Paulo Freire)

Programar não é decorar comandos.

É entender como organizar o pensamento.

Estruturas ensinam algo fundamental:

Problemas complexos precisam ser organizados em estruturas.

Isso vale para:

- software
- engenharia
- vida real.

Primeiro você organiza os dados.

Depois resolve o problema.
