/* Faça um programa em C que leia uma string e um caractere do usuário e informe se a string de
entrada contém o caracter fornecido. */

#include <stdio.h>
#include <string.h>

#define TAM 20

int main() {

    char str[TAM], c;

    puts("Digite uma string:");
    fgets(str, TAM, stdin);
    puts("Digite o caractere que deseja procurar na string:");
    scanf("%c", &c);

    if (strchr(str, c) != NULL) {
        printf("A string possui o caractere '%c'.\n", c);
    } else {
        printf("A string não possui o caractere '%c'\n.", c);
    }

    return 0;

}