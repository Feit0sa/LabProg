#include <stdio.h>

int main() {

    int xa, xb, ya, yb, d, temp1, temp2;
    
    puts("Digite a entrada de xa:");
    scanf("%d", &xa);
    puts("Digite a entrada de ya:");
    scanf("%d", &ya);
    puts("Digite a entrada de xb:");
    scanf("%d", &xb);
    puts("Digite a entrada de yb:");
    scanf("%d", &yb);

    temp1 = (xb-xa) < 0 ? -(xb-xa) : (xb-xa);
    temp2 = (yb-ya) < 0 ? -(yb-ya) : (yb-ya);

    d = temp1 > temp2 ? temp1 : temp2;

    printf("A distância entre o ponto A e o ponto B é de %d\n", d);

    return 0;
}