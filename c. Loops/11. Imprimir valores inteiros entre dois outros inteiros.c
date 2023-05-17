# include <stdio.h>
# include <stdlib.h>

// Imprimir todos os números entre dois números selecionados pelo usuário (for loop)

int main(){
	int valor_1, valor_2, aux;
	
	printf("Digite um valor: ");
	scanf("%d", &valor_1);
	printf("Digite mais um valor: ");
	scanf("%d", &valor_2);
	
	if (valor_2 > valor_1)
	{
		aux = valor_1;
		valor_1 = valor_2;
		valor_2 = aux;
	}
	printf("\nOs valores entre %d e %d sao: ", valor_1, valor_2);
	for (valor_2; valor_2 <= valor_1; valor_2++)
	{
		printf("%d ", valor_2);
	}
	
	return 0;
}
	
