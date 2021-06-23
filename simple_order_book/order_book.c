#include <stdio.h>
#include <stdlib.h>

#include "order_book.h"


struct Compra *cabecote_compra = NULL;
struct Venda *cabecote_venda = NULL;

int menu(){

	int escolher;

	while(1){
		printf("\nBem vindo ao OrderBook\n");
		printf("\n1 - Listar ofertas");
		printf("\n2 - Inserir ofertas");
		printf("\n3 - Negociar ofertas");
		printf("\n4 - Sair");
		scanf("%d",&escolher);

		switch(escolher){

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
			break;
			default:
			printf("Escolha Inválida.");
			break;
		}
	}
 return 0;

}


void inserir_ofertas(){

	int decisao;
	printf("\nDeseja inserir uma compra ou uma venda?\n1 - Venda\n2 - Compra");
	scanf("%d", &decisao);


	while(decisao!= COMPRA && decisao != VENDA){

		printf("\nOpção inválida.");
		printf("\nDeseja inserir uma compra ou uma venda?\n1 - Venda\n2 - Compra");
		scanf("%d", &decisao );

	}

	if(decisao == VENDA){

		inserir_venda();

	}

	if(decisao == COMPRA){

		inserir_compra();

	}


}


void listar_ofertas() {

	int decisao;

    printf("\nQuais ações deseja visualizar?");
	printf("\n1 - GOGL34");
	printf("\n2 - FBOK34");
	printf("\n3 - AMZO34");
	printf("\n4 - Voltar");
	printf("\n5 - Ver arquivo");
	scanf("%d", &decisao);


	while(decisao != GOGL34 && decisao != FBOK34 && decisao != AMZO34 && decisao != ARQUIVO && decisao != VOLTAR){

		printf("\nOpção inválida.");
		printf("\nQuais ações deseja visualizar?");
		printf("\n1 - GOGL34");
		printf("\n2 - FBOK34");
		printf("\n3 - AMZO34");
		printf("\n4 - Voltar\n");
		printf("\n5 - Ver arquivo");
		scanf("%d", &decisao);


	}

	switch(decisao){

		case GOGL34:
		listar_GOGL34();
		break;
		case FBOK34:
		listar_FBOK34();
		break;
		case AMZO34:
		listar_AMZO34();
		break;
		case VOLTAR:
		menu();
		break;
		case ARQUIVO:
		escolher_arquivos();
		break;
		default:
		break;
	}

}

void listar_GOGL34(){

	struct Venda *venda_atual = cabecote_venda;
	struct Compra *compra_atual = cabecote_compra;

	if(cabecote_venda == NULL || cabecote_compra == NULL) {

		printf("Não há um número suficiente de ofertas no momento.\n");
		menu();

	}else{
		printf("**************************** BOOK DE PRECOS ***************************\n\n");
		while(compra_atual != NULL && venda_atual != NULL) {
		//O nó atual vai apontar para o cabeçote
			if(compra_atual->papel_compra == GOGL34) {

				printf("| GOGL34 | COMPRA | %d | %.2f |\n", compra_atual->acoes_compra, compra_atual->preco_compra);

			}

			if(venda_atual->papel_venda == GOGL34) {

				printf("                                        | GOGL34 | VENDA | %d | %.2f |\n", venda_atual->acoes_venda, venda_atual->preco_venda);

			}

			if(venda_atual != NULL){
				venda_atual = venda_atual->proxima_venda;
			}

			if(compra_atual != NULL){
				compra_atual = compra_atual->proxima_compra;
			}
		}
	}
	menu();


}

