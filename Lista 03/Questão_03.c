/* Faça um programa em C que leia uma string do usuário e informe a quantidade de caracteres da
string fornecida. Não use a função strlen(). */

#include <stdio.h>
#include <string.h>

#define TAM 20

int main() {
    
    char str[TAM];
    unsigned count = 0;

    puts("Digite uma string:");
    fgets(str, TAM, stdin);

    while (str[count] != '\n') {
        count++;
    }

    printf("Quantidade de caracteres da string: %d\n", count);

    return 0;
}