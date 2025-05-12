#include <stdio.h>

int main(){

    int tabuleiro[10][10] = {0};

    int navioH[3] = {3, 3, 3}; // Navios horizontais
    int navioV[3] = {3, 3, 3}; // Navios verticais

    int linhaH = 2, colunaH = 3;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = navioH[i];
    }
    
    // 4. Posicionamento do navio vertical (linha 5, coluna 7)
    int linhaV = 5, colunaV = 7;
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = navioV[i];
    }

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

    printf("Tabuleiro inicial:\n");
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}