# include <stdlib.h>
# include <stdio.h>
# include <locale.h>

// Problema: Criar um programa que imprimir todos os números inteiros entre dois números inteiros escolhidos pelo usuário
/* Abstração:	1. Ler os dois números inteiros
				2. Como queremos todos os números no intervalo entre dois numeros, temos que verificar se um número é maior o que outro
				3. Se for maior, trocar as posições de forma a evitar conflito no loop for
				4. Loop for para encontrar os números no intervalo
*/

int main() {
	setlocale(LC_ALL, "portuguese");
	int valor_1, valor_2, aux;
	
	printf("Digite um valor inteiro: ");
	scanf(" %d", &valor_1);
	
	printf("\nDigite outro valor inteiro: ");
	scanf(" %d", &valor_2);
	
	if (valor_1 > valor_2)
	{
		aux = valor_1;
		valor_1 = valor_2;
		valor_2 = aux;
	}
	
	printf("\nOs valores inteiros entre %d e %d são: ", valor_1, valor_2);
	
	for (valor_1 = valor_1 + 1; valor_1 < valor_2; valor_1++)
	{
		printf("%d ", valor_1);
	}
	
	return 0;
}
