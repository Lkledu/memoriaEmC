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
    return hiddenBoard[posL][posC];
}

void validaPosicao(char hiddenBoard[TAM_L][TAM_C], char tab[TAM_L][TAM_C], int *tentativas, int *pQtdL, int *pQtdC){
    char card1, card2;
    card1 = pedePosicao(hiddenBoard, tab, pQtdL, pQtdC);
    card2 = pedePosicao(hiddenBoard, tab , pQtdL, pQtdC);

    ++*tentativas;
    if(card1 == card2){
        visualizarTabuleiro(tab, pQtdL, pQtdC);
        printf("\n\t Acertou\n\n");
    }else if(card1 == '?' || card2 == '?'){
        visualizarTabuleiro(tab, pQtdL, pQtdC);

        for(int l=0; l < *pQtdL; l++){
            for(int c=0; c < *pQtdC; c++){
                if(tab[l][c] == card1 || tab[l][c] == card2){
                    tab[l][c] = '-';
                }
            }
        }

        for(int l=0; l < *pQtdL; l++){
            for(int c=0; c < *pQtdC; c++){
                if((tab[l][c] != '-') && ((tab[l][c] != card1) || (tab[l][c] != card2))){
                    char apagar = tab[l][c];
                    tab[l][c] = '-';
                    for(int i=0; i < *pQtdL; i++){
                        for(int j =0; j < *pQtdC; j++){
                            if(tab[l][c] == apagar){
                                tab[l][c] = '-';
                            }
                        }
                    }
                }
            }
        }
        Sleep(3000);
        visualizarTabuleiro(tab, pQtdL, pQtdC);

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
        Sleep(3000);
        visualizarTabuleiro(tab, pQtdL, pQtdC);
        printf("\n\t ;-; Tente mais uma vez\n\n");
    }

}

void verificaFimDeJogo(char hiddenBoard[TAM_L][TAM_C], char tab[TAM_L][TAM_C], int *tentativas, int *pQtdL, int *pQtdC){
    int ptrL = *pQtdL;
    int ptrC = *pQtdC;
    int boardLenght = ptrL * ptrC;
    int counterFinish = 0;
    do{
        counterFinish = 0;
        for(int l=0; l < *pQtdL; l++){
            for(int c=0; c < *pQtdC; c++){
                if(tab[l][c] != '-'){
                    counterFinish++;
                }
            }
        }
        if(counterFinish < boardLenght){
            validaPosicao(hiddenBoard, tab, tentativas, pQtdL, pQtdC);
        }

    }while(counterFinish < boardLenght);

    printf("\n\tFIM DO JOGO!\n\n");

    int result = boardLenght * 0.3;

    if(*tentativas > result){
        printf("Parabéns você tem boa memória!");
    }else{
        printf("Você precisa treinar mais sua memória");
    }
}
