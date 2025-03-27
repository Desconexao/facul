#include <stdio.h>
#include <string.h>

#define tam 20 //tamanho da lista de alunos

typedef struct {
    int codigo;
    char nome[80];
    float nota1, nota2;
} aluno;

typedef struct {
	aluno alunos[tam];//vetor de alunos
	int numeroAlunos;//numero de alunos armazanados
} listaAlunos;
//protótipo das funções
aluno leAluno();
float le_nota(char msg[20]);
void buscaAluno(listaAlunos alunos);
void buscaMaiorMedia(listaAlunos alunos);


//-----------------------------------------
int main(){
	listaAlunos alunos;
	alunos.numeroAlunos = 0;
	int op=1;
	while (op){
	  // mostra menu de opcoes	
	  printf ("\n1.Incluir\n2.Listas Todos\n3.Pesquisar por nome\n4.Pesquisar maior media\n0. Sair\nQual operação deseja realizar? ");
	  scanf("%d",&op);
	  switch (op){
		case 1:
			if (alunos.numeroAlunos < tam )
				alunos.alunos[alunos.numeroAlunos++] = leAluno(); 
			else
				printf("Vetor cheio\n");  
			break;  
		case 2:
			if (alunos.numeroAlunos > 0 )
				for(int i=0; i<alunos.numeroAlunos;i++){
					printf("Cod: %d\tNome: %s\tMedia:%.2f\n", alunos.alunos[i].codigo, alunos.alunos[i].nome, (alunos.alunos[i].nota1+alunos.alunos[i].nota2) / 2);
				} 
			else
				printf("Nenhum registro alunos ser mostrado\n");
			break;
		case 3:
			buscaAluno(alunos);
			break;
		case 4:
			buscaMaiorMedia(alunos);
			break;
		default:
			printf("Fim...");
	  }
	}   
}

//---Funcao le_nota
//le um valor float, validando para nota valida 
//entrada: string contendo alunos mensagem alunos ser impressa antes da leitura
//retorno: float
float le_nota(char msg[20]){
	float n;
	
	printf("%s", msg);
	scanf("%f", &n);
	while (n<0 || n>10){
		printf("Nota Invalida, digite novamente: ");
		scanf("%f",&n);
	}
	return n;
}

//---Funcao le_aluno
//le os dados eferentes alunos um aluno
//retorna estrutura Aluno com dados lidos
aluno leAluno(){
	aluno alunos;
	  printf("Digite Codigo ");	
	  scanf("%d",&alunos.codigo);
	  printf("Digite Nome ");	
	  scanf(" %[^\n]s",alunos.nome);
	  alunos.nota1 = le_nota("Digite Nota 1 ");
	  alunos.nota2 = le_nota("Digite Nota 2 ");
    return alunos;
}

void buscaAluno(listaAlunos alunos){
	char nomeAluno[80];
	printf("Digite o nome do aluno que deseja buscar: ");
	scanf("%s", nomeAluno);
	printf("Buscando o aluno: %s...\n", nomeAluno);
	for(int i = 0; i < alunos.numeroAlunos; i++){
		printf("%d", !strcmp(nomeAluno, alunos.alunos[i].nome));
		if(!strcmp(nomeAluno, alunos.alunos[i].nome)){
			printf("Aluno %s encontado!\n", nomeAluno);
			printf("Dados:\n\tCodigo: %d \n\tNome: %s\n\tNota 1 e Nota 2: %.2f, %.2f", alunos.alunos[i].codigo, alunos.alunos[i].nome, alunos.alunos[i].nota1, alunos.alunos[i].nota2);
			return;
		}
	}
	printf("Aluno %s nao encontrado...", nomeAluno);
}

void buscaMaiorMedia(listaAlunos alunos){
	float mediaAluno, maiorMedia = -1;
	int posAluno;
	if(alunos.numeroAlunos == 0){
		printf("Nao ha alunos cadastrados.");
		return;
	}
	for(int i = 0; i < alunos.numeroAlunos; i++){
		mediaAluno = (alunos.alunos[i].nota1 + alunos.alunos[i].nota2) / 2;
		if(mediaAluno > maiorMedia){
			maiorMedia = mediaAluno;
			posAluno = i;
		}
	}
	printf("O aluno '%s' possui a maior media: %.2f", alunos.alunos[posAluno].nome, mediaAluno);
}
