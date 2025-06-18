#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};


    int navioH[TAMANHO_NAVIO] = {3, 3, 3};
    int navioV[TAMANHO_NAVIO] = {3, 3, 3};
    int navioD1[TAMANHO_NAVIO] = {3, 3, 3}; 
    int navioD2[TAMANHO_NAVIO] = {3, 3, 3};


    int linhaH = 2, colunaH = 1; 
    int linhaV = 5, colunaV = 4;  
    int linhaD1 = 0, colunaD1 = 0;     
    int linhaD2 = 0, colunaD2 = 9;      


    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int podePosicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaH][colunaH + i] != 0) {
                podePosicionar = 0;
                break;
            }
        }
        if (podePosicionar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaH][colunaH + i] = navioH[i];
            }
        }
    }

    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int podePosicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] != 0) {
                podePosicionar = 0;
                break;
            }
        }
        if (podePosicionar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = navioV[i];
            }
        }
    }


    if (linhaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int podePosicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {
                podePosicionar = 0;
                break;
            }
        }
        if (podePosicionar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = navioD1[i];
            }
        }
    }

    if (linhaD2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && colunaD2 - (TAMANHO_NAVIO - 1) >= 0) {
        int podePosicionar = 1;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {
                podePosicionar = 0;
                break;
            }
        }
        if (podePosicionar) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = navioD2[i];
            }
        }
    }

    printf("\nTabuleiro de Batalha Naval:\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}