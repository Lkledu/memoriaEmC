#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define TAM_L 6
#define TAM_C 6

void solicitarDimensoesTabuleiro(int *pQtdL, int *pQtdC);
void preencherTabuleiro(char tab[TAM_L][TAM_C], int *pQtdL, int *pQtdC);
void construirTabuleiro(char tab[TAM_L][TAM_C], int *pQtdL, int *pQtdC);
void visualizarTabuleiro(char tab[TAM_L][TAM_C], int *pQtdL, int *pQtdC);
void posicionaLetras(char tabLetra[TAM_L][TAM_C], int *pQtdL, int *pQtdC);
void verificaFimDeJogo(char hiddenBoard[TAM_L][TAM_C], char tab[TAM_L][TAM_C], int *tentativas, int *pQtdL, int *pQtdC);

