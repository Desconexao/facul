#include <stdio.h>

void initVet(int *V, int qtd, int valor) {
    int i;
    for (i = 0; i < qtd; i++)
        V[i] = valor;
}

void q4() {
    int i;
    float Vet[10];

    initVet(Vet, 10, 7);
    for (i = 0; i < 10; i++)
        printf("%f ", Vet[i]);
}

int max(int n, int v[]) {
    if (n == 1)
        return v[0];
    else {
        int x;
        printf("%d ", x);
        x = max(n - 1, v);
        printf("%d ", x);
        printf("%d", (x > v[n - 1]));
        if (x > v[n - 1])
            return x;
        else
            return v[n - 1];
    }
}
// [4] 4 > v[n - 1] false, [4, 3] 4 > v[n - 1] true, [4, 3, 5] 4 > v[n - 1]
// false, [4, 3, 5, 7] 5 > v[n - 1] false, [4, 3 ,5 , 7, 6] 7 > v[n - 1] true,
// max(5, x) == 7
void q5() {
    int x[5] = {4, 3, 5, 7, 6};

    printf("%d", max(5, x));
}

int main() { q5(); }
