#include <stdio.h>

int soma10(int x)
{
  x = x + 10;  
  return x;
}

int main(void)
{
  int numero;
  printf("Digite um numero: ");
  scanf("%d", &numero);  
       
  numero = soma10(numero);
  printf("Agora o numero vale: %d \n",numero);    
    
  return 0;
}
