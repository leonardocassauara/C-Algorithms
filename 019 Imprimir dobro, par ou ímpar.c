# include <stdio.h>
# include <stdlib.h>

// Ler indeterminados numeros inteiros e imprimir o seu dobro e dizer se o valor inicial � par ou impar (while loop)

int main(){
	int valor, dobro;
	
	while (1)
	{
		printf("\nDigite um numero inteiro qualquer ou -1 para sair: ");
		scanf("%d", &valor);
		
		if (valor == -1)
		{
			break;
		}
		
		dobro = valor * 2;
		
		if (valor % 2 == 0)
		{
			printf("\nO valor %d e PAR", valor);
		}
		else
		{
			printf("\nO valor %d e IMPAR", valor);
		}
		
		printf("\nO dobro de %d vale %d", valor, dobro);
	}
	
	return 0;
}
