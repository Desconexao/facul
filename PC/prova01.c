// Vinícius Lameirão de Lima

#include <stdio.h>

int fun(int i, int j);

int main() {
    int pares;
    int i, j;

    scanf("%d", &pares);
    while (pares > 0) {
        scanf("%d%d", &i, &j);
        printf("%d\n", fun(i, j));
        pares--;
    }
    return 0;
}

int fun(int i, int j) {
    int valor, ciclos, maiorCiclo = 1;
    for (i; i <= j; i++) {
        // printf("Inicio: %d\n", i);
        valor = i;
        ciclos = 1;
        while (valor != 1) {
            if (valor % 2 == 0) {
                // printf("par %d\n", valor);
                valor = valor / 2;
            } else if (valor % 2 == 1) {
                // printf("impar %d\n", valor);
                valor = valor * 3 + 1;
            }
            ciclos++;
            if (maiorCiclo < ciclos)
                maiorCiclo = ciclos;
            // printf("valor:%d\n", valor);
        }
    }
    return maiorCiclo;
}
// 10 5 16 8 4 2 1;
/*
int fun(int i, int j){
    //int numeroAtual = j;
    int maiorValor = j;
    int maiorValorEncontrado = j;
    int valorAtual = j;
    for(int inicio = i; inicio <= j; inicio++){
        for(int numeroAtual = i; numeroAtual <=  j; numeroAtual++){
            printf("numero: %d\n", numeroAtual);
            if(valorAtual % 2 == 0){
                valorAtual = valorAtual / 2;
                //printf("par\n");
            }
            else{
                valorAtual = (valorAtual * 3) + 1;
                //printf("impar\n");
                }
            if(maiorValor < valorAtual)
                maiorValor = valorAtual;
            printf("%d - ", valorAtual);
        }
        if(maiorValorEncontrado < maiorValor)
            maiorValorEncontrado = maiorValor;

    }
    return maiorValorEncontrado;
    //printf("teste");
}
*/
