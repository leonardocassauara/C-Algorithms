# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/*	Problema: Faça uma função que receba um vetor como parâmetro e retorne a soma de seus valores
	Abstração:	1. Declarar tipo e nome da função
				2. Declarar tipo e nome dos parâmetros
					2.1. Um parâmetro para o número de elementos do vetor, e outro parâmetro para o vetor -> int n, int vetor[n]
				3. Fazer um loop for para somar e acumular os valores do vetor inteiro
				4. Criar um vetor com capacidade e elementos decididos pelo usuário
				5. Chamar a função para somar seus elementos
				6. Imprimir resultado
*/

int soma_vetor(int n, int vetor[n]) {
	int i, acumulador=0;
	
	for (i = 0; i < n; i++)
	{
		acumulador = acumulador + vetor[i];
	}
	
	return acumulador;
}

int main() {
	setlocale(LC_ALL, "portuguese");
	int n, i, soma; 
	
	printf("Quantos elementos o vetor terá? ");
	scanf(" %d", &n);
	
	int vetor[n];
	
	for (i = 0; i < n; i++)
	{
		printf("\nDigite o %do valor do vetor: ", i+1);
		scanf(" %d", &vetor[i]);
	}
	
	soma = soma_vetor(n, vetor);
	
	printf("\nA soma dos valores do vetor vale %d", soma);
	
	return 0;
}
