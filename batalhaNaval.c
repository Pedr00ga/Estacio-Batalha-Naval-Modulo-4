#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10
#define ALTURA 3
#define LARGURA 5

int main() {
    int tabuleiro[LINHAS][COLUNAS] = {0};

    // Posicionamento dos navios
    int navioH[3] = {3, 3, 3};
    int navioV[3] = {3, 3, 3};

    int linhaH = 2, colunaH = 3;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioH[i];
    }
    int linhaH2 = 6, colunaH2 = 4;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH2][colunaH2 + i] = navioH[i];
    }

    int linhaV = 5, colunaV = 7;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioV[i];
    }
    int linhaV2 = 7, colunaV2 = 3;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV2 + i][colunaV2] = navioV[i];
    }

    // Matrizes 3x5 das habilidades
    int cone[ALTURA][LARGURA] = {0};
    int cruz[ALTURA][LARGURA] = {0};
    int octaedro[ALTURA][LARGURA] = {0};

    // Posição central: linha 1 (meio), coluna 2 (meio)
    int centro_linha = 1;
    int centro_coluna = 2;

    // CONE: forma piramidal para baixo
    for (int i = 0; i < ALTURA; i++) {
        for (int j = centro_coluna - i; j <= centro_coluna + i; j++) {
            if (j >= 0 && j < LARGURA) {
                cone[i][j] = 1;
            }
        }
    }

    // CRUZ: uma linha vertical e uma horizontal
    for (int i = 0; i < ALTURA; i++) {
        cruz[i][centro_coluna] = 1;
    }
    for (int j = 0; j < LARGURA; j++) {
        cruz[centro_linha][j] = 1;
    }

    // OCTAEDRO: losango em 3x5
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            if (abs(i - centro_linha) + abs(j - centro_coluna) <= 1) {
                octaedro[i][j] = 1;
            }
        }
    }

    // Ponto de origem no tabuleiro
    int origemConeLinha = 1, origemConeColuna = 1;
    int origemCruzLinha = 4, origemCruzColuna = 4;
    int origemOctaLinha = 7, origemOctaColuna = 7;

    // Função de sobreposição das habilidades
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            int linhaC = origemConeLinha + i - centro_linha;
            int colunaC = origemConeColuna + j - centro_coluna;

            if (linhaC >= 0 && linhaC < LINHAS && colunaC >= 0 && colunaC < COLUNAS) {
                if (cone[i][j] == 1 && tabuleiro[linhaC][colunaC] == 0) {
                    tabuleiro[linhaC][colunaC] = 5;
                }
            }

            int linhaR = origemCruzLinha + i - centro_linha;
            int colunaR = origemCruzColuna + j - centro_coluna;

            if (linhaR >= 0 && linhaR < LINHAS && colunaR >= 0 && colunaR < COLUNAS) {
                if (cruz[i][j] == 1 && tabuleiro[linhaR][colunaR] == 0) {
                    tabuleiro[linhaR][colunaR] = 5;
                }
            }

            int linhaO = origemOctaLinha + i - centro_linha;
            int colunaO = origemOctaColuna + j - centro_coluna;

            if (linhaO >= 0 && linhaO < LINHAS && colunaO >= 0 && colunaO < COLUNAS) {
                if (octaedro[i][j] == 1 && tabuleiro[linhaO][colunaO] == 0) {
                    tabuleiro[linhaO][colunaO] = 5;
                }
            }
        }
    }

    // Imprime o tabuleiro
    printf("Tabuleiro:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
