/* Faça um programa em C que leia um vetor do tipo float com 15 elementos e apresente a soma do
menor e maior elemento do vetor fornecido. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 15
#define MAX 100
#define MIN 0

int main() {
    
    // Declara o vetor e as variáveis
    int v[TAM];
    int menor, maior;

    // Gera o vetor
    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        v[i] = MIN + (rand() % MAX);
    }

    // Inicializa o menor e maior pelo primeiro valor do vetor
    menor = maior = v[0];

    // Imprime o vetor gerado
    puts("Vetor gerado:");
    for (int i = 0; i < TAM; i++) {
        printf("%p - [%d] : %d\n", &v[i], i, v[i]);
    }

    // Verifica o menor e o maior valor do vetor
    for (int i = 0; i < TAM; i++) {
        if (menor > v[i]) {
            menor = v[i];
        } else if (maior < v[i]) {
            maior = v[i];
        }
    }

    printf("Menor : [%d] , Maior - [%d] , Soma - [%d]\n", menor, maior, menor+maior);

    return 0;
}