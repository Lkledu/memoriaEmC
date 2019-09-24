#include "memoria.h"

int main()
{
    char tabuleiro[TAM_L][TAM_C];
    char hiddenBoard[TAM_L][TAM_C];
    int qtdL, qtdC;
    int tentativas = 0;

    srand(time(0));
    construirTabuleiro(tabuleiro, &qtdL, &qtdC);

    visualizarTabuleiro(tabuleiro, &qtdL, &qtdC);

    posicionaLetras(hiddenBoard, &qtdL, &qtdC);
    visualizarTabuleiro(hiddenBoard, &qtdL, &qtdC);
    validaPosicao(hiddenBoard, tabuleiro, tentativas, &qtdL, &qtdC);
    return 0;
}
