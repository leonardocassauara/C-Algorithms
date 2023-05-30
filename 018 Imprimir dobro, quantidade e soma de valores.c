# include <stdio.h>
# include <stdlib.h>

// Ler indeterminados numeros inteiros e imprimir sua soma, quantidade e dobro (while loop)

int main(){
	int valor, dobro, contador=0, soma=0;
	
	while (1)
	{
		printf("\nDigite um numero inteiro qualquer ou -1 para sair: ");
		scanf("%d", &valor);
		
		if (valor == -1)
		{
			break;
		}
		
		dobro = valor * 2;
		soma = soma + valor;
		contador++;
		
		printf("\nO dobro de %d vale %d", valor, dobro);
		
	}
	
	printf("Voce digitou %d valores, e a soma deles vale %d", contador, soma);
	
	return 0;
}

