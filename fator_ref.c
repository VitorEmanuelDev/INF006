#include <stdio.h>
#include <stdlib.h>

void fatorial(int*);

int main(void)
{
  int num;
  printf("Digite um numero: ");
  scanf("%d", &num);   
  
  fatorial(&num);  

  printf("Fator: %d \n", num);  
  
  return 0;
}

void fatorial(int *numero)
{
  if (*numero == 0 || *numero == 1){
  	
  	*numero = 1;
  
  }else{
  
       int temp = *numero;     
	*numero = *numero - 1;
	fatorial(&*numero); 
	*numero = *numero * temp;
	
  }
 
}


