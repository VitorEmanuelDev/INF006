#include <stdio.h>
#include <stdlib.h>

#include "order_book.h"

int main(int argc, char **argv){

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
					listar_ofertas(identificador);
					break;
					case 2:
					listar_ofertas(identificador);
					break;
					case 3:
					listar_ofertas(identificador);
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
