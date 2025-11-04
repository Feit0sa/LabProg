#include <stdio.h>

int main() {

    char sinal_bin[9];
    unsigned char sinal, id, status, leitura;
    
    puts("Digite o sinal (8 bits, ex.: 10101010)");
    scanf("%8s", &sinal_bin);
    puts("Digite o ID do equipamento (1 a 4)");
    scanf("%hhu", &id);

    for (int i = 0; i < 8; i++) {
        sinal = sinal << 1;
        if (sinal_bin[i] == '1') {
            sinal = sinal | 1;
        }
    }

    status = (sinal >> (id - 1) & 1);
    leitura = (sinal >> (id + 3) & 1);

    printf("Equipamento %hhu - %s - %s\n", id, status ? "Ligado" : "Desligado", leitura ? "Alto" : "Baixo");

    return 0;
}