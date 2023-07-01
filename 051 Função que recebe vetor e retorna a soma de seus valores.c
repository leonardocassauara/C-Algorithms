# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/*	Problema: Fa�a uma fun��o que receba um vetor como par�metro e retorne a soma de seus valores
	Abstra��o:	1. Declarar tipo e nome da fun��o
				2. Declarar tipo e nome dos par�metros
					2.1. Um par�metro para o n�mero de elementos do vetor, e outro par�metro para o vetor -> int n, int vetor[n]
				3. Fazer um loop for para somar e acumular os valores do vetor inteiro
				4. Criar um vetor com capacidade e elementos decididos pelo usu�rio
				5. Chamar a fun��o para somar seus elementos
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
	
	printf("Quantos elementos o vetor ter�? ");
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
