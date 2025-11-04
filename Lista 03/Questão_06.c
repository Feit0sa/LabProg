/* Faça um programa em C que leia uma string do usuário e a apresente na forma inversa. */

#include <stdio.h>
#include <string.h>

#define TAM 20

int main() {

    char str[TAM], temp;

    puts("Digite a string:");
    fgets(str, TAM, stdin);

    str[strcspn(str, "\n")] = '\0';

    printf("String antes de inverter: %s\n", str);

    for (int i = 0, j = strlen(str)-1; i < j; i++, j--) {
        temp = str[j];
        str[j] = str[i];
        str[i] = temp;
    }

    printf("String depois de inverter: %s\n", str);

    return 0;
}