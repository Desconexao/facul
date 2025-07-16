#include <stdio.h>

void q4() {
    FILE *arquivo;
    int i, q;

    arquivo = fopen("questao01in.txt", "w");

    q = 0;
    while (fscanf(arquivo, "%d", &i) == 1) {
        q++;
        printf("%d", i);
    }

    printf("\n Total: %d\n", q);
    fclose(arquivo);
}

int main() {
    q4();
    return 0;
}