void listar_FBOK34(){

	struct Venda *venda_atual = cabecote_venda;
	struct Compra *compra_atual = cabecote_compra;

	if(cabecote_venda == NULL || cabecote_compra == NULL) {

		printf("Não há um número suficiente de ofertas no momento.\n");
		menu();

	}else{
		printf("**************************** BOOK DE PRECOS ***************************\n\n");
		while(compra_atual != NULL && venda_atual != NULL) {
		//O nó atual vai apontar para o cabeçote
			if(compra_atual->papel_compra == FBOK34) {

				printf("| FBOK34 | COMPRA | %d | %.2f |\n", compra_atual->acoes_compra, compra_atual->preco_compra);

			}

			if(venda_atual->papel_venda == FBOK34) {

				printf("                                        | FBOK34 | VENDA | %d | %.2f |\n", venda_atual->acoes_venda, venda_atual->preco_venda);

			}

			if(venda_atual != NULL){
				venda_atual = venda_atual->proxima_venda;
			}

			if(compra_atual != NULL){
				compra_atual = compra_atual->proxima_compra;
			}
		}
	}
	menu();

}

void listar_AMZO34(){


	struct Venda *venda_atual = cabecote_venda;
	struct Compra *compra_atual = cabecote_compra;

	if(cabecote_venda == NULL || cabecote_compra == NULL) {

		printf("Não há um número suficiente de ofertas no momento.\n");
		menu();

	}else{
		printf("**************************** BOOK DE PRECOS ***************************\n\n");
		while(compra_atual != NULL && venda_atual != NULL) {
		//O nó atual vai apontar para o cabeçote
			if(compra_atual->papel_compra == AMZO34) {

				printf("| AMZO34 | COMPRA | %d | %.2f |\n", compra_atual->acoes_compra, compra_atual->preco_compra);

			}

			if(venda_atual->papel_venda == AMZO34) {

				printf("                                        | AMZO34 | VENDA | %d | %.2f |\n", venda_atual->acoes_venda, venda_atual->preco_venda);

			}

			if(venda_atual != NULL){
				venda_atual = venda_atual->proxima_venda;
			}

			if(compra_atual != NULL){
				compra_atual = compra_atual->proxima_compra;
			}
		}
	}
	menu();

}


void escolher_arquivos(){

	int decisao;
	printf("\nDeseja visualizar o banco de compras ou de vendas?\n1 - Vendas\n2 - Compras");
	scanf("%d", &decisao);


	while(decisao!= COMPRA && decisao != VENDA){

		printf("\nOpção inválida.");
		printf("\nDeseja visualizar o banco de compras ou de vendas?\n1 - Vendas\n2 - Compras");
		scanf("%d", &decisao );

	}

	if(decisao == COMPRA){

		buscar_arquivos_compra();

	}else{

		buscar_arquivos_venda();

	}


}



