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

    verificaFimDeJogo(hiddenBoard, tabuleiro, &tentativas, &qtdL, &qtdC);
    return 0;
}
