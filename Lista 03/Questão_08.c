/* Faça um programa em C que gere um vetor com 100 números inteiros pseudoaleatórios no intervalo
definido pelo usuário e apresente esse vetor ordenado (crescente). Faça uma versão com o método
de ordenação por seleção e outra pelo método bolha (bubble sort). */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100

// Protótipo de função
void printVetor(int [], unsigned);
void bubbleSort(int [], unsigned);
void selectionSort(int [], unsigned);

int main() {

    // Declarações
    int v[TAM], w[TAM], min, max;

    // Entrada de intervalo
    puts("Digite o valor mínimo do vetor:");
    scanf("%d", &min);
    puts("Digite o valor máximo do vetor:");
    scanf("%d", &max);
    puts("");

    // Gerando vetores v e w
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        v[i] = min + (rand() % (max-min+1));
        w[i] = min + (rand() % (max-min+1));
    }

    // Printando os vetores antes de ordenar
    puts("Vetor v antes de ordenar:");
    printVetor(v, TAM);
    puts("Vetor w antes de ordenar:");
    printVetor(w, TAM);
    puts("");

    // Ordenando os vetores
    bubbleSort(v, TAM);
    selectionSort(w, TAM);
    
    // Printando os vetores depois de ordenar
    puts("Vetor v depois de ordenar com Bubble Sort:");
    printVetor(v, TAM);
    puts("Vetor w depois de ordenar com Bubble Sort:");
    printVetor(w, TAM);

    return 0;
}

void printVetor(int vetor[], unsigned tamanho) {
    printf("[ ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("]\n");
}

void bubbleSort(int vetor[], unsigned tamanho) {
    int flag = 1;
    for (int i = 0; i < tamanho; i++) {
        flag = 1;
        for (int j = 0; j < tamanho-1; j++) {
            if (vetor[j] > vetor[j+1]) {
                vetor[j] = vetor[j] ^ vetor[j+1];
                vetor[j+1] = vetor[j] ^ vetor[j+1];
                vetor[j] = vetor[j] ^ vetor[j+1];

                flag = 0;
            }
        }

        if (flag) break;
    }
}

void selectionSort(int vetor[], unsigned tamanho) {
    int aux;
    for (int i  = 0; i < tamanho-1; i++) {
        for (int j = i+1; j < tamanho; j++) {
            if (vetor[i] > vetor[j]) {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}