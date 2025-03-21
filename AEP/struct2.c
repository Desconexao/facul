#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct
{
    char naipes[10];
    char valor[3];

} Carta;

typedef struct
{
    Carta cartas[52];
} Baralho;

Baralho criaBaralho()
{
    Baralho baralho;
    char naipes[4][10] = {"Paus", "Ouros", "Copas", "Espadas"};
    char valor[13][13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    int k = 0;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            strcpy(baralho.cartas[k].naipes, naipes[i]);
            strcpy(baralho.cartas[k].valor, valor[j]);
            k++;
        }
    }

    return baralho;
}

int main(){
    srand(time(NULL));
    Baralho baralho = criaBaralho();
    Carta jogador1[5];
    Carta jogador2[5];
    int cartaRandom1;
    int cartaRandom2;

    for (int i = 0; i < 5; i++){
        cartaRandom1 = rand() % 52;
        cartaRandom2 = rand() % 52;
    
        jogador1[i] = baralho.cartas[cartaRandom1];
        jogador2[i] = baralho.cartas[cartaRandom2];
    }

    printf("Jogador 1\n");
    for (int i = 0; i < 5; i++){
        printf("%s de %s\n", jogador1[i].valor, jogador1[i].naipes);
    }
    
    printf("Jogador 2\n");
    for(int i = 0; i < 5; i++){
        printf("%s de %s\n", jogador2[i].valor, jogador2[i].naipes);
    }
    // for(int i = 0; i < 52; i++){
    //     printf("%s de %s\n", baralho.cartas[i].valor, baralho.cartas[i].naipes);
    // }
    return 0;
}