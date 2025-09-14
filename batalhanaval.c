#include <stdio.h>

int main() {
    int tabuleiro[10][10]; // tabuleiro 10x10
    int navioHorizontal[3] = {3, 3, 3}; // navio horizontal
    int navioVertical[3]   = {3, 3, 3}; // navio vertical

    // Inicializa o tabuleiro com 0
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas fixas dos navios
    int linhaH = 2, colunaH = 4; // início do navio horizontal
    int linhaV = 5, colunaV = 7; // início do navio vertical

    // Posiciona navio horizontal (3 casas)
    if (colunaH + 3 <= 10) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[linhaH][colunaH + j] = navioHorizontal[j];
        }
    }

    // Posiciona navio vertical (3 casas)
    if (linhaV + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    }

    // Exibe o tabuleiro
    printf("\n--- Tabuleiro ---\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}