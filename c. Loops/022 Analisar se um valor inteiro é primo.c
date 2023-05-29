# include <stdio.h>
# include <stdlib.h>

// Ler um número inteiro e imprimir se ele é primo ou não (while loop)

int main(){
	int valor, divisores=0, aux;
	
	printf("\nDigite um numero inteiro para consultar se ele e primo: ");
	scanf("%d", &valor);
	
	if (valor == 0)
	{
		printf("\n0 nao e primo.");
		return 0;
	}
	if (valor < 0)
	{
		printf("\nNao existe numero primo negativo.");
		return 0;
	}
	
	aux = valor;
	
	while (aux != 0)
	{
		if (valor % aux == 0)
		{
			divisores++;
		}

		aux--;
	}
	
	if (divisores == 2)
	{
		printf("\nO valor %d e PRIMO", valor);
	}
	else
	{
		printf("\nO valor %d NAO e PRIMO", valor);
	}
	
	return 0;
}