void negociar_ofertas(){

	//O nó atual vai apontar para o cabeçote
	struct Compra *compra_atual = cabecote_compra;
	struct Venda *venda_atual = cabecote_venda;
	int papel, acoes, operacao;
	float preco;


	if(cabecote_compra == NULL || cabecote_venda == NULL) {

		printf("Não há um número suficiente de ofertas no momento.\n");
		menu();

	}

	printf("\nQuais ações deseja negociar?");
	printf("\n1 - GOGL34");
	printf("\n2 - FBOK34");
	printf("\n3 - AMZO34");
	printf("\n4 - Voltar\n");
	scanf("%d", &papel);


	while(papel != GOGL34 && papel != FBOK34 && papel != AMZO34 && papel != VOLTAR){

		printf("\nOpção inválida.");
		printf("\nQuais ações deseja negociar?");
		printf("\n1 - GOGL34");
		printf("\n2 - FBOK34");
		printf("\n3 - AMZO34");
		printf("\n4 - Voltar\n");
		scanf("%d", &papel);


	}

	if (papel == VOLTAR)
			menu();

	printf("\nQuantas ações deseja negociar?");
	scanf("%d", &acoes);


	while(acoes < 0){

		printf("\nQuantas ações deseja negociar?");
		scanf("%d", &acoes);


	}

	printf("\nA qual preço?");
	scanf("%f", &preco);


	while(acoes < 0){

		printf("\nA qual preço?");
		scanf("%f", &preco);


	}

	printf("\nQual operação deseja realizar?\n1 - Venda\n2 - Compra");
	scanf("%d", &operacao);


	while(operacao != VENDA && operacao != COMPRA){

		printf("\nQual operação deseja realizar?");
		scanf("%d", &operacao);


	}

	int posicao_compra = 0, posicao_venda = 0;

	if(operacao == VENDA){

		int flag = 0;

		while(venda_atual != NULL){

			if(venda_atual->preco_venda == preco &&
				venda_atual->papel_venda == papel) {

				flag = 1;
				break;
			}
			venda_atual = venda_atual->proxima_venda;
			posicao_venda++;

		}

		if(flag == 0){

			printf("Seu pedido de venda ainda não foi cadastrado online.\nPor favor, informe um pedido antes de acionar uma negociação.\n");
			menu();

		}

		while(compra_atual != NULL) {

			if(	compra_atual->preco_compra == preco &&
				compra_atual->acoes_compra > 0 &&
				compra_atual->papel_compra == papel) {

				int decisao;
				printf("Encontramos um match para o seu preço de venda\nDeseja realizar esta negociação?\n1 - Sim\n2 - Não\n");
				printf("| COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", compra_atual->acoes_compra, compra_atual->preco_compra, venda_atual->acoes_venda, venda_atual->preco_venda);
				scanf("%d", &decisao);


				while(decisao != SIM && decisao != NAO){

					printf("Opção inválida.\n");
					printf("Deseja realizar esta venda?\n1 - Sim\n2 - Não\n");
					printf("| COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", compra_atual->acoes_compra, compra_atual->preco_compra, venda_atual->acoes_venda, venda_atual->preco_venda);
					scanf("%d", &decisao);

				}

				int valor_compra;
				int valor_venda;

				if(decisao == SIM){

					if(papel == GOGL34){

						if(acoes <= compra_atual->acoes_compra && acoes <= venda_atual->acoes_venda){

							venda_atual->acoes_venda = venda_atual->acoes_venda - acoes;
							compra_atual->acoes_compra = compra_atual->acoes_compra - acoes;

							valor_venda = venda_atual->acoes_venda;
							valor_compra = compra_atual->acoes_compra;

							printf("| GOGL34 | ÚLTIMO PREÇO NEGOCIADO | %d | %.2f |\n", venda_atual->acoes_venda, venda_atual->preco_venda);

						}else{

							printf("Quantidade de ações do seu pedido excede a oferta dísponível.");
							menu();

						}

						if(valor_venda == 0 || valor_compra == 0){

							eliminar_ofertas(posicao_venda, valor_venda, posicao_compra, valor_compra);

						}

					}

					if(papel == FBOK34){

						if(acoes <= compra_atual->acoes_compra && acoes <= venda_atual->acoes_venda){

							venda_atual->acoes_venda = venda_atual->acoes_venda - acoes;
							compra_atual->acoes_compra = compra_atual->acoes_compra - acoes;

							valor_venda = venda_atual->acoes_venda;
							valor_compra = compra_atual->acoes_compra;

							printf("| FBOK34 | ÚLTIMO PREÇO NEGOCIADO | %d | %.2f |\n", venda_atual->acoes_venda, venda_atual->preco_venda);

						}else{

							printf("Quantidade de ações do seu pedido excede a oferta dísponível.");
							menu();
						}


						if(valor_venda == 0 || valor_compra == 0){

							eliminar_ofertas(posicao_venda, valor_venda, posicao_compra, valor_compra);

						}

					}

					if(papel == AMZO34){

						if(acoes <= compra_atual->acoes_compra && acoes <= venda_atual->acoes_venda){

							venda_atual->acoes_venda = venda_atual->acoes_venda - acoes;
							compra_atual->acoes_compra = compra_atual->acoes_compra - acoes;

							valor_venda = venda_atual->acoes_venda;
							valor_compra = compra_atual->acoes_compra;

							printf("| AMZO34 | ÚLTIMO PREÇO NEGOCIADO | %d | %.2f |\n", venda_atual->acoes_venda, venda_atual->preco_venda);

						}else{

							printf("Quantidade de ações do seu pedido excede a oferta dísponível.");
							menu();
						}

						if(valor_venda == 0 || valor_compra == 0){

							eliminar_ofertas(posicao_venda, valor_venda, posicao_compra, valor_compra);

						}

					}

				}else{

					menu();

				}

			}
			posicao_compra++;
			compra_atual = compra_atual->proxima_compra;
		}

	}

	if(operacao == COMPRA){

		int flag = 0;

		while(compra_atual != NULL){

			if(compra_atual->preco_compra == preco &&
			   compra_atual->papel_compra == papel) {

				flag = 1;
				break;

			}
			compra_atual = compra_atual->proxima_compra;
			posicao_compra++;
		}

		if(flag == 0){

			printf("Seu pedido de compra ainda não foi cadastrado online.\nPor favor, informe um pedido antes de acionar uma negociação.\n");
			menu();

		}

		int valor_compra;
		int valor_venda;

		while(venda_atual != NULL) {

			if(venda_atual->preco_venda == preco &&
				venda_atual->acoes_venda > 0 &&
				venda_atual->papel_venda == papel) {

				int decisao;
				printf("Encontramos um match para o seu preço de compra\nDeseja realizar esta negociação?\n1 - Sim\n2 - Não\n");
				printf("| COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", compra_atual->acoes_compra, compra_atual->preco_compra, venda_atual->acoes_venda, venda_atual->preco_venda);
				scanf("%d", &decisao);


				while(decisao != SIM && decisao != NAO){

					printf("Opção inválida.\n");
					printf("Deseja realizar esta compra?\n1 - Sim\n2 - Não\n");
					printf("| COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", compra_atual->acoes_compra, compra_atual->preco_compra, venda_atual->acoes_venda, venda_atual->preco_venda);
					scanf("%d", &decisao);

				}

				if(decisao == SIM){

					if(papel == GOGL34){

						if(acoes <= compra_atual->acoes_compra && acoes <= venda_atual->acoes_venda){

							venda_atual->acoes_venda = venda_atual->acoes_venda - acoes;
							compra_atual->acoes_compra = compra_atual->acoes_compra - acoes;

							valor_venda = venda_atual->acoes_venda;
							valor_compra = compra_atual->acoes_compra;

							printf("| GOGL34 | ÚLTIMO PREÇO NEGOCIADO | %d | %.2f |\n", venda_atual->acoes_venda, venda_atual->preco_venda);

						}else{

							printf("Quantidade de ações do seu pedido excede a oferta dísponível.");
							menu();
						}

						if(valor_venda == 0 || valor_compra == 0){

							eliminar_ofertas(posicao_venda, valor_venda, posicao_compra, valor_compra);

						}

					}

					if(papel == FBOK34){

						if(acoes <= compra_atual->acoes_compra && acoes <= venda_atual->acoes_venda){

							venda_atual->acoes_venda = venda_atual->acoes_venda - acoes;
							compra_atual->acoes_compra = compra_atual->acoes_compra - acoes;

							valor_venda = venda_atual->acoes_venda;
							valor_compra = compra_atual->acoes_compra;

							printf("| FBOK34 | ÚLTIMO PREÇO NEGOCIADO | %d | %.2f |\n", venda_atual->acoes_venda, venda_atual->preco_venda);

						}else{

							printf("Quantidade de ações do seu pedido excede a oferta dísponível.");
							menu();
						}

						if(valor_venda == 0 || valor_compra == 0){

							eliminar_ofertas(posicao_venda, valor_venda, posicao_compra, valor_compra);

						}

					}

					if(papel == AMZO34){

						if(acoes <= compra_atual->acoes_compra && acoes <= venda_atual->acoes_venda){

							venda_atual->acoes_venda = venda_atual->acoes_venda - acoes;
							compra_atual->acoes_compra = compra_atual->acoes_compra - acoes;

							valor_venda = venda_atual->acoes_venda;
							valor_compra = compra_atual->acoes_compra;

							printf("| AMZO34 | ÚLTIMO PREÇO NEGOCIADO | %d | %.2f |\n", venda_atual->acoes_venda, venda_atual->preco_venda);

						}else{

							printf("Quantidade de ações do seu pedido excede a oferta dísponível.");
							menu();
						}

						if(valor_venda == 0 || valor_compra == 0){

							eliminar_ofertas(posicao_venda, valor_venda, posicao_compra, valor_compra);

						}

					}

				}else{

					menu();

				}

			}
			posicao_venda++;
			venda_atual = venda_atual->proxima_venda;
		}

	}

	menu();

}


