#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int identificador;//cotação por empresa
	int operacao;//1 == venda; 2 == compra;
    int acoes;
    float preco;
    struct No *prox;
} No;

struct No *cabecote = NULL;


void criar_sessao();
void inserir_ofertas();
void comprar_acoes(int comprar, int operacao, int identificador);
void vender_acoes(int vender, int operacao, int identificador);
void listar_ofertas(int listar);
void ordenar_compras(int comprar, int operacao, int identificador);
void ordenar_vendas(int vender, int operacao, int identificador);
void negociar_ofertas(int vender, int comprar, int operacao, int identificador);


criar_sessao();

int main(void){

	int escolher;

	while(1){

		printf("Bem vindo ao OrderBook\n");
		printf("\n1 - Comprar ações\n");
		printf("\n2 - Vender ações\n");
		printf("\n3 - Listar ofertas\n");
		printf("\n4 - Inserir ofertas\n");
		printf("\n5 - Sair\n");
		scanf("%d",&escolher);
		switch(escolher){

			case 1:
			int comprar;
			int identificador = 0;
			int operacao = 0;

			while(comprar != 4){
				printf("\n1 - GOGL34\n");
				printf("\n2 - FBOK34\n");
				printf("\n3 - AMZO34\n");
				printf("\n4 - Voltar\n");
				scanf("%d",&comprar);
				switch(comprar){

					case 1:
					operacao = 1;
					identificador = 1;
					comprar_acoes(comprar, operacao, identificador);
					break;
					case 2:
					operacao = 1;
					identificador = 2;
					comprar_acoes(comprar, operacao, identificador);
					break;
					case 3:
					operacao = 1;
					identificador = 3;
					comprar_acoes(comprar, operacao, identificador);
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
					operacao = 2;
					identificador = 1;
					vender_acoes(vender, operacao, identificador);
					break;
					case 2:
					operacao = 2;
					identificador = 2;
					vender_acoes(vender, operacao, identificador);
					break;
					case 3:
					operacao = 2;
					identificador = 3;
					vender_acoes(vender, operacao, identificador);
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
			inserir_ofertas();
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

void inserir_ofertas()
{
        struct node *temp;
        temp = (struct node *)malloc(sizeof(struct node));

        if(temp == NULL){
			printf("Espaço fora da memória.");
			return;
		}

        int operacao;
        int identificador;

        printf("\nDeseja inserir uma compra ou uma venda?\n1 - venda;\n2 - compra");
        scanf("%d", &temp->operacao );

        while(temp->operacao != 1 && temp->operacao !=2){

			printf("\nOpção inválida.");
			printf("\nDeseja inserir uma compra ou uma venda?\n1 - venda;\n2 - compra");
			scanf("%d", &temp->operacao );

        }

        if(temp->operacao  == 1){

        	printf("De qual cotação deseja comprar?");
        	printf("\n1 - GOGL34");
			printf("\n2 - FBOK34");
			printf("\n3 - AMZO34\n");
			scanf("%d", &temp->identificador);

			while(temp->identificador != 1 && temp->identificador != 2 && temp->identificador != 3){

				printf("\nOpção inválida.");
				printf("De qual cotação deseja comprar?");
				printf("\n1 - GOGL34");
				printf("\n2 - FBOK34");
				printf("\n3 - AMZO34\n");
				scanf("%d", &temp->identificador);

			}

			printf("Qual o preço de compra das ações?\n");
			scanf("%f",&temp->preco);

			while(temp->preco < 0){

				printf("\nValor deve ser positivo.");
				printf("Qual o preço de compra das ações?\n");
				scanf("%f",&temp->preco);

			}

			printf("Quantas ações pelo preço informado?\n");
			scanf("%d",&temp->acoes);

			while(temp->acoes < 0){

				printf("\nValor deve ser positivo.");
				printf("Quantas ações pelo preço informado?\n");
				scanf("%f",&temp->acoes);

			}

        }else{
        	printf("De qual cotação deseja vender?");
			printf("\n1 - GOGL34");
			printf("\n2 - FBOK34");
			printf("\n3 - AMZO34\n");
			scanf("%d", &temp->identificador);

			while(temp->identificador != 1 && temp->identificador != 2 && temp->identificador != 3){

				printf("\nOpção inválida.");
				printf("De qual cotação deseja vender?");
				printf("\n1 - GOGL34");
				printf("\n2 - FBOK34");
				printf("\n3 - AMZO34\n");
				scanf("%d", &temp->identificador);

			}

			printf("Qual o preço de venda das ações?\n");
			scanf("%f",&temp->preco);

			while(temp->preco < 0){

				printf("\nValor deve ser positivo.");
				printf("Qual o preço de venda das ações?\n");
				scanf("%f",&temp->preco);

			}

			printf("Quantas ações pelo preço informado?\n");
			scanf("%d",&temp->acoes);

			while(temp->acoes < 0){

				printf("\nValor deve ser positivo.");
				printf("Quantas ações pelo preço informado?\n");
				scanf("%f",&temp->acoes);

			}

        }

        temp->next = NULL;

        if(cabecote == NULL){
        	cabecote = temp;
        }else{
			temp->next = cabecote;
			cabecote = temp;
        }


}


void comprar_acoes(int comprar, int operacao, int identificador){//insere no começo

		struct node *temp;
		temp = (struct node *)malloc(sizeof(struct node));

		if(temp == NULL){
			printf("Espaço fora da memória.");
			return;
		}

		temp->identificador = identificador;
		temp->operacao = operacao;

		printf("Qual o preço de compra das ações?\n");
		scanf("%d",&temp->preco);
		printf("Quantas ações pelo preço informado?\n");
		scanf("%d",&temp->acoes);

		temp->prox = NULL;

		if(cabecote == NULL){
			cabecote = temp;
		}else{
			temp->prox = cabecote;
			cabecote = temp;
		}

		ordenar_compras(comprar, operacao);


}

void vender_acoes(int vender, int operacao, int identificador){//insere no começo

		struct node *temp;
		temp = (struct node *)malloc(sizeof(struct node));

		if(temp == NULL){
			printf("Espaço fora da memória.");
			return;
		}

		temp->identificador = identificador;
		temp->operacao = operacao;

		printf("Qual o preço de venda das ações?\n");
		scanf("%d",&temp->preco);
		printf("Quantas ações pelo preço informado?\n");
		scanf("%d",&temp->acoes);

		temp->prox = NULL;

		if(cabecote == NULL){
			cabecote = temp;
		}else{
			temp->prox = cabecote;
			cabecote = temp;
		}

		ordenar_vendas(vender, operacao);

}


void ordenar_compras(int comprar, int operacao){
	//O nó atual vai apontar para o cabeçote
	struct node *atual = cabecote, *indice = NULL;
	int temp_preco;
	int temp_acoes;
	int temp_id;

	if(cabecote == NULL) {
		return;
	}else{
		while(atual != NULL) {
			//O índice do nó vai apontar para o nó próximo ao atual
			indice = atual->prox;

			while(indice != NULL) {
				//Se os dados do nó atual forem menores que os dados do nó do índice, troque os dados entre eles
				if((atual->preco < indice->preco) && atual->operacao == 2) {

					temp_preco = indice->preco;
					indice->preco = atual->preco;
					atual->preco = temp_preco;

					temp_acoes = indice->acoes;
					indice->acoes  = atual->acoes;
					atual->acoes = temp_acoes;

					temp_id = indice->identificador;
					indice->identificador =  atual->identificador;
					atual->identificador = temp_id;
				}
				indice = indice->prox;
			}
			atual = atual->prox;
		}
	}
}



void ordenar_vendas(int comprar, int operacao){
	//O nó atual vai apontar para o cabeçote
	struct node *atual = cabecote, *indice = NULL;
	int temp_preco;
	int temp_acoes;
	int temp_id;

	if(cabecote == NULL) {
		return;
	}else{
		while(atual != NULL) {
			//O índice do nó vai apontar para o nó próximo ao atual
			indice = atual->prox;

			while(indice != NULL) {
				//Se os dados do nó atual forem menores que os dados do nó do índice, troque os dados entre eles
				if((atual->preco > indice->preco) && atual->operacao == 2) {

					temp_preco = atual->preco;
					atual->preco = indice->preco;
					indice->preco = temp_preco;

					temp_acoes = atual->acoes;
					atual->acoes = indice->acoes;
					indice->acoes = temp_acoes;

					temp_id = atual->identificador ;
					atual->identificador = indice->identificador;
					indice->identificador = temp_id;
				}
				indice = indice->prox;
			}
			atual = atual->prox;
		}
	}
}

void listar_ofertas(){

	struct No *ptr;

	if(cabecote == NULL){

		printf("Lista vazia.");
		return;

	}else{

		ptr = cabecote;

		while(ptr != NULL){

			if(ptr->prox == NULL){

				//printf("[ %d | NULL ]\n",ptr->conteudo );
				//ptr=ptr->prox;

			}else{

				//printf("[ %d | %p ]--->",ptr->conteudo, ptr->prox);
				//ptr = ptr->prox;

			}
		}
	}
}

