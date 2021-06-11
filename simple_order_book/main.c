#include <stdio.h>
#include <stdlib.h>

#include "order_book.h"

int main(void){

	int escolher;

	while(1){

		printf("Bem vindo ao OrderBook\n");
		printf("\n1 - Listar ofertas\n");
		printf("\n2 - Inserir ofertas\n");
		printf("\n3 - Negociar ofertas\n");
		printf("\n4 - Sair\n");
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
			exit(0);
			break;
			default:
			printf("Escolha Inválida.");
			break;
		}
	}
	return 0;

}
