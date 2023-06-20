# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/* Problema: Imprimir matriz 3x3 de valores digitados pelo usuário
   Abstração:	1. Utilizar loop for dentro de outro loop for para ler as linhas e colunas
   				2. Utilizar a mesma lógica para imprimir a matriz
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
			printf("[%d]\t", matriz[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
