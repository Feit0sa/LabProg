/* Escreva um programa que dado um vetor X de inteiros, realize a seguinte normalização dos dados (min-max): 
                            X' = (X-min(X))/(max(X)-min(X))
onde min() e max() correspondem ao menor e maior do vetor, respectivamente.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 10
#define MAX 11

float max(const float *, const unsigned);
float min(const float *, const unsigned);
void normalizarVetor(float *, const unsigned);

int main() {

    float v[TAM];
    float *pv = v;

    srand(time(NULL));
    for (int i = 0; i < TAM; i++) {
        *(pv+i) = rand() % MAX;
    }

    puts("Vetor antes da normalização:");
    for (int i = 0; i < TAM; i++) {
        printf("[%p] %f\n", pv+i, *(pv+i));
    }

    normalizarVetor(pv, TAM);

    puts("Vetor depois da normalização:");
    for (int i = 0; i < TAM; i++) {
        printf("[%p] %f\n", pv+i, *(pv+i));
    }

    return 0;
}

float max(const float *pv, const unsigned tam) {
    int maior, menor;
    maior = *pv;
    menor = *pv;

    for (int i = 0; i < tam; i++) {
        if (*(pv+i) > maior) {
            maior = *(pv+i);
        }
        else if (*(pv+i) < menor) {
            menor = *(pv+i);
        }
    }

    return maior;
}

float min(const float *pv, const unsigned tam) {
    int maior, menor;
    maior = *pv;
    menor = *pv;

    for (int i = 0; i < tam; i++) {
        if (*(pv+i) > maior) {
            maior = *(pv+i);
        }
        else if (*(pv+i) < menor) {
            menor = *(pv+i);
        }
    }

    return menor;
}

void normalizarVetor(float *pv, const unsigned tam) {
    for (int i = 0; i < tam; i++) {
        *(pv+i) = (*(pv+i)-min(pv, tam))/(max(pv, tam)-min(pv, tam));
    }
}