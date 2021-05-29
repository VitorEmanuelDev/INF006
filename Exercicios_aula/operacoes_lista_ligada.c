#include<stdlib.h>
#include <stdio.h>

void criarLista();
void mostrarLista();
void inserirNo();
void deletarNo();


struct No{

	int conteudo;
	struct No *prox;

};
struct No *cabecote = NULL;

int main()
{
	int escolha;

	while(1){

		printf("\n1 - Criar lista encadeada\n");
		printf("\n2 - Visualizar lista\n");
		printf("\n3 - Inserir nó na lista\n");
		printf("\n4 - Deletar nó da lista\n");
		printf("\n5 - Sair\n");
		scanf("%d",&escolha);
		switch(escolha){

			case 1:
				criarLista();
				break;
			case 2:
				mostrarLista();
				break;
			case 3:
				inserirNo();
				break;
			case 4:
				deletarNo();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Escolha Inválida.");
				break;
			}
	}
	return 0;
}

void criarLista(){

	struct No *temp, *ptr;

	temp = (struct No *)malloc(sizeof(struct No));

	if(temp == NULL){

		printf("Espaço de memória não alocado\n");
		exit(0);

	}

	printf("Informe o valor do nó:\n");
	scanf("%d", &temp->conteudo);

	temp->prox = NULL;// primeiro e último da lista. por isso o endereço de ligação fica NULL

	if(cabecote == NULL){

		cabecote = temp;

	}else{

		ptr = cabecote;

		while(ptr->prox != NULL){

			ptr = ptr->prox;

		}

		ptr->prox = temp;

	}
}

void mostrarLista(){

	struct No *ptr;

	if(cabecote == NULL){

		printf("Lista vazia.");
		return;

	}else{

		ptr = cabecote;

		while(ptr != NULL){

			if(ptr->prox == NULL){

				printf("[ %d | NULL ]\n",ptr->conteudo );
				ptr=ptr->prox;

			}else{

				printf("[ %d | %p ]--->",ptr->conteudo, ptr->prox);
				ptr = ptr->prox;

			}
		}
	}
}


void inserirNo(){

	struct No *ptr,*temp;
	int i, pos;

	temp = (struct No *)malloc(sizeof(struct No));

	if(temp == NULL){

		printf("Espaço de memória não alocado\n");
		return;

	}

	printf("Informe a posição em que o novo nó será inserido: \n");
	scanf("%d",&pos);

	printf("Informe o valor do nó:\n");
	scanf("%d",&temp->conteudo) ;

	temp->prox = NULL;//o inserido se torna o último da lista

	if(pos == 0){

		temp->prox = cabecote;
		cabecote = temp;

	}else{

		for(i = 0, ptr = cabecote; i < pos - 1; i++){

			ptr = ptr->prox;

			if(ptr == NULL){

				printf("Posição não encontrada:\n");
				return;

			}
		}

		temp->prox = ptr->prox;
		ptr->prox = temp;

	}
}

void deletarNo(){

	struct No *temp,*ptr;
	int i,pos;

	if(cabecote == NULL){

		printf("Lista vazia.");
		exit(0);

	}else{

		printf("Informe a posiçãodo nó será deletado: \n");
		scanf("%d",&pos);

		if(pos == 0){

			ptr = cabecote;
			cabecote = cabecote->prox;
			free(ptr);

		}else{

			ptr = cabecote;

			for(i=0; i < pos; i++){

				temp = ptr;
				ptr = ptr->prox;

				if(ptr == NULL){

					printf("Posicao não encontrada");
					return;

				}
			}

			temp->prox = ptr->prox ;
			free(ptr);

		}
	}
}

