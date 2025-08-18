#include <stdio.h>
#include <stdlib.h>

typedef struct QUADRANTE {
    int x;
    int y;
    struct QUADRANTE *proximo;
} QUADRANTE;

void lerArquivo(QUADRANTE *quadrante1, QUADRANTE *quadrante2,
                QUADRANTE *quadrante3, QUADRANTE *quadrante4);
void escreverArquivo(QUADRANTE *quadrante1, QUADRANTE *quadrante2,
                     QUADRANTE *quadrante3, QUADRANTE *quadrante4);
QUADRANTE *criaQuadrante();
void adicionaPonto(QUADRANTE *quadrante, QUADRANTE *novoPonto);
void mostrarQuadrante(QUADRANTE *quadrante);

int main() {
    QUADRANTE *quadrante1 = criaQuadrante();
    QUADRANTE *quadrante2 = criaQuadrante();
    QUADRANTE *quadrante3 = criaQuadrante();
    QUADRANTE *quadrante4 = criaQuadrante();
    lerArquivo(quadrante1, quadrante2, quadrante3, quadrante4);
    escreverArquivo(quadrante1, quadrante2, quadrante3, quadrante4);
    return 0;
}

void lerArquivo(QUADRANTE *quadrante1, QUADRANTE *quadrante2,
                QUADRANTE *quadrante3, QUADRANTE *quadrante4) {
    FILE *arquivoEntrada;
    int x;
    int y;

    arquivoEntrada = fopen("prova02-2023entrada.txt", "r");

    while (fscanf(arquivoEntrada, "%d %d", &x, &y) == 2) {
        QUADRANTE *novoPonto = (QUADRANTE *)malloc(sizeof(QUADRANTE));

        novoPonto->x = x;
        novoPonto->y = y;
        novoPonto->proximo = NULL;
        if (x > 0 && y > 0)
            adicionaPonto(quadrante1, novoPonto);
        else if (x < 0 && y > 0)
            adicionaPonto(quadrante2, novoPonto);
        else if (x < 0 && y < 0)
            adicionaPonto(quadrante3, novoPonto);
        else if (x > 0 && y < 0)
            adicionaPonto(quadrante4, novoPonto);
    }
    fclose(arquivoEntrada);
}

void escreverArquivo(QUADRANTE *quadrante1, QUADRANTE *quadrante2,
                     QUADRANTE *quadrante3, QUADRANTE *quadrante4) {
    FILE *arquivoSaida;

    arquivoSaida = fopen("prova02-2023saida.txt", "w");
    QUADRANTE *atual;
    int cont = 1;
    while (cont <= 4) {
        fprintf(arquivoSaida, "Q%d:\n", cont);
        if (cont == 1)
            atual = quadrante1->proximo;
        else if (cont == 2)
            atual = quadrante2->proximo;
        else if (cont == 3)
            atual = quadrante3->proximo;
        else if (cont == 4)
            atual = quadrante4->proximo;
        while (atual != NULL) {
            fprintf(arquivoSaida, "\t%d %d\n", atual->x, atual->y);
            atual = atual->proximo;
        }
        cont++;
    }

    fclose(arquivoSaida);
}

QUADRANTE *criaQuadrante() {
    QUADRANTE *quadrante = (QUADRANTE *)malloc(sizeof(QUADRANTE));
    quadrante->proximo = NULL;
    return quadrante;
}

void adicionaPonto(QUADRANTE *quadrante, QUADRANTE *novoPonto) {
    QUADRANTE *atual = quadrante;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novoPonto;
}

void mostrarQuadrante(QUADRANTE *quadrante) {
    QUADRANTE *atual = quadrante->proximo;
    while (atual != NULL) {
        printf("%d %d\n", atual->x, atual->y);
        atual = atual->proximo;
    }
}
