#include <stdio.h>
#include <stdlib.h>

typedef struct No {
	int identificador;//cotação por empresa
	int operacao;//1 == venda; 2 == compra;
    int acoes;
    float preco;
    struct No *proximo;
    struct No *anterior;
} No;

struct No *cabecote, *cauda = NULL;

void finalizar_sessao(No *cabecote, No *cauda);
void inserir_ofertas();
void listar_compras(int identificador);
void listar_vendas(int identificador);
void ordenar_lista();



int main(void){

	int escolher;
	int identificador;

	while(1){

		printf("Bem vindo ao OrderBook\n");
		printf("\n1 - Listar ofertas\n");
		printf("\n2 - Inserir ofertas\n");
		printf("\n3 - Sair\n");
		scanf("%d",&escolher);
		switch(escolher){

			case 1:

			while(identificador != 4){
				printf("Quais açoões deseja listar?\n");
				printf("\n1 - GOGL34\n");
				printf("\n2 - FBOK34\n");
				printf("\n3 - AMZO34\n");
				printf("\n4 - Voltar\n");
				scanf("%d",&identificador);
				switch(identificador){

					case 1:
					listar_compras(identificador);
					break;
					case 2:
					listar_compras(identificador);
					break;
					case 3:
					listar_compras(identificador);
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
			inserir_ofertas();
			break;
			case 3:
			finalizar_sessao(cabecote, cauda);
			exit(0);
			break;
			default:
			printf("Escolha Inválida.");
			break;
		}
	}
	return 0;

}


void finalizar_sessao(No *cabecote, No *cauda)
{
     No *temp;
     while(cabecote != NULL){
          temp = cabecote;
          cabecote = cabecote->proximo;
          free(temp);
          temp = cauda;
		  cauda = cauda->anterior;
		  free(temp);
     }
}

void inserir_ofertas()
{
        struct No *temp;
        temp = (struct No *)malloc(sizeof(struct No));

        if(temp == NULL){
			printf("Espaço fora da memória.");
			return;
		}

        printf("\nDeseja inserir uma compra ou uma venda?\n1 - venda\n2 - compra");
        scanf("%d", &temp->operacao);

        while(temp->operacao != 1 && temp->operacao !=2){

			printf("\nOpção inválida.");
			printf("\nDeseja inserir uma compra ou uma venda?\n1 - venda\n2 - compra");
			scanf("%d", &temp->operacao );

        }

        if(temp->operacao  == 1){

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
				scanf("%d",&temp->acoes);

			}

        }else{
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
				scanf("%d",&temp->acoes);

			}

        }

        temp->proximo = NULL;

        if(cabecote == NULL){
        	cabecote = temp;
        }else{
			temp->proximo = cabecote;
			cabecote = temp;
        }

        ordenar_lista();

}


void ordenar_lista(){
	//O nó atual vai apontar para o cabeçote
	struct No *atual = cabecote, *indice = NULL;
	int temp_preco;
	int temp_acoes;
	int temp_id;
	int temp_op;

	if(cabecote == NULL) {
		return;
	}else{
		while(atual != NULL) {
			//O índice do nó vai apontar para o nó próximo ao atual
			indice = atual->proximo;

			while(indice != NULL) {
				//Se os dados do nó atual forem menores que os dados do nó do índice, troque os dados entre eles
				if(atual->preco > indice->preco) {

					temp_preco = atual->preco;
					atual->preco = indice->preco;
					indice->preco = temp_preco;

					temp_acoes = atual->acoes;
					atual->acoes  = indice->acoes;
					indice->acoes = temp_acoes;

					temp_id = atual->identificador;
					atual->identificador =  indice->identificador;
					indice->identificador = temp_id;

					temp_op = atual->operacao;
					atual->operacao =  indice->operacao;
					indice->operacao = temp_op;

				}

				indice = indice->proximo;

			}

			atual = atual->proximo;

		}
	}
}

void listar_compras(int identificador) {
    //Nó atual vai apontar para o cabecote
    struct No *atual = cabecote;

    if(cabecote == NULL) {
        printf("Lista vazia \n");
        return;
    }

    printf("___________\n");
    printf("| COMPRA  |\n");
    while(atual != NULL) {

     	if(atual->identificador == identificador && atual->operacao == 1){
 			printf("___________\n");
 			printf("|%d |%.2f |\n", atual->acoes, atual->preco);
 			atual = atual->proximo;
     	}
     }

    listar_vendas(identificador);

}

void listar_vendas(int identificador) {
    //Nó atual vai apontar para o cabecote
    struct No *temp = cauda;

    printf("___________\n");
    printf("|  VENDA  |\n");
    while(temp != NULL) {

    	if(temp->identificador == identificador && temp->operacao == 2){

    		printf("|___________|\n");
			printf("|%d|%.2f|\n", temp->acoes, temp->preco);
			temp = temp->anterior;
    	}
    }

    main();

}


