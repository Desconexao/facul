#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

typedef struct{
    char nome[20];
    int idade;
    float peso;
} Pessoa;

int main(){
    Pessoa pessoa1;
    Pessoa *pessoa2 = &pessoa1;
    
    strcpy(pessoa1.nome, "Vinicius");
    pessoa1.idade = 21;

    printf("%s %d", pessoa2->nome, pessoa2->idade);

    return 0;
}
