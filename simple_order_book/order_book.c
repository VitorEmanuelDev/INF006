#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int identificador;
	int operacao;//1 == venda; 2 == compra;
    int acoes;
    float preco;
    struct No *prox;
} No;

struct No *cabecote = NULL;


void criar_sessao();
int comprar_acoes(int comprar);
int vender_acoes(int vender);
int listar_ofertas(int listar);

int main(void){

	int escolher;

	while(1){

		printf("Bem vindo ao OrderBook\n");
		printf("\n1 - Comprar ações\n");
		printf("\n2 - Vender ações\n");
		printf("\n3 - Listar ofertas\n");
		printf("\n4 - Sair\n");
		scanf("%d",&escolher);
		switch(escolher){

			case 1:
			int comprar;
			while(comprar != 4){
				printf("\n1 - GOGL34\n");
				printf("\n2 - FBOK34\n");
				printf("\n3 - AMZO34\n");
				printf("\n4 - Voltar\n");
				scanf("%d",&comprar);
				switch(comprar){

					case 1:
					comprar_acoes(comprar);
					break;
					case 2:
					comprar_acoes(comprar);
					break;
					case 3:
					comprar_acoes(comprar);
					break;
					case 4:
					break;
					default:
					printf("Escolha Inválida.");
					break;
				}
			}
			break;
			case 2:
			int vender;
			while(vender != 4){
				printf("\n1 - GOGL34\n");
				printf("\n2 - FBOK34\n");
				printf("\n3 - AMZO34\n");
				printf("\n4 - Voltar\n");
				scanf("%d",&vender);
				switch(vender){

					case 1:
					vender_acoes(vender);
					break;
					case 2:
					vender_acoes(vender);
					break;
					case 3:
					vender_acoes(vender);
					break;
					case 4:
					break;
					default:
					printf("Escolha Inválida.");
					break;
				}
			}
			break;
			case 3:
			int listar;
			while(listar != 4){
				printf("\n1 - GOGL34\n");
				printf("\n2 - FBOK34\n");
				printf("\n3 - AMZO34\n");
				printf("\n4 - Voltar\n");
				scanf("%d",&listar);
				switch(listar){

					case 1:
					listar_ofertas(listar);
					break;
					case 2:
					listar_ofertas(listar);
					break;
					case 3:
					listar_ofertas(listar);
					break;
					case 4:
					break;
					default:
					printf("Escolha Inválida.");
					break;
				}
			}
			break;
			case 4:
			exit(0);
			break;
			default:
			printf("Escolha Inválida.");
			break;
		}
	}
	return 0;

}


void criar_sessao(){

	struct No *temp, *ptr;

	temp = (struct No *)malloc(sizeof(struct No));

	if(temp == NULL){

		printf("Espaço de memória não alocado\n");
		exit(0);

	}

	temp->identificador = 0;
	temp->acoes = 0;
	temp->preco = 0;
	temp->operacao = 0;

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


void listar_ofertas(){

	/*struct No *ptr;

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
	}*/
}

