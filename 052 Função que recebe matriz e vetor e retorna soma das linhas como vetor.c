# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/*	Problema: Criar função que recebe uma matriz quadrada como parâmetro e calcule a soma das suas linhas
	Abstração:	1. Declarar tipo e nome da função
					1.1. int soma_linha
				2. Declarar tipo e nome dos parâmetros
					2.1. int matriz[][n], int vetor[n]
				3. Utilizar um loop for para preencher o vetor inteiro com 0
				4. Utilizar um loop for para somar as linhas e atribuí-las ao vetor
				5. A função irá retornar o vetor, mas sem usar o return
				6. Chamar a função no main
*/

int soma_linha (int n, int matriz[][n], int vetor[n]) {
	int i, j;
	
	for (i = 0; i < n; i++)
	{
		vetor[i] = 0;
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			vetor[i] = vetor[i] + matriz[i][j];
		}
	}
}

int main() {
	setlocale(LC_ALL, "portuguese");
	int i, j, tam;
	
	printf("Qual será o tamanho da matriz quadrada? ");
	scanf(" %d", &tam);
	printf("\n");
	
	int grid[tam][tam], vet[tam];
	
	for (i = 0; i < tam; i++)
	{
		for (j = 0; j < tam; j++)
		{
			printf("Digite um valor para a posição (%d, %d): ", i, j);
			scanf(" %d", &grid[i][j]);
		}
	}
	
	soma_linha(tam, grid, vet);
	
	printf("\nMatriz: \n");
	for (i = 0; i < tam; i++)
	{
		for (j = 0; j < tam; j++)
		{
			printf("[%d]\t", grid[i][j]);
		}
		printf("\n");
	}
	
	printf("\nSoma das Linhas: \n");
	for (i = 0; i < tam; i++)
	{
		printf("[%d]\n", vet[i]);
	}
	
	return 0;	
}