void eliminar_ofertas(int posicao_venda, int valor_venda, int posicao_compra, int valor_compra){

	if(valor_compra == 0){

		struct Compra *temp_compra, *ptr_compra;

		if(cabecote_compra == NULL){

			printf("Lista vazia. (delete)\n");
			menu();

		}else{

			if(posicao_compra == 0){

				ptr_compra = cabecote_compra;
				cabecote_compra = cabecote_compra->proxima_compra ;
				free(ptr_compra);

			}else{

				ptr_compra = cabecote_compra;
				for(int i = 0; i < posicao_compra; i++) {
					temp_compra = ptr_compra;
					ptr_compra = ptr_compra->proxima_compra;

					if(ptr_compra == NULL){
						printf("Posição não encontrada.\n");
						return;
					}
				}
				temp_compra->proxima_compra = ptr_compra->proxima_compra;
				free(ptr_compra);
			}

		}
	}

	if(valor_venda == 0){

		struct Venda *temp_venda, *ptr_venda;

			if(cabecote_venda == NULL){

				printf("Lista vazia (delete)\n");
				return;

			}else{

				if(posicao_venda == 0){

					ptr_venda = cabecote_venda;
					cabecote_venda = cabecote_venda->proxima_venda;
					free(ptr_venda);

				}else{

					ptr_venda = cabecote_venda;
					for(int i = 0; i < posicao_venda; i++) {
						temp_venda = ptr_venda;
						ptr_venda = ptr_venda->proxima_venda;

						if(ptr_venda == NULL){
							printf("Posição não encontrada.\n");
							return;
						}
					}
					temp_venda->proxima_venda = ptr_venda->proxima_venda;
					free(ptr_venda);
				}

			}

	}

	ordenar_vendas();

}

