#include <stdio.h>
#include <stdlib.h>

#include "order_book.h"

struct Compra *cabecote_compra = NULL;
struct Venda *cabecote_venda = NULL;

struct Compra_Arq *cabecote_compra_arq = NULL;
struct Venda_Arq *cabecote_venda_arq = NULL;


//OFERTAS

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
	printf("\n3 - AMZO34\n");
	printf("\n4 - Ver arquivo");
	scanf("%d", &decisao);

	while(decisao != GOGL34 && decisao != FBOK34 && decisao != AMZO34 && decisao != ARQUIVO){

		printf("\nOpção inválida.");
		printf("\nQuais ações deseja visualizar?");
		printf("\n1 - GOGL34");
		printf("\n2 - FBOK34");
		printf("\n3 - AMZO34");
		printf("\n4 - Ver arquivo");
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

		printf("Não há um número suficiente de ofertas no momento.");
		menu();

	}else{
		printf("********************************* BOOK DE PRECOS ***********************************\n\n");
		while(compra_atual != NULL || venda_atual != NULL) {
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

		printf("Não há um número suficiente de ofertas no momento.");
		menu();

	}else{
		printf("********************************* BOOK DE PRECOS ***********************************\n\n");
		while(compra_atual != NULL || venda_atual != NULL) {
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

		printf("Não há um número suficiente de ofertas no momento.");
		menu();

	}else{
		printf("********************************* BOOK DE PRECOS ***********************************\n\n");
		while(compra_atual != NULL || venda_atual != NULL) {
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
	printf("********************************* BOOK DE PRECOS ***********************************\n\n");
		if(decisao == COMPRA){

			//buscar_arquivos_compra();

		}else{

			buscar_arquivos_venda();

		}


}



void negociar_ofertas(){

	//O nó atual vai apontar para o cabeçote
	struct Compra *compra_atual = cabecote_compra;
	struct Venda *venda_atual = cabecote_venda;
	int decisao;
	int posicao_compra = 0, posicao_venda = 0;

	printf("\nQuais ações deseja negociar?");
	printf("\n1 - GOGL34");
	printf("\n2 - FBOK34");
	printf("\n3 - AMZO34\n");
	scanf("%d", &decisao);

	while(decisao != GOGL34 && decisao != FBOK34 && decisao != AMZO34){

		printf("\nOpção inválida.");
		printf("\nQuais ações deseja comprar?");
		printf("\n1 - GOGL34");
		printf("\n2 - FBOK34");
		printf("\n3 - AMZO34\n");
		scanf("%d", &decisao);

	}

	if(cabecote_compra == NULL || cabecote_venda == NULL) {

		printf("Não há um número suficiente de ofertas no momento.");
		menu();
		return;

	}

	if(decisao == GOGL34){

		while(compra_atual != NULL) {

			venda_atual = cabecote_venda;

			while(venda_atual != NULL) {

				if((compra_atual->preco_compra == venda_atual->preco_venda) &&
				   ((compra_atual->acoes_compra <= venda_atual->acoes_venda) && compra_atual->acoes_compra > 0) &&
				   (compra_atual->papel_compra == GOGL34 && venda_atual->papel_venda == GOGL34)) {

					int decisao;
					printf("Deseja realizar esta compra?\n1 - Sim\n2 - Não\n");
					printf("| GOGL34 | COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", compra_atual->acoes_compra, compra_atual->preco_compra, venda_atual->acoes_venda, venda_atual->preco_venda);
					scanf("%d", &decisao);

					while(decisao != SIM && decisao != NAO){

						printf("Opção inválida.\n");
						printf("Deseja realizar esta compra?\n1 - Sim\n2 - Não\n");
						printf("| GOGL34 | COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", compra_atual->acoes_compra, compra_atual->preco_compra, venda_atual->acoes_venda, venda_atual->preco_venda);
						scanf("%d", &decisao);
					}

					if(decisao == SIM){
						printf("Cotação GOGL34:");
						printf("| GOGL34 | ÚLTIMO PREÇO NEGOCIADO | %d | %.2f |\n", compra_atual->acoes_compra, compra_atual->preco_compra);

						venda_atual->acoes_venda = venda_atual->acoes_venda - compra_atual->acoes_compra;
						int valor_venda = venda_atual->acoes_venda;

						int valor_compra = compra_atual->acoes_compra = 0;


						if(valor_venda == 0 || valor_compra == 0){

							eliminar_ofertas(posicao_venda, valor_venda, posicao_compra, valor_compra);

						}

					}else if(decisao == NAO){

						//break;
						menu();

					}

				}

				posicao_venda++;
				venda_atual = venda_atual->proxima_venda;
			}

			posicao_compra++;
			compra_atual = compra_atual->proxima_compra;
		}

	}

	if(decisao == FBOK34){

			while(compra_atual != NULL) {

				venda_atual = cabecote_venda;

				while(venda_atual != NULL) {

					if((compra_atual->preco_compra == venda_atual->preco_venda) &&
					   (compra_atual->acoes_compra <= venda_atual->acoes_venda && compra_atual->acoes_compra > 0) &&
					   (compra_atual->papel_compra == FBOK34 && venda_atual->papel_venda == FBOK34)) {

						int decisao;
						printf("Deseja realizar esta compra?\n1 - Sim\n2 - Não\n");
						printf("| FBOK34 | COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", compra_atual->acoes_compra, compra_atual->preco_compra, venda_atual->acoes_venda, venda_atual->preco_venda);
						scanf("%d", &decisao);

						while(decisao != SIM && decisao != NAO){

							printf("Opção inválida.\n");
							printf("Deseja realizar esta compra?\n1 - Sim\n2 - Não\n");
							printf("| FBOK34 | COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", compra_atual->acoes_compra, compra_atual->preco_compra, venda_atual->acoes_venda, venda_atual->preco_venda);
							scanf("%d", &decisao);
						}

						if(decisao == SIM){
							printf("Cotação FBOK34:");
							printf("| FBOK34 | ÚLTIMO PREÇO NEGOCIADO | %d | %.2f |\n", compra_atual->acoes_compra, compra_atual->preco_compra);

							venda_atual->acoes_venda = venda_atual->acoes_venda - compra_atual->acoes_compra;
							int valor_venda = venda_atual->acoes_venda;

							int valor_compra = compra_atual->acoes_compra = 0;

							if(valor_venda == 0 || valor_compra == 0){

								eliminar_ofertas(posicao_venda, valor_venda, posicao_compra, valor_compra);

							}

						}else if(decisao == NAO){

							menu();

						}

					}

					posicao_venda++;
					venda_atual = venda_atual->proxima_venda;
				}

				posicao_compra++;
				compra_atual = compra_atual->proxima_compra;
			}

		}

	if(decisao == AMZO34){

			while(compra_atual != NULL) {

				venda_atual = cabecote_venda;

				while(venda_atual != NULL) {

					if((compra_atual->preco_compra == venda_atual->preco_venda) &&
					   (compra_atual->acoes_compra <= venda_atual->acoes_venda && compra_atual->acoes_compra > 0) &&
					   (compra_atual->papel_compra == AMZO34 && venda_atual->papel_venda == AMZO34)) {

						int decisao;
						printf("Deseja realizar esta compra?\n1 - Sim\n2 - Não\n");
						printf("| AMZO34 | COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", compra_atual->acoes_compra, compra_atual->preco_compra, venda_atual->acoes_venda, venda_atual->preco_venda);
						scanf("%d", &decisao);

						while(decisao != SIM && decisao != NAO){

							printf("Opção inválida.\n");
							printf("Deseja realizar esta compra?\n1 - Sim\n2 - Não\n");
							printf("| AMZO34 | COMPRA | %d | %.2f | VENDA | %d | %.2f |\n", compra_atual->acoes_compra, compra_atual->preco_compra, venda_atual->acoes_venda, venda_atual->preco_venda);
							scanf("%d", &decisao);
						}

						if(decisao == SIM){
							printf("Cotação AMZO34:");
							printf("| AMZO34 | ÚLTIMO PREÇO NEGOCIADO | %d | %.2f |\n", compra_atual->acoes_compra, compra_atual->preco_compra);

							venda_atual->acoes_venda = venda_atual->acoes_venda - compra_atual->acoes_compra;
							int valor_venda = venda_atual->acoes_venda;

							int valor_compra = compra_atual->acoes_compra = 0;

							if(valor_venda == 0 || valor_compra == 0){

								eliminar_ofertas(posicao_venda, valor_venda, posicao_compra, valor_compra);

							}


						}else if(decisao == NAO){

							break;

						}

					}

					posicao_venda++;
					venda_atual = venda_atual->proxima_venda;
				}

				posicao_compra++;
				compra_atual = compra_atual->proxima_compra;
			}

		}

	menu();

}


void eliminar_ofertas(int posicao_venda, int valor_venda, int posicao_compra, int valor_compra){

	if(valor_compra == 0){

		struct Compra *temp_compra, *ptr_compra;

		if(cabecote_compra == NULL){

			printf("Lista vazia");
			return;

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

				printf("Lista vazia");
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

	 printf("\nAté mais!");
	 exit(0);
}


//VENDAS


void inserir_venda(){


	struct Venda *temp,*ptr;
	temp = (struct Venda *)malloc(sizeof(struct Venda));

	if(temp == NULL){
		printf("Espaço fora da memória.");
		return;
	}


	printf("De qual cotação deseja vender?");
	printf("\n1 - GOGL34");
	printf("\n2 - FBOK34");
	printf("\n3 - AMZO34\n");
	scanf("%d", &temp->papel_venda);

	while(temp->papel_venda != GOGL34 && temp->papel_venda != FBOK34 && temp->papel_venda != AMZO34){

		printf("\nOpção inválida.");
		printf("\nDe qual cotação deseja vender?");
		printf("\n1 - GOGL34");
		printf("\n2 - FBOK34");
		printf("\n3 - AMZO34\n");
		scanf("%d", &temp->papel_venda);

	}

	printf("Qual o preço de venda das ações?\n");
	scanf("%f",&temp->preco_venda);

	while(temp->preco_venda < 0){

		printf("\nValor deve ser positivo.");
		printf("Qual o preço de venda das ações?\n");
		scanf("%f",&temp->preco_venda);

	}

	printf("Quantas ações pelo preço informado?\n");
	scanf("%d",&temp->acoes_venda);

	while(temp->acoes_venda < 0){

		printf("\nValor deve ser positivo.");
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

}


void ordenar_vendas(){

	//O nó atual vai apontar para o cabeçote
	struct Venda *atual = cabecote_venda, *indice = NULL;

	int temp;

	if(cabecote_venda == NULL) {

		return;

	}else{

		while(atual != NULL) {
		//O nó atual vai apontar para o cabeçote

			indice = atual->proxima_venda;

			while(indice != NULL) {

				if(atual->preco_venda > indice->preco_venda) {

					temp = atual->preco_venda;
					atual->preco_venda = indice->preco_venda;
					indice->preco_venda = temp;

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
	file = fopen ("/home/vitor/Desktop/IFBA/INF006-Estrutura-de-Dados/simple_order_book/vendas.txt", "a");

	 if (file == NULL){

		fprintf(stderr, "\nNão foi possível abrir o arquivo.\n");
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

	if(fwrite != 0){

		fclose(file);
		menu();

	}else{

		printf("Erro ao salvaar arquivo\n");
		fclose(file);
		menu();

	}


}

void buscar_arquivos_venda(){

	FILE* file;
	file = fopen("/home/vitor/Desktop/IFBA/INF006-Estrutura-de-Dados/simple_order_book/vendas.txt","r");

	if (file == NULL){

		fprintf(stderr, "\nNão foi possível abrir o arquivo.\n");
		menu();
	}

	 char ch;
	 printf("OFERTAS DE VENDA");
	 while ((ch = fgetc(file)) != EOF)
	        putchar(ch);

   fclose(file);
   menu();

}



//COMPRAS


void inserir_compra(){

	struct Compra *temp,*ptr;
	temp = (struct Compra *)malloc(sizeof(struct Compra));

	if(temp == NULL){
		printf("Espaço fora da memória.");
		return;
	}

	printf("\nDe qual cotação deseja comprar?");
	printf("\n1 - GOGL34");
	printf("\n2 - FBOK34");
	printf("\n3 - AMZO34\n");
	scanf("%d", &temp->papel_compra);

	while(temp->papel_compra != GOGL34 && temp->papel_compra != FBOK34 && temp->papel_compra != AMZO34){

		printf("\nOpção inválida.");
		printf("De qual cotação deseja comprar?");
		printf("\n1 - GOGL34");
		printf("\n2 - FBOK34");
		printf("\n3 - AMZO34\n");
		scanf("%d", &temp->papel_compra);

	}

	printf("Qual o preço de compra das ações?\n");
	scanf("%f",&temp->preco_compra);

	while(temp->preco_compra < 0){

		printf("\nValor deve ser positivo.");
		printf("Qual o preço de compra das ações?\n");
		scanf("%f",&temp->preco_compra);

	}

	printf("Quantas ações pelo preço informado?\n");
	scanf("%d",&temp->acoes_compra);

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

	if(cabecote_compra == NULL) {

		return;

	}else{

		while(atual != NULL) {
		//O nó atual vai apontar para o cabeçote

			indice = atual->proxima_compra;

			while(indice != NULL) {

				if(atual->preco_compra < indice->preco_compra) {

					temp = atual->preco_compra;
					atual->preco_compra = indice->preco_compra;
					indice->preco_compra = temp;

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
	file = fopen ("/home/vitor/Desktop/IFBA/INF006-Estrutura-de-Dados/simple_order_book/compras.txt", "a");

	 if (file == NULL){

		fprintf(stderr, "\nNão foi possível abrir o arquivo.\n");
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

	if(fwrite != 0){

		fclose(file);
		menu();

	}else{

		printf("Erro ao salvaar arquivo\n");
		fclose(file);
		menu();

	}


}

void buscar_arquivos_compra(){

	FILE* file;
	file = fopen("/home/vitor/Desktop/IFBA/INF006-Estrutura-de-Dados/simple_order_book/compras.txt","r");

	if (file == NULL){

		fprintf(stderr, "\nNão foi possível abrir o arquivo.\n");
		menu();
	}

	 char ch;
	 printf("PEDIDOS DE COMPRA");
	 while ((ch = fgetc(file)) != EOF)
	        putchar(ch);

   fclose(file);
   menu();

}
