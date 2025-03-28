#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscaCaracter(char frase[], char caracter);

int main(){
	char frase[500], caracter;
	
	printf("Digite a frase: ");
	scanf(" %[^\n]", frase);
	printf("Digite um caracter: ");
    scanf(" %c", &caracter);
    
    if(buscaCaracter(frase, caracter))
		printf("O caracter '%c' aparece %d vez(es) na frase '%s'.", caracter, buscaCaracter(frase, caracter), frase);
	else
		printf("O caracter '%c' nao apareceu na frase '%s'.", caracter, frase);
}

int buscaCaracter(char frase[], char caracter){
	int contCaracter = 0;
	for(int i = 0; i < (strlen(frase)); i++){
		if(frase[i] == caracter) contCaracter++;
	}
	return contCaracter;
}
