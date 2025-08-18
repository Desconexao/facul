#include <stdio.h>
#include <stdlib.h>

typedef struct LISTA {
    int prioridade;
    int custo;
    struct LISTA *proximo;
} LISTA;

void lerArquivo(LISTA *cabecaLista);
void escreverArquivo(LISTA *cabecaLista);
LISTA *criarLista();
void inserirNaLista(LISTA *cabecaLista, LISTA *novoElemento);
void mostrarLista(LISTA *cabecaLista);

int main() {
    LISTA *cabecaLista = criarLista();
    lerArquivo(cabecaLista);
    escreverArquivo(cabecaLista);
    return 0;
}

void lerArquivo(LISTA *cabecaLista) {
    FILE *arqEntrada;
    int prioridade;
    int custo;

    arqEntrada = fopen("prova02entrada.txt", "r");

    while (fscanf(arqEntrada, "%d %d", &prioridade, &custo) == 2) {
        LISTA *novoElemento = (LISTA *)malloc(sizeof(LISTA));
        novoElemento->prioridade = prioridade;
        novoElemento->custo = custo;
        novoElemento->proximo = NULL;
        inserirNaLista(cabecaLista, novoElemento);
    }
    fclose(arqEntrada);
}

void escreverArquivo(LISTA *cabecaLista) {
    FILE *arqSaida;
    LISTA *atual = cabecaLista->proximo;

    arqSaida = fopen("prova02saida.txt", "w");

    while (atual != NULL) {
        fprintf(arqSaida, "%d %d\n", atual->prioridade, atual->custo);
        atual = atual->proximo;
    }

    fclose(arqSaida);
}

LISTA *criarLista() {
    LISTA *cabecaLista = (LISTA *)malloc(sizeof(LISTA));
    cabecaLista->proximo = NULL;
    return cabecaLista;
}

void inserirNaLista(LISTA *cabecaLista, LISTA *novoElemento) {
    LISTA *atual = cabecaLista;
    while ((atual->proximo != NULL) &&
           (atual->proximo->prioridade <= novoElemento->prioridade)) {
        if ((atual->proximo->prioridade == novoElemento->prioridade) &&
            ((atual->proximo->custo > novoElemento->custo)))
            break;
        atual = atual->proximo;
    }
    novoElemento->proximo = atual->proximo;
    atual->proximo = novoElemento;
}

void mostrarLista(LISTA *cabecaLista) {
    LISTA *atual = cabecaLista->proximo;

    while (atual != NULL) {
        printf("Tarefa: %d\tCusto: %d\n", atual->prioridade, atual->custo);
        atual = atual->proximo;
    }
}
