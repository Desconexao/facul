#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <threads.h>

#define MAX 100

struct endereco {
    char nome[MAX];
    char rua[MAX];
    char cidade[MAX];
    char estado[MAX];
    unsigned long int cep;
} info[MAX];

void cria_lista(void);
void insere(void);
void apaga(void);
void imprime(void);
int menu(void);
int livre(void);
int buscaNome(char nome[MAX]);
void imprimePessoa(void);
void gravarEnderecos(void);
void recuperarEnderecos();
void ler_string(char palavra[MAX], int tamanho);

int main() {
    int escolha;

    cria_lista();
    for (;;) {
        escolha = menu();
        switch (escolha) {
        case 1:
            insere();
            break;
        case 2:
            apaga();
            break;
        case 3:
            imprime();
            break;
        case 4:
            imprimePessoa();
            break;
        case 5:
            gravarEnderecos();
            break;
        case 6:
            recuperarEnderecos();
            break;
        case 7:
            exit(0);
            break;
        }
    }
    return 0;
}

void cria_lista(void) {
    int i;
    for (i = 0; i < MAX; i++)
        info[i].nome[0] = '\0';
}

int menu(void) {
    int c = 0;
    do {
        printf("-- MENU:\n");
        printf("\t 1. Inserir um nome\n");
        printf("\t 2. Excluir um nome\n");
        printf("\t 3. Listar o arquivo\n");
        printf("\t 4. Listar uma pessoa\n");
        printf("\t 5. Gravar Endereços\n");
        printf("\t 4. Recuperar Endereços\n");
        printf("\t 5. Sair\n");
        printf("-- Digite sua escolha: ");
        scanf("%d", &c);
    } while (c <= 0 || c > 5);
    getchar();
    return c;
}

void ler_string(char palavra[MAX], int tamanho) {
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

void insere(void) {
    int posicao;
    char nome[MAX];

    posicao = livre();
    if (posicao == -1) {
        printf("\nEstrutura Cheia!!");
        return;
    }

    printf("-- Registro %d:\n", posicao);
    printf("\t Nome: ");
    ler_string(nome, MAX);
    if (buscaNome(nome) != -1) {
        printf("O nome '%s' já existe.\n", nome);
        return;
    }
    strcpy(info[posicao].nome, nome);
    printf("\t Rua: ");
    ler_string(info[posicao].rua, MAX);
    printf("\t Cidade: ");
    ler_string(info[posicao].cidade, MAX);
    printf("\t Estado: ");
    ler_string(info[posicao].estado, MAX);
    printf("\t CEP: ");
    scanf("%lu", &info[posicao].cep);
}

int livre(void) {
    int i;
    for (i = 0; info[i].nome[0] && i < MAX; i++)
        ;
    if (i == MAX)
        return -1;
    return i;
}

int buscaNome(char *nomeProurado) {
    for (int i = 0; i < MAX; i++) {
        if (strcmp(nomeProurado, info[i].nome) == 0)
            return i;
    }
    return -1;
}

void imprimePessoa() {
    char nome[MAX];
    ler_string(nome, MAX);
    int posicao = buscaNome(nome);

    printf("-- Registro %d:\n", posicao);
    printf("\t Nome: %s", info[posicao].nome);
    printf("\t Rua: %s", info[posicao].rua);
    printf("\t Cidade: %s", info[posicao].cidade);
    printf("\t Estado: %s\n", info[posicao].estado);
    printf("\t CEP: %lu\n", info[posicao].cep);
}

void apaga(void) {
    int posicao;
    char nome[MAX], opcao;

    ler_string(nome, MAX);
    posicao = buscaNome(nome);

    if (posicao == -1) {
        printf("Nome '%s' não econtrado.", nome);
        return;
    }
    printf("Deseja realmente apagar o %s ? [s/n] ", info[posicao].nome);
    scanf("%c", &opcao);
    // printf("Número do Registro: ");
    // scanf("%d", &posicao);
    //
    if (opcao == 's')
        if (posicao >= 0 && posicao < MAX)
            info[posicao].nome[0] = '\0';
}

void imprime(void) {
    int i;

    for (i = 0; i < MAX; i++)
        if (info[i].nome[0] != '\0') {
            printf("-- Registro %d:\n", i);
            printf("\t Nome: %s", info[i].nome);
            printf("\t Rua: %s", info[i].rua);
            printf("\t Cidade: %s", info[i].cidade);
            printf("\t Estado: %s\n", info[i].estado);
            printf("\t CEP: %lu\n", info[i].cep);
        }
}
