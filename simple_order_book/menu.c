#include <stdio.h>
#include <stdlib.h>

#include "order_book.h"

void menu(){

	int decisao;

	printf("\n1 - Listar ofertas\n2 - Informar nova oferta\n3 - Negociar ofertas\n4 - Sair\n");
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
			break;
			default:
			printf("Escolha Inválida.");
			break;
		}

	}

}
