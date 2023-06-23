# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/* Problema: Imprimir diagonal principal e secundária da matriz 3x3 de valores digitados pelo usuário
   Abstração:	1. Utilizar loop for dentro de outro loop for para ler as linhas e colunas
   				2. Utilizar a mesma lógica para imprimir a diagonal principal da matriz
   				3. Usando if-statement em que i + j == 2 (numero de linhas ou colunas - 1) ou i == j
*/

int main(){
	setlocale(LC_ALL, "portuguese");
	
	int matriz[3][3], i, j;
	
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("Digite um valor para a posição (%d, %d): \n", i, j);
			scanf(" %d", &matriz[i][j]);
		}
	}
	
	printf("\n");
	
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{	
			if ((i + j == 2) || (i == j))
			{
				printf("[%d]\t", matriz[i][j]);	
			}
			else
			{
				printf("\t");
			}
		}
		printf("\n");
	}
	
	return 0;
}
