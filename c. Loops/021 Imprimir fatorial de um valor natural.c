# include <stdio.h>
# include <stdlib.h>

// Ler um número inteiro e imprimir o seu fatorial (for loop)

int main(){
	int valor, fatorial=1, valor_inicial;
	
	printf("\nDigite um numero inteiro qualquer para consultar o seu fatorial: ");
	scanf("%d", &valor);
	
	valor_inicial = valor;
	
	for (valor; valor != 0; valor--)
	{
		fatorial = fatorial * valor;
	}
	
	printf("\nO fatorial de %d vale %d", valor_inicial, fatorial);
	
	return 0;
}
