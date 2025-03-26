#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void q1(){
    int tamanhoFrase;
    int contApareceu = 0;
    char frase[50];
    char caracter;

    printf("Digite uma frase: ");
    scanf(" %[^\n]s", frase);
    printf("Digite um caracter: ");
    scanf(" %c", &caracter);
    tamanhoFrase = strlen(frase);

    for(int i = 0; i < tamanhoFrase; i++){
        if(frase[i] == caracter)
            contApareceu++;
    }
    printf("Apareceu %d vezes", contApareceu);

}

void q2(){
    char palavra[20];
    int tamanhoPalavra;
    int palindromo = 1;
    
    printf("Digite uma palavra: ");
    scanf(" %s", palavra);
    tamanhoPalavra = strlen(palavra) - 1;
    printf("%c", palavra[tamanhoPalavra]);
    for(int i = 0; i <= tamanhoPalavra; i++){
        if(palavra[i] != palavra[tamanhoPalavra - i]){
            palindromo = !palindromo;
            break;
        }
    }
    if(palindromo)
        printf("a frase '%s' e um palindromo", palavra);
    else
        printf("a frase '%s' nao e um palindromo", palavra);

}

void q3(){
    int populacaoAtual, populacaoAnterior;
    int dias = 0;

    printf("Digite a populacao: ");
    scanf("%d", &populacaoAtual);
    populacaoAnterior = populacaoAtual;

    while(populacaoAtual > populacaoAnterior / 2){
        populacaoAtual -= populacaoAnterior / 15;
        dias++;
    }
    
    printf("Levou %d", dias);

}

void q4(){
    int valores[10];
    int n;

    for(int i = 0; i < 10; i++){
        printf("Digite o valores na posicao %d:", i);
        scanf("%d", &valores[i]);
    }

    printf("Digite a posicao: ");
    scanf("%d", &n);

    for(int i = n; i < 9; i++){
        valores[i] = valores[i + 1];
    }

    for(int i = 0; i < 9; i++){
        printf("valores[%d]: %d \n", i, valores[i]);
    }

}

void q5(){
    int campo[5][5];
    int linha, coluna;
    int minasDescobertas = 0;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            printf("Digite a posicao [%d][%d] do campo: ", i, j);
            scanf("%d", &campo[i][j]);
        }
    }
    for(int i = 1; i <= 10; i++){
        printf("Digite um par [linha][coluna](par %d/10): ", i);
        scanf("%d %d", &linha, &coluna);
        if(campo[linha][coluna] == 1)
            minasDescobertas++;
    }
    printf("O jogador descobriu %d minas!", minasDescobertas);
}

int main(){
    // q1();
    // q2();
    // q3();
    // q4();
    // q5();
}



