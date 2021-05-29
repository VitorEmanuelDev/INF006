#include <stdio.h>

int soma10p(int *numero)
{
  *numero = *numero + 10;  
  return *numero;
}

int main(void)
{
  int numero;
  printf("Digite um numero: ");
  scanf("%d", &numero);   
  
  soma10p(&numero);  

  printf("Agora o numero vale: %d \n",numero);  
  return 0;
}