void finalizar_sessao(){

     Compra *temp_compra;
     while(cabecote_compra != NULL){
    	 temp_compra = cabecote_compra;
    	 cabecote_compra = cabecote_compra->proxima_compra;
          free(temp_compra);
     }

     Venda *temp_venda;
	 while(cabecote_venda != NULL){
		 temp_venda = cabecote_venda;
		  cabecote_venda = cabecote_venda->proxima_venda;
		  free(temp_venda);
	 }

	 printf("\nAté mais!\n");
	 exit(0);
}


//COMPRAS
void carregar_arquivo_compras(){

	int papel;
	int acoes;
	float preco;

    FILE * file  = fopen("/home/vitor/Desktop/IFBA/INF006-Estrutura-de-Dados/simple_order_book/compras_carregar.txt", "r");

    if(file == NULL){

    	printf("Não foi possível abrir o arquivo.\n");

    }


    while (fscanf(file, "%d %d %f", &papel, &acoes, &preco) != EOF ){

  // printf("%d %d %.2f \n", papel, acoes, preco);

    	popular_lista_compras(papel, acoes, preco);

    }

    fclose(file);

}

void popular_lista_compras(int papel, int acoes, float preco){

	struct Compra* temp = (struct Compra*) malloc(sizeof(struct Compra));

	temp->papel_compra = papel;
	temp->acoes_compra = acoes;
	temp->preco_compra = preco;
	temp->proxima_compra = NULL;

	struct Compra *atual = cabecote_compra, *indice = NULL;

	int swap;
	float swap_f;

	if (cabecote_compra == NULL){
		cabecote_compra = temp;
		return;

	}else{

		while(atual != NULL) {
		//O nó atual vai apontar para o cabeçote

			indice = atual->proxima_compra;

			while(indice != NULL) {

				if(atual->preco_compra < indice->preco_compra) {

					swap_f = atual->preco_compra;
					atual->preco_compra = indice->preco_compra;
					indice->preco_compra = swap_f;

					swap = atual->acoes_compra;
					atual->acoes_compra  = indice->acoes_compra;
					indice->acoes_compra = swap;

					swap = atual->papel_compra;
					atual->papel_compra =  indice->papel_compra;
					indice->papel_compra = swap;

				}
				indice = indice->proxima_compra;
			}
			atual = atual->proxima_compra;
		}
	}


	struct Compra* ultima = cabecote_compra;

	while (ultima->proxima_compra != NULL)
	        ultima = ultima->proxima_compra;

	    ultima->proxima_compra = temp;
	    return;
}

