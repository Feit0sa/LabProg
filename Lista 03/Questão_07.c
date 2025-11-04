/* Faça um programa em C que gere um vetor com 3 números inteiros pseudoaleatórios no intervalo
[0, 19] e apresente a sua média aritmética e geométrica. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM 3
#define MAX 20

int main() {

    int v[TAM], arit = 0, geo = 1;

    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        v[i] = rand() % MAX;
    }

    puts("Vetor gerado:");
    for (int i = 0; i < TAM; i++) {
        printf("[%p] - %d\n", &v[i], v[i]);
        arit += v[i];
        geo *= v[i];
    }

    double media_aritmetica = (double) arit / TAM;
    double media_geometrica = pow(geo, 1.0 / TAM);

    printf("\nMédia aritmética: %.2lf", media_aritmetica);
    printf("\nMédia geométrica: %.2lf\n", media_geometrica);

    return 0;
}