#include <stdio.h>
#include <stdlib.h>

#include "order_book.h"


int main(){

	carregar_arquivo_compras();
	carregar_arquivo_vendas();

	int escolher;

	while(1){
		printf("\nBem vindo ao OrderBook\n");
		printf("\n1 - Listar ofertas");
		printf("\n2 - Inserir ofertas");
		printf("\n3 - Negociar ofertas");
		printf("\n4 - Sair");
		scanf("%d",&escolher);
		fflush(stdin);
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
