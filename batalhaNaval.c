#include <stdio.h>
#include <stdlib.h>

#define tamanho_tabuleiro 10
#define tamanho_navio 3
#define tamanho_habilidade 5


void aplicar_habilidade(int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro],
                        int habilidade[tamanho_habilidade][tamanho_habilidade],
                        int origem_linha, int origem_coluna) {
    int offset = tamanho_habilidade / 2;
    for (int i = 0; i < tamanho_habilidade; i++) {
        for (int j = 0; j < tamanho_habilidade; j++) {
            int linha = origem_linha - offset + i;
            int coluna = origem_coluna - offset + j;

            if (linha >= 0 && linha < tamanho_tabuleiro &&
                coluna >= 0 && coluna < tamanho_tabuleiro &&
                habilidade[i][j] == 1 &&
                tabuleiro[linha][coluna] == 0) {
                tabuleiro[linha][coluna] = 5;
            }
        }
    }
}

int main() {
    int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro] = {0};

    int navio_h[tamanho_navio] = {3, 3, 3};
    int navio_v[tamanho_navio] = {3, 3, 3};
    int navio_d1[tamanho_navio] = {3, 3, 3}; 
    int navio_d2[tamanho_navio] = {3, 3, 3};

    int linha_h = 2, coluna_h = 1;
    int linha_v = 5, coluna_v = 4;
    int linha_d1 = 0, coluna_d1 = 0;
    int linha_d2 = 0, coluna_d2 = 9;

    for (int i = 0; i < tamanho_navio; i++) {
        if (coluna_h + tamanho_navio <= tamanho_tabuleiro)
            tabuleiro[linha_h][coluna_h + i] = navio_h[i];

        if (linha_v + tamanho_navio <= tamanho_tabuleiro)
            tabuleiro[linha_v + i][coluna_v] = navio_v[i];

        if (linha_d1 + tamanho_navio <= tamanho_tabuleiro && coluna_d1 + tamanho_navio <= tamanho_tabuleiro)
            tabuleiro[linha_d1 + i][coluna_d1 + i] = navio_d1[i];

        if (linha_d2 + tamanho_navio <= tamanho_tabuleiro && coluna_d2 - i >= 0)
            tabuleiro[linha_d2 + i][coluna_d2 - i] = navio_d2[i];
    }

    // Habilidade: cone
    int cone[tamanho_habilidade][tamanho_habilidade] = {0};
    for (int i = 0; i < tamanho_habilidade; i++) {
        for (int j = 0; j < tamanho_habilidade; j++) {
            if (j >= 2 - i && j <= 2 + i && i >= 0)
                cone[i][j] = 1;
        }
    }

    // Habilidade: cruz
    int cruz[tamanho_habilidade][tamanho_habilidade] = {0};
    for (int i = 0; i < tamanho_habilidade; i++) {
        for (int j = 0; j < tamanho_habilidade; j++) {
            if (i == tamanho_habilidade / 2 || j == tamanho_habilidade / 2)
                cruz[i][j] = 1;
        }
    }

    // Habilidade: octaedro
    int octaedro[tamanho_habilidade][tamanho_habilidade] = {0};
    for (int i = 0; i < tamanho_habilidade; i++) {
        for (int j = 0; j < tamanho_habilidade; j++) {
            if (abs(i - 2) + abs(j - 2) <= 2)
                octaedro[i][j] = 1;
        }
    }

    aplicar_habilidade(tabuleiro, cone, 4, 2);
    aplicar_habilidade(tabuleiro, cruz, 6, 6);
    aplicar_habilidade(tabuleiro, octaedro, 7, 2);

    // Exibir o tabuleiro
    printf("\nTabuleiro de Batalha Naval com Habilidades:\n\n");
    for (int i = 0; i < tamanho_tabuleiro; i++) {
        for (int j = 0; j < tamanho_tabuleiro; j++) {
            if (tabuleiro[i][j] == 0)
                printf("0 ");
            else if (tabuleiro[i][j] == 3)
                printf("3 ");
            else if (tabuleiro[i][j] == 5)
                printf("5 ");
        }
        printf("\n");
    }

    return 0;
}