//COMPRAS


void inserir_compra(){

	struct Compra *temp,*ptr;
	temp = (struct Compra *)malloc(sizeof(struct Compra));

	if(temp == NULL){
		printf("Sem espaço alocado na memória\n");
		menu();
	}
	int decisao;

	printf("\nDe qual cotação deseja comprar?");
	printf("\n1 - GOGL34");
	printf("\n2 - FBOK34");
	printf("\n3 - AMZO34");
	printf("\n4 - Voltar\n");
	scanf("%d", &decisao);


	while(decisao != GOGL34 && decisao != FBOK34 && decisao != AMZO34 && decisao != VOLTAR){

		printf("\nOpção inválida.");
		printf("\nDe qual cotação deseja comprar?");
		printf("\n1 - GOGL34");
		printf("\n2 - FBOK34");
		printf("\n3 - AMZO34");
		printf("\n4 - Voltar\n");
		scanf("%d", &decisao);


	}

	if(decisao == VOLTAR){

		menu();

	}else{

		temp->papel_compra = decisao;

	}

	printf("Qual o preço de compra das ações?\n");
	scanf("%f",&temp->preco_compra);


	while(temp->preco_compra < 0){

		printf("\nValor deve ser positivo.");
		printf("Qual o preço de compra das ações?\n");
		scanf("%f",&temp->preco_compra);

	}

	printf("Quantas ações pelo preço informado?\n");
	scanf("%d", &temp->acoes_compra);


	while(temp->acoes_compra < 0){

		printf("\nValor deve ser positivo.");
		printf("Quantas ações pelo preço informado?\n");
		scanf("%d",&temp->acoes_compra);


	}
	temp->proxima_compra = NULL;

	if(cabecote_compra == NULL){
		cabecote_compra = temp;
	}else{
		ptr = cabecote_compra;
		while(ptr->proxima_compra != NULL){
			ptr = ptr->proxima_compra ;
		}
		ptr->proxima_compra = temp;
	}

    ordenar_compras();

}


void ordenar_compras(){
	//O nó atual vai apontar para o cabeçote
	struct Compra *atual = cabecote_compra, *indice = NULL;

	int temp;
	float temp_f;

	if(cabecote_compra == NULL) {

		printf("Sem espaço alocado em memória. (sort)\n");
		menu();

	}else{

		while(atual != NULL) {
		//O nó atual vai apontar para o cabeçote

			indice = atual->proxima_compra;

			while(indice != NULL) {

				if(atual->preco_compra < indice->preco_compra) {

					temp_f = atual->preco_compra;
					atual->preco_compra = indice->preco_compra;
					indice->preco_compra = temp_f;

					temp = atual->acoes_compra;
					atual->acoes_compra  = indice->acoes_compra;
					indice->acoes_compra = temp;

					temp = atual->papel_compra;
					atual->papel_compra =  indice->papel_compra;
					indice->papel_compra = temp;

				}
				indice = indice->proxima_compra;
			}
			atual = atual->proxima_compra;
		}
	}

	salvar_arquivos_compra();
	//menu();

}

