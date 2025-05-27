#include <stdio.h>
#include <stdlib.h>

typedef struct No {
  int conteudo;
  struct No *prox;
} No;

No *criaNo() {
  No *comeco = (No *)malloc(sizeof(No));
  if (comeco == NULL) {
    printf("Erro: falha na alocação de memória\n");
    exit(1);
  }
  comeco->conteudo = 0;
  comeco->prox = NULL;
  return comeco;
}

void insereNo(int conteudo, No *no) {
  No *novoNo = (No *)malloc(sizeof(No));
  if (novoNo == NULL) {
    printf("Erro: falha na alocação de memória\n");
    exit(1);
  }
  novoNo->conteudo = conteudo;
  novoNo->prox = no->prox;
  no->prox = novoNo;
}

void imprime(No *ini) {
  No *no;
  for (no = ini->prox; no != NULL; no = no->prox) {
    printf("%d\n", no->conteudo);
  }
}

No *busca(int conteudo, No *init) {
  No *no = init->prox;
  while (no != NULL && no->conteudo != conteudo) {
    no = no->prox;
  }
  return no;
}

void removeNo(int conteudo, No *ini) {
  No *atual = ini;
  No *proximo = ini->prox;
  while (proximo != NULL && proximo->conteudo != conteudo) {
    atual = proximo;
    proximo = proximo->prox;
  }
  if (proximo != NULL) {
    atual->prox = proximo->prox;
    free(proximo);
  }
}

void removeNoPos(No *ini, No *no) {
  if (ini == NULL || no == NULL)
    return;
  No *atual = ini;
  while (atual != NULL && atual->prox != no)
    atual = atual->prox;
  if (atual == NULL || atual->prox == NULL)
    return;
  atual->prox = no->prox;
  free(no);
}

void liberaLista(No *ini) {
  No *atual = ini;
  while (atual != NULL) {
    No *temp = atual;
    atual = atual->prox;
    free(temp);
  }
}

int main() {
  No *ini = criaNo();
  // No *pos;

  insereNo(10, ini);
  insereNo(5, ini);
  insereNo(25, ini);
  removeNo(25, ini);
  insereNo(35, ini);
  busca(5, ini);
  removeNoPos(ini, busca(5, ini));
  imprime(ini);

  liberaLista(ini);
  return 0;
}
