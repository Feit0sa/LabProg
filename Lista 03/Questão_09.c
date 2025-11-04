/* Faça um programa que leia uma matriz bidimensional do usuário, de dimensão 3x3, e apresente os
elementos da diagonal principal. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3
#define MAX 10

int main() {
    
    // Declarações
    int matriz[TAM][TAM];
    
    // Gerando a matriz
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            matriz[i][j] = rand() % MAX;
        }
    }

    // Printando a matriz
    puts("Matriz gerada:");
    printf("[");
    for (int i = 0; i < TAM; i++) {
        printf("[ ");
        for (int j = 0; j < TAM; j++) {
            printf("%d ", matriz[i][j]);
        }       
        printf("]");
    }
    printf("]\n\n");

    // Printando a diagonal principal
    puts("Diagonal principal");
    printf("[ ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", matriz[i][i]);
    }
    printf("]\n");

    return 0;
}