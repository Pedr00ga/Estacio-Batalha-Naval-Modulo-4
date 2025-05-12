#include <stdio.h>

#define LINHAS 10
#define COLUNAS 10

int main(){
    //Cria o tabuleiro 10x10 com todas as posicoes zeradas
    int tabuleiro[LINHAS][COLUNAS] = {0};

    int navioH[3] = {3, 3, 3}; // Navios array do navio horizontal
    int navioV[3] = {3, 3, 3}; // Navios array do navio vertical

    // Define posicionamento dos navios horizontais
    int linhaH = 2, colunaH = 3;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioH[i];
    }
    int linhaH2 = 6, colunaH2 = 4;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH2][colunaH2 + i] = navioH[i];
    }

    //Define posicionamento dos navios verticais
    int linhaV = 5, colunaV = 7;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioV[i];
    }
    int linhaV2 = 7, colunaV2 = 3;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV2 + i][colunaV2] = navioV[i];
    }

    // Faz o tratamento de erros para verificar se os navios estão fora do tabuleiro ou colidiram
    if (linhaV < 0 || linhaV >= 10 || colunaV < 0 || colunaV >= 10) {
        printf("Posicao invalida para o navio vertical.\n");
        return 1;
    }
    if (linhaH < 0 || linhaH >= 10 || colunaH < 0 || colunaH >= 10) {
        printf("Posicao invalida para o navio horizontal.\n");
        return 1;
    }

    if (linhaV == linhaH && colunaV == colunaH) {
        printf("Navios colidiram!\n");
        return 1;
    }

    // Mostra o tabuleiro com o navios posicionados
    printf("Tabuleiro:\n");
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}