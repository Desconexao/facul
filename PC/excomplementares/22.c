#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;

    printf("Digite um numero: ");
    scanf("%d", &x);

    for (int i = 1; i < x; i++) {
        printf("%d: ", i);
        for (int j = 0; j < x; j++) {
            if (j != 0 && i % j == 0) printf("%d ", j);
        }
        printf("\n");
    }

    return 0;
}