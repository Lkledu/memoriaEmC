#include "memoria.h"

void solicitarDimensoesTabuleiro(int *pQtdL, int *pQtdC){

    do{
        printf("\nDigite a quantidade de linhas do seu tabuleiro: \n");
        scanf("%i", pQtdL);
    }while(*pQtdL < 3 || *pQtdL > 6);

    do{
        printf("\nDigite a quantidade de colunas do seu tabuleiro: \n");
        scanf("%i", pQtdC);
    }while(*pQtdC < 3 || *pQtdC > 6);

}

void preencherTabuleiro(char tab[TAM_L][TAM_C], int *pQtdL, int *pQtdC){
    for(int l=0; l<*pQtdL; l++){
        for (int c=0; c<*pQtdC; c++){
            tab[l][c] = '-';
        }
    }
}

void construirTabuleiro(char tab[TAM_L][TAM_C], int *pQtdL, int *pQtdC){
    solicitarDimensoesTabuleiro(pQtdL, pQtdC);
    preencherTabuleiro(tab, pQtdL, pQtdC);
}

void visualizarTabuleiro(char tab[TAM_L][TAM_C], int *pQtdL, int *pQtdC){
    system("cls");
    printf("\n");
    for(int l=0; l<*pQtdL; l++){
        printf("\t");
        for (int c=0; c<*pQtdC; c++){
            printf("| %c |", tab[l][c]);
        }
        printf("\n");
    }
}

void cleanHiddenBoard(char tabLetra[TAM_L][TAM_C]){
    for(int l=0; l < TAM_L; l++){
        for (int c=0; c< TAM_C; c++){
            tabLetra[l][c] = '0';
        }
    }
}

void posicionaLetras(char tabLetra[TAM_L][TAM_C], int *pQtdL, int *pQtdC){
    char cards[18] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R'};

    int ptrL = *pQtdL;
    int ptrC = *pQtdC;
    int boardLenght = ptrL * ptrC;
    int verificaParImpar = boardLenght % 2;
    int maxPares = (ptrL * ptrC)/2;

    cleanHiddenBoard(tabLetra);

    if(verificaParImpar == 1){
        tabLetra[rand() % ptrL][rand() % ptrC] = '?';
    }

    for(int card = 0; card < maxPares; card++){

        int C = rand() % ptrC;
        int L = rand() % ptrL;

        int putLetter = 0;

        while(putLetter < 2){
            if(tabLetra[L][C] == '0'){
                tabLetra[L][C] = cards[card];
                C = rand() % ptrC;
                L = rand() % ptrL;
                putLetter++;
            }else{
                C = rand() % ptrC;
                L = rand() % ptrL;
            }
        }
    }

}
