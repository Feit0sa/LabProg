/* Faça um programa que gere uma matriz bidimensional com elementos aleatórios e receba do usuário
um valor inteiro x. O programa deve informar quantas vezes x aparece na matriz gerada. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3
#define MAX 10

int main() {
    
    // Declarações
    int matriz[TAM][TAM], x, count;
    
    // Gerando a matriz
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            matriz[i][j] = rand() % MAX;
        }
    }

    // Valor de entrada
    puts("Digite o valor de entrada para a verificação:");
    scanf("%d", &x);

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
    
    // Verificando quantas vezes x aparece na matriz
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (x == matriz[i][j]) count++;
        }
    }

    // Saída
    printf("O valor de entrada [%d] aparece %d vezes na matrizes gerada.\n", x, count);

    return 0;
}