/* Faça um programa em C que concatene duas strings recebidas pelo usuário. Construa uma versão
com uso da função strcat() e outra sem. */

#include <stdio.h>
#include <string.h>

#define TAM 20

int main() {

    // Declarações
    char str1[TAM], str2[TAM], resultado1[2*TAM] = "", resultado2[2*TAM] = "";
    unsigned i = 0, j = 0;

    // Entradas
    puts("Digite a primeira string:");
    fgets(str1, TAM, stdin);
    puts("Digite a segunda string:");
    fgets(str2, TAM, stdin);

    // Removendo o '\n'
    str1[strcspn(str1, "\n")] = '\0';
    str2[strcspn(str2, "\n")] = '\0';

    strcpy(resultado2, str1); // Copiando str1 na resultado2
    strcat(resultado2, str2); // Concatenando str2 na resultado2 com strcat

    // Concatenando str1 na resultado1
    while (str1[j] != '\0') {
     resultado1[i] = str1[j];
        i++;
        j++;
    }

    // Concatenando str2 na resultado1
    j = 0;
    while (str2[j] != '\0') {
     resultado1[i] = str2[j];
        i++;
        j++;
    }
 resultado1[i] = '\0';

    printf("Primeira string [%s]\n", str1);
    printf("Sefunda string [%s]\n", str2);
    printf("Concatenação sem strcat [%s]\n", resultado1);
    printf("Concatenação com strcat [%s]\n", resultado2);

    return 0;
}