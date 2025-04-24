#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int conteudo;
    struct Nodo *prox;
} Nodo;

Nodo *criaNodo() {
    Nodo *comeco;

    comeco = (Nodo *)malloc(sizeof(Nodo));
    comeco->prox = NULL;
    return comeco;
}

void insereNodo(int conteudo, Nodo *nodo) {
    Nodo *novoNodo = (Nodo *)malloc(sizeof(Nodo));

    novoNodo->conteudo = conteudo;
    novoNodo->prox = nodo->prox;
    nodo->prox = novoNodo;
}

void imprime(Nodo *ini) {
    Nodo *nodo;

    for (nodo = ini->prox; nodo != NULL; nodo = nodo->prox)
        printf("%d\n", nodo->conteudo);
}

Nodo *busca(int conteudo, Nodo *init) {
    Nodo *nodo;

    nodo = init->prox;
    while (nodo != NULL && nodo->conteudo != conteudo)
        nodo = nodo->prox;
    return nodo;
}

void removeNodo(int conteudo, Nodo *ini) {
    Nodo *atual, *proximo;
    atual = ini;
    proximo = ini->prox;
    while ((proximo != NULL) && (proximo->conteudo != conteudo)) {
        atual = proximo;
        proximo = proximo->prox;
    }
    if (proximo != NULL) {
        atual->prox = proximo->prox;
        free(proximo);
    }
}

void removeNodoPos(Nodo *nodo){
    Nodo *morta;
    morta = nodo->prox;
    nodo->prox = morta->prox;
    free(morta);
}

int main() {
    Nodo *ini, *pos;

    ini = criaNodo();
    insereNodo(10, ini);
    insereNodo(5, ini);
    insereNodo(25, ini);
    removeNodo(25, ini);
    insereNodo(35, ini);
    pos = busca(5, ini);
    removeNodoPos(pos);
    imprime(ini);

    return 0;
}
