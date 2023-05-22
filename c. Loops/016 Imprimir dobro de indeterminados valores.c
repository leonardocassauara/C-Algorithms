# include <stdio.h>
# include <stdlib.h>

// Ler indeterminados numeros inteiros e imprimir o seu dobro (while loop)

int main (){
	int valor, dobro;
	
	while(1)
	{
		printf("\nDigite um valor ou -1 para sair: ");
		scanf("%d", &valor);	
		
		if (valor == -1)
		{
			break;
		}
		
		dobro = valor * 2;
		printf("\nO dobro de %d vale %d", valor, dobro);
    }	
	return 0;
}
