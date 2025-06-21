#include <stdio.h>
#define TAM 1000

void numeros_amigos(int n, int amigos[TAM][2], int *q);

int main() {
    int n, i, q;
    int pares_amigos[TAM][2];

    scanf("%d", &n);
    numeros_amigos(n, pares_amigos, &q);
    for (i = 0; i < q; i++)
        printf("(%d,%d)\n", pares_amigos[i][0], pares_amigos[i][1]);
    return 0;
}

void numeros_amigos(int n, int amigos[TAM][2], int *q) {
    *q = 0;
    int firstSum = 0;
    int secondSum = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                firstSum += j;
            }
        }

        for (int j = 1; j < firstSum; j++)
            if (firstSum % j == 0)
                secondSum += j;
        if (i == secondSum && i != firstSum) {
            amigos[*q][0] = i;
            amigos[*q][1] = firstSum;
            (*q)++;
        }
        firstSum = 0;
        secondSum = 0;
    }
}