void salvar_arquivos_compra(){

	struct Compra *temp = cabecote_compra;

	FILE* file;
	file = fopen ("/home/vitor/Desktop/IFBA/INF006-Estrutura-de-Dados/simple_order_book/historico_compras.txt", "w");

	 if (file == NULL){

		fprintf(stderr, "Não foi possível abrir o arquivo.\n");
		menu();
	}

	while(temp != NULL){

		if(temp->papel_compra == GOGL34){

			fprintf(file,"%s","| GOGL34 |");

		}else if(temp->papel_compra == FBOK34){

			fprintf(file,"%s","| FBOK34 |");

		}else if(temp->papel_compra == AMZO34){

			fprintf(file,"%s","| AMZN34 |");

		}

		fprintf(file," %d |",temp->acoes_compra);
		fprintf(file," %.2f |",temp->preco_compra);
		fprintf(file,"\n");
		temp = temp->proxima_compra;
	}

	fclose(file);
	menu();

}

void buscar_arquivos_compra(){

	FILE* file;
	file = fopen("/home/vitor/Desktop/IFBA/INF006-Estrutura-de-Dados/simple_order_book/historico_compras.txt","r");

	if (file == NULL){

		fprintf(stderr, "Não foi possível abrir o arquivo.\n");
		menu();
	}

	 char ch;
	 printf("HISTÓRICO DE PREÇOS: COMPRAS\n");
	 while ((ch = fgetc(file)) != EOF)
	        putchar(ch);

   fclose(file);
   menu();
}

//VENDAS
void carregar_arquivo_vendas()
{
	int papel;
	int acoes;
	float preco;

    FILE * file  = fopen("/home/vitor/Desktop/IFBA/INF006-Estrutura-de-Dados/simple_order_book/vendas_carregar.txt", "r");

    if (file == NULL){

	 printf("Não foi possível abrir o arquivo.\n");

   }


    while (fscanf(file, "%d %d %f", &papel, &acoes, &preco) != EOF ){

  // printf("%d %d %.2f \n", papel, acoes, preco);

    	popular_lista_vendas(papel, acoes, preco);

    }
    fclose(file);

}

void popular_lista_vendas(int papel, int acoes, float preco){

	struct Venda* temp = (struct Venda*) malloc(sizeof(struct Venda));

	temp->papel_venda = papel;
	temp->acoes_venda = acoes;
	temp->preco_venda = preco;
	temp->proxima_venda = NULL;

	struct Venda *atual = cabecote_venda, *indice = NULL;

	int swap;
	float swap_f;

	if (cabecote_venda == NULL){
		cabecote_venda = temp;
		return;

	}else{

		while(atual != NULL) {
		//O nó atual vai apontar para o cabeçote

			indice = atual->proxima_venda;

			while(indice != NULL) {

				if(atual->preco_venda > indice->preco_venda) {

					swap_f = atual->preco_venda;
					atual->preco_venda = indice->preco_venda;
					indice->preco_venda = swap_f;

					swap = atual->acoes_venda;
					atual->acoes_venda  = indice->acoes_venda;
					indice->acoes_venda = swap;

					swap = atual->papel_venda;
					atual->papel_venda =  indice->papel_venda;
					indice->papel_venda = swap;

				}
				indice = indice->proxima_venda;
			}
			atual = atual->proxima_venda;
		}
	}


	struct Venda* ultima = cabecote_venda;

	while (ultima->proxima_venda != NULL)
	        ultima = ultima->proxima_venda;

	    ultima->proxima_venda = temp;
	    return;
}



