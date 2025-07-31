#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO : Ordem alfa alfabetica

struct end {
    char nome[100];
    char rua[100];
    char cidade[100];
    char estado[100];
    unsigned long int cep;
    struct end *prox;
};

struct end *cria(void);
void insere(struct end *p);
void imprime(struct end *ini);
void remova(struct end *ini);

int menu(void);
void ler_string(char palavra[100], int tamanho);

int main() {
    int escolha;
    struct end *info, *fim;
    int onde;

    info = cria();
    for (;;) {
        escolha = menu();
        switch (escolha) {
        case 1:
            printf("\tDigite 1. início ou 2. fim: ");
            scanf("%d", &onde);
            getchar();
            if (onde == 1)
                insere(info);
            else if (onde == 2) {
                // acha o fim
                for (fim = info; fim->prox != NULL; fim = fim->prox)
                    ;
                insere(fim);
            }
            break;
        case 2:
            remova(info);
            break;
        case 3:
            imprime(info);
            break;
        case 4:
            exit(0);
            break;
        }
    }
    return 0;
}

struct end *cria(void) {
    struct end *start;

    start = (struct end *)malloc(sizeof(struct end));
    start->prox = NULL;
    return start;
}

void insere(struct end *p) {
    struct end *nova;

    nova = (struct end *)malloc(sizeof(struct end));

    printf("\t Nome: ");
    ler_string(nova->nome, 100);
    printf("\t Rua: ");
    ler_string(nova->rua, 100);
    printf("\t Cidade: ");
    ler_string(nova->cidade, 100);
    printf("\t Estado: ");
    ler_string(nova->estado, 100);
    printf("\t CEP: ");
    scanf("%lu", &nova->cep);

    nova->prox = p->prox;
    p->prox = nova;
}

void remova(struct end *ini) {
    struct end *p, *q;
    char nome_excluido[100];

    printf("\tNome: ");
    ler_string(nome_excluido, 100);

    p = ini;
    q = ini->prox;
    while ((q != NULL) && (strcmp(nome_excluido, q->nome) != 0)) {
        p = q;
        q = q->prox;
    }
    if (q != NULL) {
        p->prox = q->prox;
        free(q);
        printf("\tNome excluído!\n");
    } else {
        printf("\tNome não encontrado!\n");
    }
}

void imprime(struct end *ini) {
    struct end *p;

    for (p = ini->prox; p != NULL; p = p->prox) {
        printf("\t Nome: %s\n", p->nome);
        printf("\t Rua: %s\n", p->rua);
        printf("\t Cidade: %s\n", p->cidade);
        printf("\t Estado: %s\n", p->estado);
        printf("\t CEP: %lu\n", p->cep);
    }
}

int menu(void) {
    int c = 0;
    do {
        printf("-- MENU:\n");
        printf("\t 1. Inserir um nome\n");
        printf("\t 2. Excluir um nome\n");
        printf("\t 3. Imprimir lista\n");
        printf("\t 4. Sair\n");
        printf("-- Digite sua escolha: ");
        scanf("%d", &c);
    } while (c <= 0 || c > 4);
    getchar();
    return c;
}

void ler_string(char palavra[100], int tamanho) {
    int i = 0;
    char c;

    c = getchar();
    while ((c != '\n') && (i < tamanho)) {
        palavra[i++] = c;
        c = getchar();
    }
    palavra[i] = '\0';

    if (c != '\n') {
        c = getchar();
        while ((c != '\n') && (c != EOF)) {
            c = getchar();
        }
    }
}
