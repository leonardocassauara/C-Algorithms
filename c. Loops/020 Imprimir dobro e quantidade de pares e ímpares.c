# include <stdio.h>
# include <stdlib.h>

// Ler indeterminados numeros inteiros e imprimir o seu dobro e quatidade de pares e impares digitados (while loop)

int main(){
	int valor, dobro, conta_par=0, conta_impar=0;
	
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
			conta_par++;
		}
		else
		{
			conta_impar++;
		}
		printf("\nO dobro de %d vale %d", valor, dobro);
	}
	
	printf("\nForam digitados %d valores PARES e %d valores IMPARES", conta_par, conta_impar);
	
	return 0;
}
