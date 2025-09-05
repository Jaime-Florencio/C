# 📚 Linguagem C – Aula 7.3  
## Passagem de Matrizes para Funções – Criando um Jogo "Batalha Naval"

**📅 Data de estudo:** 05/09/2025  
**📚 Tema:** Matrizes, Funções e Manipulação de Strings  

---

### ✅ Pré-requisito
- Conhecimento de **vetores e matrizes**.  
- Noções básicas de **funções em C**.  

---

### 📖 Objetivo da Aula
- Entender como **passar matrizes como parâmetros** para funções em C.  
- Implementar um **jogo simples de Batalha Naval (3x3)**.  
- Fixar os conceitos de **entrada do usuário, aleatoriedade e controle de fluxo**.  

---

### 🧩 Estrutura do Código
O programa está dividido em 4 partes principais:

1. **Protótipos das funções** → avisam ao compilador quais funções existirão depois.  
2. **Função `main()`** → cria o tabuleiro, sorteia bombas e inicia o jogo.  
3. **Função `imprimirfolha()`** → imprime a matriz formatada no estilo de tabuleiro.  
4. **Função `converte_coluna()`** → traduz letra da coluna (A, B, C) em número (0, 1, 2).  
5. **Função `jogo()`** → controla vidas, jogadas e mostra o resultado final.  

---

### 📜 Código Completo
```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Protótipos das funções
void imprimirfolha(char matriz[3][3]);
void jogo(char campo[3][3]);
int converte_coluna(char letra);

int main() {
    char campo[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    srand(time(NULL));  // Inicializa a aleatoriedade

    // Sorteia 3 bombas
    int bombas = 0;
    while (bombas < 3) {
        int x = rand() % 3;
        int y = rand() % 3;
        if (campo[x][y] == ' ') {
            campo[x][y] = '@';
            bombas++;
        }
    }

    jogo(campo);  // Inicia o jogo
    return 0;
}

// Mostra o tabuleiro (matriz)
void imprimirfolha(char matriz[3][3]) {
    printf("     A    B    C  \n");
    printf("   ----------------\n");
    for (int i = 0; i < 3; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("  %c  |", matriz[i][j]);
        }
        printf("\n   ----------------\n");
    }
}

// Converte letra da coluna em número
int converte_coluna(char letra) {
    if (letra == 'A' || letra == 'a') return 0;
    if (letra == 'B' || letra == 'b') return 1;
    if (letra == 'C' || letra == 'c') return 2;
    return -1; // inválido
}

// Função principal do jogo
void jogo(char campo[3][3]) {
    int vidas = 3;

    char visivel[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    while (vidas > 0) {
        imprimirfolha(visivel);

        int linha;
        char letra_coluna;
        printf("Digite a celula (ex: 2 A): ");
        scanf(" %d %c", &linha, &letra_coluna);

        int coluna = converte_coluna(letra_coluna);
        linha = linha - 1;

        if (linha >= 0 && linha < 3 && coluna >= 0 && coluna < 3) {
            if (campo[linha][coluna] == '@') {
                printf("Bomba! Voce perdeu uma vida.\n");
                visivel[linha][coluna] = '@';
                vidas--;
            } else {
                printf("Agua! Voce esta seguro.\n");
                visivel[linha][coluna] = 'O';
            }
        } else {
            printf("Entrada invalida. Tente novamente.\n");
        }

        printf("Vidas restantes: %d\n", vidas);
    }

    printf("\nFim de jogo! Voce perdeu todas as vidas.\n");
    printf("Campo real com bombas:\n");
    imprimirfolha(campo);
}