void inserir_venda(){


	struct Venda *temp,*ptr;
	temp = (struct Venda *)malloc(sizeof(struct Venda));

	if(temp == NULL){
		printf("Espaço fora da memória.\n");
		return;
	}

	int decisao;

	printf("De qual cotação deseja vender?");
	printf("\n1 - GOGL34");
	printf("\n2 - FBOK34");
	printf("\n3 - AMZO34");
	printf("\n4 - Voltar");
	scanf("%d", &decisao);


	while(decisao != GOGL34 && decisao != FBOK34 && decisao != AMZO34 && decisao != VOLTAR){

		printf("\nOpção inválida.");
		printf("\nDe qual cotação deseja vender?");
		printf("\n1 - GOGL34");
		printf("\n2 - FBOK34");
		printf("\n3 - AMZO34");
		printf("\n4 - Voltar");
		scanf("%d", &decisao);


	}

	if(decisao == VOLTAR){

		menu();

	}else{

		temp->papel_venda = decisao;

	}

	printf("Qual o preço de venda das ações?\n");
	scanf("%f",&temp->preco_venda);



	while(temp->preco_venda < 0){

		printf("Qual o preço de venda das ações?\n");
		scanf("%f",&temp->preco_venda);

	}

	printf("Quantas ações pelo preço informado?\n");
	scanf("%d",&temp->acoes_venda);



	while(temp->acoes_venda < 0){

		printf("Quantas ações pelo preço informado?\n");
		scanf("%d",&temp->acoes_venda);

	}

	temp->proxima_venda = NULL;

	if(cabecote_venda == NULL){
		cabecote_venda = temp;
	}else{
    	ptr = cabecote_venda;
        while(ptr->proxima_venda != NULL){
            ptr = ptr->proxima_venda ;
        }
        ptr->proxima_venda = temp;
	}

    ordenar_vendas();
	//salvar_arquivos_venda();

}


void ordenar_vendas(){

	//O nó atual vai apontar para o cabeçote
	struct Venda *atual = cabecote_venda, *indice = NULL;

	int temp;
	float temp_f;

	if(cabecote_venda == NULL) {

		printf("Sem espaço alocado em memória. (sort)\n");
		menu();

	}else{

		while(atual != NULL) {
		//O nó atual vai apontar para o cabeçote

			indice = atual->proxima_venda;

			while(indice != NULL) {

				if(atual->preco_venda > indice->preco_venda) {

					temp_f = atual->preco_venda;
					atual->preco_venda = indice->preco_venda;
					indice->preco_venda = temp_f;

					temp = atual->acoes_venda;
					atual->acoes_venda  = indice->acoes_venda;
					indice->acoes_venda = temp;

					temp = atual->papel_venda;
					atual->papel_venda =  indice->papel_venda;
					indice->papel_venda = temp;

				}
				indice = indice->proxima_venda;
			}
			atual = atual->proxima_venda;
		}
	}

	salvar_arquivos_venda();
	//menu();

}

void salvar_arquivos_venda(){

	struct Venda *temp = cabecote_venda;

	FILE* file;
	file = fopen ("/home/vitor/Desktop/IFBA/INF006-Estrutura-de-Dados/simple_order_book/historico_vendas.txt", "w");

	 if (file == NULL){

		fprintf(stderr, "Não foi possível abrir o arquivo.(venda)\n");
		menu();
	}

	while(temp != NULL){

		if(temp->papel_venda == GOGL34){

			fprintf(file,"%s","| GOGL34 |");

		}else if(temp->papel_venda == FBOK34){

			fprintf(file,"%s","| FBOK34 |");

		}else if(temp->papel_venda == AMZO34){

			fprintf(file,"%s","| AMZN34 |");

		}

		fprintf(file," %d |",temp->acoes_venda);
		fprintf(file," %.2f |",temp->preco_venda);
		fprintf(file,"\n");
		temp = temp->proxima_venda;
	}

	fclose(file);
	menu();


}

void buscar_arquivos_venda(){

	FILE* file;
	file = fopen("/home/vitor/Desktop/IFBA/INF006-Estrutura-de-Dados/simple_order_book/historico_vendas.txt","r");

	if (file == NULL){

		fprintf(stderr, "\nNão foi possível abrir o arquivo.\n");
		menu();
	}

	 char ch;
	 printf("HISTÓRICO DE PREÇOS: VENDAS\n");
	 while ((ch = fgetc(file)) != EOF)
	        putchar(ch);

   fclose(file);
   menu();

}



