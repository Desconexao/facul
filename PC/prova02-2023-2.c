#include <stdio.h>
#include <stdlib.h>

typedef struct LETRAS {
    char caractere;
    struct LETRAS *proximo;
} LETRAS;

void lerArquivo(LETRAS *cabecaVogais, LETRAS *cabecaConsoantes);
void escreverArquivo(LETRAS *cabecaVogais, LETRAS *cabecaConsoantes);
LETRAS *criaLista();
void adicionaLetra(LETRAS *cabecaLista, LETRAS *novaLetra);
void mostrarLista(LETRAS *cabecaLista);

int main() {
    LETRAS *cabecaVogais = criaLista();
    LETRAS *cabecaConsoantes = criaLista();
    lerArquivo(cabecaVogais, cabecaConsoantes);
    escreverArquivo(cabecaVogais, cabecaConsoantes);
    return 0;
}

void lerArquivo(LETRAS *cabecaVogais, LETRAS *cabecaConsoantes) {
    FILE *arquivoEntrada;
    char caractere;

    arquivoEntrada = fopen("prova02-2023-2entrada.txt", "r");
    while (fscanf(arquivoEntrada, " %c", &caractere) == 1) {
        LETRAS *novaLetra = (LETRAS *)malloc(sizeof(LETRAS));
        novaLetra->caractere = caractere;
        novaLetra->proximo = NULL;

        if (caractere == 'A' || caractere == 'E' || caractere == 'I' ||
            caractere == 'O' || caractere == 'U')
            adicionaLetra(cabecaVogais, novaLetra);
        else
            adicionaLetra(cabecaConsoantes, novaLetra);
    }
}

void escreverArquivo(LETRAS *cabecaVogais, LETRAS *cabecaConsoantes) {
    FILE *arquivoSaida;

    arquivoSaida = fopen("prova02-2023-2saida.txt", "w");

    LETRAS *atual;
    for (int i = 1; i <= 2; i++) {
        if (i == 1) {
            atual = cabecaVogais->proximo;
            fprintf(arquivoSaida, "Vogais: \n");
        } else {
            atual = cabecaConsoantes->proximo;
            fprintf(arquivoSaida, "Consoantes:\n");
        }
        while (atual != NULL) {
            fprintf(arquivoSaida, "\t%c\n", atual->caractere);
            atual = atual->proximo;
        }
    }
}

LETRAS *criaLista() {
    LETRAS *cabecaLetras = (LETRAS *)malloc(sizeof(LETRAS));
    cabecaLetras->proximo = NULL;
    return cabecaLetras;
}

void adicionaLetra(LETRAS *cabecaLista, LETRAS *novaLetra) {
    LETRAS *atual = cabecaLista;
    while (atual->proximo != NULL &&
           atual->proximo->caractere < novaLetra->caractere) {
        atual = atual->proximo;
    }
    novaLetra->proximo = atual->proximo;
    atual->proximo = novaLetra;
}

void mostrarLista(LETRAS *cabecaLista) {
    LETRAS *atual = cabecaLista->proximo;

    while (atual != NULL) {
        printf("%c\n", atual->caractere);
        atual = atual->proximo;
    }
}
