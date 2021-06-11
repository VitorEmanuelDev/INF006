#include <stdio.h>
#include <stdlib.h>

#define VENDA 1
#define COMPRA 2

#define GOGL34 1
#define FBOK34 2
#define AMZO34 3

#include "order_book.h"

struct No *cabecote, *cauda = NULL;


/*void persistir_ofertas(No *cabecote){

	FILE *arquivo;

	arquivo = fopen("ofertas.txt", "wb");

	if(arquivo){


	}

}*/

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


		printf("\nDeseja inserir uma compra ou uma venda?\n1 - Venda\n2 - Compra");
		scanf("%d", &temp->operacao);

		while(temp->operacao != COMPRA && temp->operacao != VENDA){

			printf("\nOpção inválida.");
			printf("\nDeseja inserir uma compra ou uma venda?\n1 - Venda\n2 - Compra");
			scanf("%d", &temp->operacao );

		}

		if(temp->operacao  == VENDA){

			printf("De qual cotação deseja vender?");
			printf("\n1 - GOGL34");
			printf("\n2 - FBOK34");
			printf("\n3 - AMZO34\n");
			scanf("%d", &temp->identificador);

			while(temp->identificador != GOGL34 && temp->identificador != FBOK34 && temp->identificador != AMZO34){

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

			while(temp->identificador != GOGL34 && temp->identificador != FBOK34 && temp->identificador != AMZO34){

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

		if(cabecote == NULL) {
			cabecote = temp;
			cauda = temp;
		}else {
			cauda->proximo = temp;
			cauda = temp;
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

		while(atual != NULL) {

			indice = atual->proximo;

			while(indice != NULL) {

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
				indice = indice->proximo;
			}
			atual = atual->proximo;
		}
	}
}

void listar_ofertas() {
    //Nó atual vai apontar para o cabecote
    struct No *atual = cabecote;

    if(cabecote == NULL) {
		printf("Lista vazia \n");
		return;
	}

    		printf("**************************** BOOK DE PRECOS ***********************************");
    while(atual != NULL) {

		if(atual->identificador == GOGL34 && atual->operacao == VENDA){
			printf("                                        _____________________________________\n");
			printf("                                        | GOGL34 | VENDA | %d | %.2f |\n", atual->acoes, atual->preco);
			atual = atual->proximo;
		}

		if(atual->identificador == GOGL34 && atual->operacao == COMPRA){
			printf("_____________________________________\n");
			printf("| GOGL34 | COMPRA | %d | %.2f |\n", atual->acoes, atual->preco);
			atual = atual->proximo;
		}

		if(atual->identificador == FBOK34 && atual->operacao == VENDA){
			printf("                                        _____________________________________\n");
			printf("                                        | FBOK34 | VENDA | %d | %.2f |\n", atual->acoes, atual->preco);
			atual = atual->proximo;
		}

		if(atual->identificador == FBOK34 && atual->operacao == COMPRA){
			printf("_____________________________________\n");
			printf("| FBOK34 | COMPRA | %d | %.2f |\n", atual->acoes, atual->preco);
			atual = atual->proximo;
		}
		if(atual->identificador == AMZO34 && atual->operacao == VENDA){
			printf("                                        _____________________________________\n");
			printf("                                        | AMZO34 | VENDA | %d | %.2f |\n", atual->acoes, atual->preco);
			atual = atual->proximo;
		}

		if(atual->identificador == AMZO34 && atual->operacao == COMPRA){
			printf("_____________________________________\n");
			printf("| AMZO34 | COMPRA | %d | %.2f |\n", atual->acoes, atual->preco);
			atual = atual->proximo;
		}
	}

    int decisao;

	printf("\n1 - Listar ofertas novamente\n2 - Informar nova oferta\n3 - Negociar ofertas\n4 - Sair do programa\n");
	scanf("%d", &decisao);
	while(1){

		switch(decisao){

			case 1:
			listar_ofertas();
			break;
			case 2:
			inserir_ofertas();
			break;
			case 3:
			negociar_ofertas();
			break;
			case 4:
			finalizar_sessao();
			exit(0);
			break;
			default:
			printf("Escolha Inválida.");
			break;
		}

	}

}

void negociar_ofertas(){
	//O nó atual vai apontar para o cabeçote
	struct No *atual = cabecote, *indice = NULL;

	if(cabecote == NULL) {

		return;

	}else{

		int posicao_compra = 0,posicao_venda = 0;

		while(atual != NULL) {

			indice = atual->proximo;

			while(indice != NULL) {

				if((atual->preco == indice->preco) &&
				   (atual->acoes <= indice->acoes) &&
				   (atual->identificador == indice->identificador) &&
				   (atual->operacao == COMPRA && indice->operacao == VENDA)) {

					char decisao;

					if(atual->identificador == GOGL34){
						printf("Deseja realizar esta compra? (s/n)\n");
						printf("_______________________________________________________________________\n");
						printf("| GOGL34 | COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", atual->acoes, atual->preco, indice->acoes, indice->preco);
						scanf("%c", &decisao);

						while(decisao != 'y' && decisao != 'n'){

							printf("Opção inválida.\n");
							printf("Deseja realizar esta compra? (s/n)\n");
							printf("_______________________________________________________________________\n");
							printf("| GOGL34 | COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", atual->acoes, atual->preco, indice->acoes, indice->preco);
							scanf("%c", &decisao);

							if(decisao == 'y'){
								printf("Cotação GOGL34:");
								printf("_______________________________________________________________________\n");
								printf("| GOGL34 | COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", atual->acoes, atual->preco, indice->acoes, indice->preco);

								indice->acoes = indice->acoes - atual->acoes;

								if(indice->acoes == 0){

									eliminar_ofertas(posicao_venda);

								}

								if(atual->acoes == 0){

									eliminar_ofertas(posicao_compra);

								}

							}

							if(decisao == 'n'){

								break;

							}

						}
					}
					if(atual->identificador == FBOK34){

						printf("Deseja realizar esta compra?\n");
						printf("_______________________________________________________________________\n");
						printf("| FBOK34 | COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", atual->acoes, atual->preco, indice->acoes, indice->preco);
						while(decisao != 'y' && decisao != 'n'){

							printf("Opção inválida.\n");
							printf("Deseja realizar esta compra? (s/n)\n");
							printf("_______________________________________________________________________\n");
							printf("| FBOK34 | COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", atual->acoes, atual->preco, indice->acoes, indice->preco);
							scanf("%c", &decisao);

							if(decisao == 'y'){
								printf("Cotação FBOK34:");
								printf("_______________________________________________________________________\n");
								printf("| FBOK34 | COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", atual->acoes, atual->preco, indice->acoes, indice->preco);

								indice->acoes = indice->acoes - atual->acoes;

								if(indice->acoes == 0){

									eliminar_ofertas(posicao_venda);

								}

								if(atual->acoes == 0){

									eliminar_ofertas(posicao_compra);

								}

							}

							if(decisao == 'n'){

								break;

							}
						}
					}
					if(atual->identificador == AMZO34){

						printf("Deseja realizar esta compra?\n");
						printf("_______________________________________________________________________\n");
						printf("| AMZO34 | COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", atual->acoes, atual->preco, indice->acoes, indice->preco);
						scanf("%c", &decisao);
						while(decisao != 'y' && decisao != 'n'){

							printf("Opção inválida.\n");
							printf("Deseja realizar esta compra? (s/n)\n");
							printf("_______________________________________________________________________\n");
							printf("| AMZO34 | COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", atual->acoes, atual->preco, indice->acoes, indice->preco);
							scanf("%c", &decisao);

							if(decisao == 'y'){
								printf("Cotação AMZO34:");
								printf("_______________________________________________________________________\n");
								printf("| AMZO34 | COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", atual->acoes, atual->preco, indice->acoes, indice->preco);

								indice->acoes = indice->acoes - atual->acoes;

								if(indice->acoes == 0){

									eliminar_ofertas(posicao_venda);

								}

								if(atual->acoes == 0){

									eliminar_ofertas(posicao_compra);

								}

							}

							if(decisao == 'n'){

								break;

							}
						}
					}

				}

			}
			posicao_venda++;
			indice = indice->proximo;
		}
		posicao_compra++;
		atual = atual->proximo;
	}
}


void eliminar_ofertas(int posicao){

	struct No *temp,*ptr;

	if(cabecote == NULL){

		printf("Lista vazia");
		return;

	}else{

		if(posicao == 0){

			ptr = cabecote;
			cabecote = cabecote->proximo ;
			free(ptr);

		}else{
			ptr = cabecote;
			for(int i = 0; i < posicao; i++) {
				temp = ptr;
				ptr = ptr->proximo ;

				if(ptr == NULL){
					printf("Posição não encontrada.\n");
					return;
				}
			}
			temp->proximo = ptr->proximo ;
			free(ptr);
		}
	}

}
