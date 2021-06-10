#include <stdio.h>
#include <stdlib.h>

#include "order_book.h"

void persistir_ofertas(No *cabecote){

	FILE *arquivo;

	arquivo = fopen("ofertas.txt", "wb");

	if(arquivo){


	}

}

void finalizar_sessao()
{
     No *temp;
     while(cabecote != NULL){
          temp = cabecote;
          cabecote = cabecote->proximo;
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

		while(temp->operacao != 1 && temp->operacao != 2){

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

		//Se a lista estiver vazia
		if(cabecote == NULL) {

			// Tanto a cabeça quanto a cauda apontarão para temp o que será o novo nó
			cabecote = cauda = temp;

			// o anterior da cabeça apontará para NULL
			cabecote->anterior = NULL;

			// o próximo da cauda apontará para NULL, pois é o último nó da lista
			cauda->proximo = NULL;

		}else {

			// temp será adicionado após a cauda de modo que a próxima cauda aponte para temp
			cauda->proximo = temp;

			// o anterior de temp apontará para a cauda
			temp->anterior = cauda;

			// temp se tornará uma nova cauda
			cauda = temp;

			// Como é o último nó, o próximo nó da cauda apontará para NULL
			cauda->proximo = NULL;
		}

        ordenar_lista();

}


void ordenar_lista(){
	//O nó atual vai apontar para o cabeçote
	struct No *atual = cabecote, *indice = NULL;

	int temp;

	if(cabecote == NULL) {

		return;

	}else{

		for(atual = cabecote; atual->proximo != NULL; atual = atual->proximo) {
			//O índice do nó vai apontar para o nó próximo ao atual
			indice = atual->proximo;

			for(indice = atual->proximo; indice != NULL; indice = indice->proximo) {
				//Se os dados do nó atual forem menores que os dados do nó do índice, troque os dados entre eles
				if(atual->preco > indice->preco) {

					temp = atual->preco;
					atual->preco = indice->preco;
					indice->preco = temp;

					temp = atual->acoes;
					atual->acoes  = indice->acoes;
					indice->acoes = temp;

					temp = atual->identificador;
					atual->identificador =  indice->identificador;
					indice->identificador = temp;

					temp = atual->operacao;
					atual->operacao =  indice->operacao;
					indice->operacao = temp;

				}

			}

		}
	}
}

void listar_ofertas(int identificador) {
    //Nó atual vai apontar para o cabecote
    struct No *atual = cabecote;

    if(cabecote == NULL) {
        printf("Lista vazia \n");
        return;
    }

    		printf("_________________________\n");
    		printf("|       | Ações | Preços |\n");
    while(atual != NULL) {

		if(atual->identificador == identificador && atual->operacao == 1){
			printf("_________________________\n");
			printf("| VENDA | %d | %.2f |\n", atual->acoes, atual->preco);
			atual = atual->proximo;
		}

		if(atual->identificador == identificador && atual->operacao == 2){
			printf("_________________________\n");
			printf("|COMPRA | %d | %.2f |\n", atual->acoes, atual->preco);
			atual = atual->proximo;
		}
	}

}

