/* Escreva um programa que gere dois vetores (X e Y ) com números pseudoaleatórios no 
intervalo [0,N − 1]. Crie uma matriz M com dimensões NxN que armazene as
coocorrências dos elementos de X e Y da seguinte forma:
Por exemplo, para N = 7: 
X = [4, 6, 2, 3, 2, 3, 0, 2, 5, 5, 2, 6, 0, 5]
Y = [3, 6, 2, 1, 0, 2, 1, 3, 5, 5, 3, 4, 1, 5]
Portanto,
    | 0 0 1 0 0 0 0 |
    | 2 0 0 1 0 0 0 |
    | 0 0 1 1 0 0 0 |
M = | 0 0 2 0 1 0 1 |
    | 0 0 0 0 0 0 0 |
    | 0 0 0 0 0 3 0 |
    | 0 0 0 0 0 0 1 |
Use alocação dinâmica e linha de comando.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **alocaMatriz(const unsigned);
void liberaMatriz(int **, const unsigned);
int *alocaVetor(const unsigned);
void geraVetor(int *, const unsigned, const unsigned);
void incrementaCoocorrencias(const int *, const int *, int **, const unsigned, const unsigned);
void imprimeVetor(const int *, const unsigned);
void imprimeMatriz(int **, const unsigned);

int main(int argc, char **argv) {
    
    if (argc != 3) {
        printf("Uso incorreto: %s <tamanhoVetor> <valorMax>\n", *argv); // 14 7
        exit(1);
    }

    int tam = atoi(argv[1]);
    int max = atoi(argv[2]);

    int X[] = {4, 6, 2, 3, 2, 3, 0, 2, 5, 5, 2, 6, 0, 5};
    int Y[] = {3, 6, 2, 1, 0, 2, 1, 3, 5, 5, 3, 4, 1, 5};
    int *x = X, *y = Y;

    int **matriz = alocaMatriz(max);
    // int *x = alocaVetor(tam);
    // int *y = alocaVetor(tam);

    srand(time(NULL));
    // geraVetor(x, tam, max);
    // geraVetor(y, tam, max);
    imprimeVetor(x, tam);
    imprimeVetor(y, tam);
    incrementaCoocorrencias(x, y, matriz, tam, max);
    imprimeMatriz(matriz, max);
    liberaMatriz(matriz, max);
    // free(x);
    // free(y);

    return 0;
}

int **alocaMatriz(const unsigned tamanho) {
    int **matriz = (int **) calloc(tamanho, sizeof(int *));
    if (matriz == NULL) {
        puts("Memória não alocada!");
        exit(2);
    }

    for (int i = 0; i < tamanho; i++) {
        *(matriz+i) = (int *) calloc(tamanho, sizeof(int));
        if (*(matriz+i) == NULL)  {
            puts("Memória não alocada!");
            exit(2);
        }
    }

    return matriz;
}

void liberaMatriz(int **matriz, const unsigned tamanho) {
    for (int i = 0; i < tamanho; i++) {
        free(*(matriz+i));
    }
    free(matriz);
}

int *alocaVetor(const unsigned tamanho) {
    return malloc(tamanho * sizeof(int));
}

void incrementaCoocorrencias(const int *x, const int *y, int **matriz, const unsigned tamanhoVetor, const unsigned valorMax) {
    for (int i = 0; i < tamanhoVetor; i++) {
        (*(*(matriz+*(x+i))+*(y+i)))++;
    }
}

void imprimeVetor(const int *v, const unsigned tamanho) {
    printf("Vetor: [ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", *(v + i));
    }
    puts("]");
}

void imprimeMatriz(int **matriz, const unsigned tamanho) {
    puts("Matriz:");
    for (int i = 0; i < tamanho; i++) {
        printf("[ ");
        for (int j = 0; j < tamanho; j++) {
                printf("%d ", *(*(matriz+j)+i));
        }
        puts("]");
    }
}

void geraVetor(int *v, const unsigned tamanho, const unsigned max) {
    for (int i = 0; i < tamanho; i++) {
        *(v+i) = rand() % max;
    }
}