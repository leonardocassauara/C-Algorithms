# include <stdio.h>
# include <stdlib.h>

// Ler dois inteiros e imprimir o seu produto

int main(){
	int valor_1, valor_2, produto;
	
	printf("Digite um valor: ");
	scanf("%d", &valor_1);
	printf("Digite mais um valor: ");
	scanf("%d", &valor_2);
	
	produto = valor_1 * valor_2;
	
	printf("\nO produto entre %d e %d vale: %d", valor_1, valor_2, produto);
	
	return 0;
}
