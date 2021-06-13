#include <stdio.h>
#include <stdlib.h>

#define VENDA 1
#define COMPRA 2

#define GOGL34 1
#define FBOK34 2
#define AMZO34 3

#include "order_book.h"

struct No *cabecote, *cauda = NULL;

void finalizar_sessao()
{
     No *temp;
     while(cabecote != NULL){
          temp = cabecote;
          cabecote = cabecote->proximo;
          free(temp);
     }
}

void inserir_ofertas(){
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

		// Se a lista estiver vazia
		if (cabecote == NULL) {
			// Tanto a cabeça quanto a cauda apontarão para newNode
			cabecote = cauda = temp;
			// o anterior do cabeçote apontará para NULL
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
       // persistir_ofertas(cabecote);

}


void ordenar_lista(){
	//O nó atual vai apontar para o cabeçote
	//struct No *atual = cabecote, *indice = NULL;

	struct No *atual = NULL, *indice = NULL;
	int temp;

	if(cabecote == NULL) {

		return;

	}else{
		//while(indice != NULL) {
		//O nó atual vai apontar para o cabeçote
		 for(atual = cabecote; atual->proximo != NULL; atual = atual->proximo) {

			//indice = atual->proximo;

			//while(indice != NULL) {
			for(indice = atual->proximo; indice != NULL; indice = indice->proximo) {

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
				//indice = indice->proximo;
			}
			//atual = atual->proximo;
		}
	}
}

No *listar_arquivo(No *cabecote, FILE *arquivo){

	size_t valor;

	if(cabecote == NULL){

		cabecote = malloc(sizeof(No));
		valor = fread(cabecote, sizeof(No), 1, arquivo);

		cabecote->proximo = NULL;
		cabecote->anterior;

	}else{

		No *indice = cabecote;
		cabecote = malloc(sizeof(No));
		No *temp = malloc(sizeof(No));

		while(indice->proximo != NULL){

			indice = indice->proximo;

		}

		valor = fread(temp, sizeof(No), 1, arquivo);
		indice->proximo = temp;
		temp->proximo = NULL;
		temp->anterior = indice;

	}

	return cabecote;

}

void listar_ofertas() {
    //Nó atual vai apontar para o cabecote
    struct No *atual = cabecote;

    if(cabecote == NULL) {
		printf("Lista vazia \n");
		return;
	}

    //FILE *arquivo;

   // arquivo = fopen("ofertas.txt", "rb");

   /* if(arquivo != NULL){

    	fseek(arquivo, 0, SEEK_END);
    	long tamanho_arquivo = ftell(arquivo);
    	rewind(arquivo);

    	int registros = (int)(tamanho_arquivo / (sizeof(No)));

    	for(int i = 0; i < registros; i++){

    		fseek(arquivo, (sizeof(No) * i), SEEK_SET);
    		cabecote = listar_arquivo(cabecote, arquivo);
    	}

    }else{*/


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

    //}

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


void persistir_ofertas(No *cabecote){

	FILE *arquivo;

	arquivo = fopen("ofertas.txt", "wb");

	if(arquivo != NULL){

		No *atual = cabecote;
		No *segura_proximo = NULL;
		No *segura_anterior = NULL;

		while(atual != NULL){

			segura_proximo = atual->proximo;
			segura_anterior = atual->anterior;

			atual->proximo = NULL;
			atual->anterior = NULL;

			fseek(arquivo, 0, SEEK_END);
			fwrite(atual, sizeof(No), 1, arquivo);

			atual->proximo = segura_proximo;
			atual->anterior = segura_anterior;

			segura_proximo = NULL;
			segura_anterior = NULL;

			atual = atual->proximo;

		}

		fclose(arquivo);
		arquivo = NULL;

	}else{

		printf("Erro ao abrir arquivo.");

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
