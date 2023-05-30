# include <stdio.h>
# include <stdlib.h>

// Ler indeterminados numeros inteiros e imprimir o seu dobro e quantidade de numeros (while loop)

int main(){
	int valor, contador=0, dobro;
	
	while (1)
	{
		printf("\nDigite um valor ou -1 para sair: ");
		scanf("%d", &valor);
		
		if (valor == -1)
		{
			break;
		}
		
		dobro = valor * 2;
		contador++;
		
		printf("\nO dobro de %d vale %d", valor, dobro);
	}	
	
	printf("\nVoce digitou %d valores", contador);
	
	return 0;
}
