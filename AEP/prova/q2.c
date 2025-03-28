#include <stdio.h>
#include <string.h>

#define tam 20

typedef struct{
	int dia, mes, ano;
} Data;

typedef struct{
	int codigo;
	char nome[80];
	char endereco[100];
	Data aniversario;
	float salario;
} Funcionario;

typedef struct{
	Funcionario funcionarios[tam];
	int numeroFuncionarios;
} ListaFuncionarios;

Funcionario leFuncionario();
Data leData();
void mostraAniversariante(ListaFuncionarios listaFuncionarios, Data dataHoje);

int main(){
	ListaFuncionarios listaFuncionarios;
	listaFuncionarios.numeroFuncionarios = 0;
	int opcao = 1;
	
	while(opcao){
		printf("\n1.Incluir\n2.Listar todos\n3.Pesquisar Aniversariante\n0.Sair\nQual operacao deseja realizar? ");
		scanf("%d", &opcao);
		
		switch(opcao){
			case 1:
				if(listaFuncionarios.numeroFuncionarios < tam) 
					listaFuncionarios.funcionarios[listaFuncionarios.numeroFuncionarios++] = leFuncionario();
				else
					printf("Vetor cheio!");
				break;
			case 2:
				if(listaFuncionarios.numeroFuncionarios > 0)
					for(int i = 0; i < listaFuncionarios.numeroFuncionarios; i++)
						printf("Todos Funcionarios:\n\tCodigo: %d\n\tNome: %s\n\t", listaFuncionarios.funcionarios[i].codigo, listaFuncionarios.funcionarios[i].nome);
				else
					printf("Nenhum funcionario cadastrado!");
				break;
			case 3:
				Data datahoje;
				datahoje = leData();
				mostraAniversariante(listaFuncionarios, datahoje);
				//mostraAniversariante(listaFuncionarios, leData()); queria saber o pq disso nao funcionar ;c
				break;
			default:
				printf("Fim...");
		}
	}
}

Funcionario leFuncionario(){
	Funcionario funcionario;
	
	printf("Cadastrando Funcionario... Digite as informacoes a seguir:\n");

	printf("Digite o codigo do funcionario: ");
	scanf("%d", &funcionario.codigo);
	printf("Digite o nome do funcionario: ");
	scanf(" %[^\n]", funcionario.nome);
	printf("Digite o endereco do funcionario: ");
	scanf(" %[^\n]", funcionario.endereco);
	printf("Digite a data de aniversario: (Separe o dia, mes e ano com um espaço. Ex[01 12 2001]): ");
	scanf("%d %d %d", &funcionario.aniversario.dia, &funcionario.aniversario.mes, &funcionario.aniversario.ano);
	printf("Digite o salario do funcionario: ");
	scanf("%f", &funcionario.salario);
	
	return funcionario;
}

Data leData(){
	Data data;
	
	printf("Digite a data de aniversario: (Separe o dia, mes e ano com um espaço. Ex[01 12 2001]): ");
	scanf("%d %d %d", &data.dia, &data.mes, &data.ano);
	
	return data;
}
void mostraAniversariante(ListaFuncionarios listaFuncionarios, Data dataHoje){
	printf("Lista de aniversariantes: \n---------------------------\n");
	for(int i = 0; i < listaFuncionarios.numeroFuncionarios; i++)
		if((listaFuncionarios.funcionarios[i].aniversario.dia == dataHoje.dia) && (listaFuncionarios.funcionarios[i].aniversario.mes == dataHoje.mes))
			printf("%s\n", listaFuncionarios.funcionarios[i].nome);
	printf("---------------------------\n");
	printf("Acima estao todos os aniversariantes encontrados. \nCaso nao tenha nenhum aniversariante nao aparecera nada entre os tracos!");
}
