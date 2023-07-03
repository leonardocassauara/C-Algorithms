# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/*	Problema: Criar fun��o que recebe uma matriz quadrada como par�metro e calcule a soma das suas linhas
	Abstra��o:	1. Declarar tipo e nome da fun��o
					1.1. int soma_linha
				2. Declarar tipo e nome dos par�metros
					2.1. int matriz[][n], int vetor[n]
				3. Utilizar um loop for para preencher o vetor inteiro com 0
				4. Utilizar um loop for para somar as linhas e atribu�-las ao vetor
				5. A fun��o ir� retornar o vetor, mas sem usar o return
				6. Chamar a fun��o no main
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
	
	printf("Qual ser� o tamanho da matriz quadrada? ");
	scanf(" %d", &tam);
	printf("\n");
	
	int grid[tam][tam], vet[tam];
	
	for (i = 0; i < tam; i++)
	{
		for (j = 0; j < tam; j++)
		{
			printf("Digite um valor para a posi��o (%d, %d): ", i, j);
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
