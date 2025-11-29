/* Escreva um programa em C que informe se o somatório da diagonal principal de matriz N x N gerada é par ou ímpar. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int somaDiagonal(int **, const unsigned);

int main(int argc, char **argv) {
    
    if (argc != 3) {
        printf("Uso incorreto: %s <tamanho> <valorMax>\n", *argv);
        exit(1);
    }
    
    int **matriz;
    int tamanho = atoi(argv[1]);
    int max = atoi(argv[2]);
    
    matriz = (int **) malloc(tamanho * sizeof(int *));
    if (matriz ==  NULL) {
        puts("Erro de memória!");
        exit(2);
    }


    for (int i = 0; i < tamanho; i++) {
        matriz[i] = (int *) malloc(tamanho * sizeof(int));
        if (matriz[i] == NULL) {
                puts("Erro de memória!");
                exit(3);
        }
    }

    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j< tamanho; j++) {
                *(*(matriz+i)+j) = rand() % max;
        }
    }
    
    for (int i = 0; i < tamanho; i++) {
        printf("[ ");
        for (int j = 0; j < tamanho; j++) {
                printf("%d ", *(*(matriz+i)+j));
        }
        puts("]");
    }
    
    int res = somaDiagonal(matriz, tamanho);
    printf("Somatório da diagonal principal: %d\n", res);
    
    for (int i = 0; i < tamanho; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}

int somaDiagonal(int **matriz, const unsigned tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        for (int j = 0; j < tamanho; j++) {
            if (i == j) {
                soma += *(*(matriz+i)+j);
            }
        }
    }
    return soma;
}