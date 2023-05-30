# include <stdio.h>
# include <stdlib.h>

// Ler um número inteiro e imprimir o seu numero de divisores naturais (while loop)

int main(){
	int valor, divisores=0, aux, aux_signal=1;
	
	printf("\nDigite um numero inteiro para consultar seu numero de divisores: ");
	scanf("%d", &valor);
	
	if (valor == 0)
	{
		printf("\nValor invalido! 0 nao e divisor.");
		return 0;
	}
	if (valor < 0)
	{
		aux_signal = -1;
		valor = valor * aux_signal;
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
	
	valor = valor * aux_signal;
	
	printf("\nO numero de divisores de %d e %d divisores", valor, divisores);
	
	return 0;
}

