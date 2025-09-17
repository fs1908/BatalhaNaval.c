#include <stdio.h>

int main() {
    int tabuleiro[10][10];

    // Inicializa tabuleiro com água (0)
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ---- NAVIO HORIZONTAL ----
    int linhaH = 2, colunaH = 4;
    if (colunaH + 3 <= 10) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[linhaH][colunaH + j] = 3;
        }
    }

    // ---- NAVIO VERTICAL ----
    int linhaV = 5, colunaV = 7;
    if (linhaV + 3 <= 10) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaV + i][colunaV] = 3;
        }
    }

    // ---- NAVIO DIAGONAL DESCENDO ↘ ----
    int linhaD1 = 0, colunaD1 = 0;
    if (linhaD1 + 3 <= 10 && colunaD1 + 3 <= 10) {
        for (int k = 0; k < 3; k++) {
            tabuleiro[linhaD1 + k][colunaD1 + k] = 3;
        }
    }

    // ---- NAVIO DIAGONAL SUBINDO ↗ ----
    int linhaD2 = 9, colunaD2 = 0;
    if (linhaD2 - 2 >= 0 && colunaD2 + 3 <= 10) {
        for (int k = 0; k < 3; k++) {
            tabuleiro[linhaD2 - k][colunaD2 + k] = 3;
        }
    }

    // ---- MOSTRA TABULEIRO ----
    printf("\n--- Tabuleiro ---\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
