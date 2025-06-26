#include <stdio.h>

enum numeros {
    um,
    dois,
    tres,
    quatro,
    cinco,
    seis = 6,
    sete,
    oito,
    nove,
    dez,
};

void q3() { printf("%d %d %d %d", um, dez, (cinco + quatro), (sete + um)); }

typedef struct {
    char c;
    int i;
    float f;
    double d;
} sdata;

struct {
    sdata x;
    char c;
    int i;
    float f;
    double d;
} tdata;

void q4() {
    tdata.c = 'a';
    tdata.x.c = 'b';
    tdata.i = 1234;
    tdata.x.i = 4321;
    tdata.f = 12.34;
    tdata.x.f = 43.21;
    tdata.d = 1111.1111;
    tdata.x.d = 2222.2222;
    printf("%c %d %.2f %.4lf", tdata.c, tdata.i, tdata.f, tdata.d);
    printf("%c %d %.2f %.4lf", tdata.x.c, tdata.x.i, tdata.x.f, tdata.x.d);
}

typedef struct {
    int x, y;
} pares;

void leitura(int *qtde, pares vet[100]);

void q5() {
    pares valores[100];
    int q, i;

    leitura(&q, valores);

    printf("Foram lidos %d pares de valores.\n", q);

    for (int i = 0; i < q; i++)
        printf("%d %d\n", valores[i].x, valores[i].y);
}

void leitura(int *qtde, pares vet[100]) {
    *qtde = 0;
    while (scanf("%d %d", &vet[*qtde].x, &vet[*qtde].y) == 2)
        (*qtde)++;
}

int main() {
    q5();
    return 0;
}
