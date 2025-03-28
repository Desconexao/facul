#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int buscaPalavra(char frase[], char palavra[]){
    int tamanhoFrase = strlen(frase) - 1;
    int tamanhoPalavra = strlen(palavra) - 1;
    int  j;
    for(int i = 0; i <= tamanhoFrase - tamanhoPalavra; i++){
        for(j = 0; j < tamanhoPalavra; j++){
            if(frase[i+j] != palavra[j])
                break;
        }
        if(j == tamanhoPalavra)
            return 1;
    }
    return 0;
}

void q1(){
    char frase[100];
    char palavra[20];
    printf("Frase: ");
    scanf(" %[^\n]s", frase);
    
    printf("Palavra: ");
    scanf(" %[^\n]s", palavra);

    if(buscaPalavra(frase, palavra))
        printf("A palavra '%s' esta na frase '%s'", palavra, frase);
    else
        printf("A palavra '%s' nao esta na frase '%s'", palavra, frase);

}

typedef struct {
    float altura;
    float peso;
    float imc;
} Caracteristica;

typedef struct {
    Caracteristica caracIndividuais[500];
} Individuos;

Individuos pegaDados(int tamanho){
    Caracteristica caracteristica;
    Individuos individuos;

    for(int i = 0; i < tamanho; i++){
        printf("Digite a altura da pessoa: %d: ", i + 1);
        scanf("%f", &caracteristica.altura);
        printf("Digite o peso da pessoa %d: ", i + 1);
        scanf("%f", &caracteristica.peso);
        caracteristica.imc = caracteristica.peso / pow(caracteristica.altura, 2);
        individuos.caracIndividuais[i] = caracteristica;
    }
    return individuos;
}

void q2(){
    int tamanho = 5;
    int maiorTrinta = 0;
    Individuos individuos = pegaDados(tamanho);

    for(int i = 0; i < tamanho; i++ ){
        printf("Altura da pessoa %d: %.2f\n", i + 1 , individuos.caracIndividuais[i].altura);
        printf("Peso da pessoa %d: %.2f\n", i + 1 , individuos.caracIndividuais[i].peso);
        printf("IMC da pessoa %d: %.2f\n", i + 1 , individuos.caracIndividuais[i].imc);
        if(individuos.caracIndividuais[i].imc > 30)
            maiorTrinta++;
    }
    printf("%d individuos com IMC maior que 30", maiorTrinta);
}

int validaEntrada(int entrada){
    while (entrada < 0){
        printf("Numero invalido, digite um numero maior que 0: (Ultima entrada: %d): ", entrada);
        scanf("%d", &entrada);
    }
    return entrada;  
}

int leValores(int valores[], int tamanho){
    int entrada;
    int somaValores = 0;

    for(int i = 0; i < tamanho; i++){
        printf("Digite um inteiro maior que 0: ");
        scanf("%d", &entrada);
        if(entrada < 0)
            entrada = validaEntrada(entrada);
        valores[i] = entrada;
        somaValores += entrada;
    }
    return somaValores;
}

void q3(){
    int tamanho = 5;
    int valores[tamanho];
    int somaValores = leValores(valores, tamanho);
    int acimaMedia = 0;

    for(int i = 0; i < tamanho; i++){
        printf("Valor na posicao %d: %d\n", i, valores[i]);
        if(valores[i] > (somaValores / tamanho))
            acimaMedia++;
    }

    printf("%d valores estao acima da media", acimaMedia);
}

int validaTiro(int tiro, char charPos){
    while(tiro > 5 || tiro < 0){
        printf("Posicao %c invalida, digite novamente entre [0-5] para %c: ", charPos, charPos);
        scanf("%d", &tiro);
    }
    return tiro;
}

void q4(){
    int matrizTabuleiro[6][6] = {{0,1,1,3,0,1},{0,0,0,3,0,1},{2,2,2,3,0,2}
                                ,{0,0,0,3,0,2},{1,0,0,0,1,2},{1,0,0,0,1,0}};
    int disparoPosX, disparoPosY;
    int pontuacao = 0;
    for(int i = 0; i < 6; i++){
        printf("Digite a posicao X do seu [%d] tiro:  ", i + 1);
        scanf("%d", &disparoPosX);
        if(disparoPosX > 5 || disparoPosX < 0)
            disparoPosX = validaTiro(disparoPosX, 'X');
        printf("Digite a posicao Y do seu [%d] tiro:  ", i + 1);
        scanf("%d", &disparoPosY);
        if(disparoPosY > 5 || disparoPosY < 0)
            disparoPosY = validaTiro(disparoPosY, 'Y');
        pontuacao += matrizTabuleiro[disparoPosX][disparoPosY]; 
    }
    printf("Voce obteve %d pontos!", pontuacao);
}

int main(){
    // q1();
    // q2();
    // q3();
    // q4();
}