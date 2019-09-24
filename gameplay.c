#include "memoria.h"

void pedeLinha(int *posL , int *pQtdL){
    do{
        printf("\nEscolha uma linha\n");
        scanf("%d", posL);
    }while(*posL < 0 || *posL >= *pQtdL);
}

void pedeColuna(int *posC, int *pQtdC){
    do{
       printf("\nEscolha uma coluna \n");
       scanf("%d", posC);
    }while(*posC < 0 || *posC >= *pQtdC);
}

char pedePosicao(char hiddenBoard[TAM_L][TAM_C], char tab[TAM_L][TAM_C], int *pQtdL, int *pQtdC){
    int posL = 0 , posC = 0;
    pedeLinha(&posL, pQtdL);
    pedeColuna(&posC, pQtdC);

    tab[posL][posC] = hiddenBoard[posL][posC];
    printf("%c", tab[posL][posC]);
    return hiddenBoard[posL][posC];
}

void validaPosicao(char hiddenBoard[TAM_L][TAM_C], char tab[TAM_L][TAM_C], int tentativas, int *pQtdL, int *pQtdC){
    char card1, card2;
    card1 = pedePosicao(hiddenBoard, tab, pQtdL, pQtdC);
    card2 = pedePosicao(hiddenBoard, tab , pQtdL, pQtdC);

    tentativas++;
    if(card1 == card2){
        printf("\n\t Acertou\n\n");
        visualizarTabuleiro(tab, pQtdL, pQtdC);
    }else if(card1 == '?' || card2 == '?'){
        printf("\n\tWILD CARD\n\n");
    }else{
        visualizarTabuleiro(tab, pQtdL, pQtdC);
        for(int l=0; l < *pQtdL; l++){
            for(int c=0; c < *pQtdC; c++){
                if(tab[l][c] == card1 || tab[l][c] == card2){
                    tab[l][c] = '-';
                }
            }
        }
        timerPause(3000);
        visualizarTabuleiro(tab, pQtdL, pQtdC);
        printf("\n\t ;-; Tente mais uma vez\n\n");
    }
}

void timerPause(float delay){
    int msec = 0; /* 10ms */
    clock_t before = clock();

    do {
          clock_t difference = clock() - before;
          msec = difference * 1000 / CLOCKS_PER_SEC;
    } while ( msec < delay );

}
