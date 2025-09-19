#include <stdio.h>
#include <stdlib.h>  

#define TAM 10
#define HAB 5  // tamanho da matriz de habilidade (5x5)

int main() {
    int tabuleiro[TAM][TAM];

    // Inicializa tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ---- NAVIO HORIZONTAL ----
    int linhaH = 2, colunaH = 4;
    if (colunaH + 3 <= TAM) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[linhaH][colunaH + j] = 3;
        }
    }

    // ---- NAVIO VERTICAL ----
    int linhaV = 5, colunaV = 7;
    if (linhaV + 3 <= TAM) {
        for (int i = 0; i < 3; i++) {
            tabuleiro[linhaV + i][colunaV] = 3;
        }
    }

    // ---- NAVIO DIAGONAL DESCENDO ↘ ----
    int linhaD1 = 0, colunaD1 = 0;
    if (linhaD1 + 3 <= TAM && colunaD1 + 3 <= TAM) {
        for (int k = 0; k < 3; k++) {
            tabuleiro[linhaD1 + k][colunaD1 + k] = 3;
        }
    }

    // ---- NAVIO DIAGONAL SUBINDO ↗ ----
    int linhaD2 = 9, colunaD2 = 0;
    if (linhaD2 - 2 >= 0 && colunaD2 + 3 <= TAM) {
        for (int k = 0; k < 3; k++) {
            tabuleiro[linhaD2 - k][colunaD2 + k] = 3;
        }
    }

    // ---- MATRIZES DE HABILIDADE (5x5) ----
    int cone[HAB][HAB];
    int cruz[HAB][HAB];
    int octaedro[HAB][HAB];

    // Cone (forma de triângulo apontando para baixo)
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (j >= (HAB/2 - i) && j <= (HAB/2 + i) && i <= HAB/2) {
                cone[i][j] = 1;
            } else {
                cone[i][j] = 0;
            }
        }
    }

    // Cruz
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (i == HAB/2 || j == HAB/2) {
                cruz[i][j] = 1;
            } else {
                cruz[i][j] = 0;
            }
        }
    }

    // Octaedro (losango)
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (abs(i - HAB/2) + abs(j - HAB/2) <= HAB/2) {
                octaedro[i][j] = 1;
            } else {
                octaedro[i][j] = 0;
            }
        }
    }

    // ---- SOBREPOR HABILIDADES AO TABULEIRO ----
    // Origens fixas
    int origemConeL = 4, origemConeC = 2;
    int origemCruzL = 6, origemCruzC = 5;
    int origemOctL = 3, origemOctC = 8;

    // Cone
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (cone[i][j] == 1) {
                int x = origemConeL - HAB/2 + i;
                int y = origemConeC - HAB/2 + j;
                if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                    if (tabuleiro[x][y] == 0) tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // Cruz
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (cruz[i][j] == 1) {
                int x = origemCruzL - HAB/2 + i;
                int y = origemCruzC - HAB/2 + j;
                if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                    if (tabuleiro[x][y] == 0) tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // Octaedro
    for (int i = 0; i < HAB; i++) {
        for (int j = 0; j < HAB; j++) {
            if (octaedro[i][j] == 1) {
                int x = origemOctL - HAB/2 + i;
                int y = origemOctC - HAB/2 + j;
                if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                    if (tabuleiro[x][y] == 0) tabuleiro[x][y] = 5;
                }
            }
        }
    }

    // ---- MOSTRA TABULEIRO ----
    printf("\n--- Tabuleiro com Habilidades ---\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ "); // água
            } else if (tabuleiro[i][j] == 3) {
                printf("■ "); // navio
            } else if (tabuleiro[i][j] == 5) {
                printf("* "); // área de habilidade
            }
        }
        printf("\n");
    }

    return 0;
}
