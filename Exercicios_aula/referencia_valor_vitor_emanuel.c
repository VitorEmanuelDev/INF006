#include <stdio.h>
#include <stdlib.h>

void troca(int* a, int* b) {

	/*o operador é utilizado para desreferenciar o ponteiro.
	 Isso ocorre para que se pegue o valor original ou o objeto
	 propriamente dito para o qual o ponteiro está apontando*/
    int tmp = *a;
    *a = *b;
    *b = tmp;

}

int main() {

    int n1 = 6;
    int n2 = 10;

    printf("Antes da troca (m,n): (%d,%d)\n",n1,n2);

    troca(&n1,&n2);// a funcao pega dois ponteiros de int como argumentos

    printf("Depois da troca (m,n): (%d,%d)\n",n1,n2);
    // m e n continuam com os mesmos valores de antes
}

