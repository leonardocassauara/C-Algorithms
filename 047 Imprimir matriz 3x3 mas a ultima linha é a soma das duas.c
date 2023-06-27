# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/* Problema: Imprimir uma matriz 3x3, em em que os elementos das duas primeiras linhas são dados pelo usuário, e a última linha é a soma das outras duas
   Abstração:	1. Ler os valores da matriz 3x3 usando a lógica do loop foor
   					1.1. for (roda 2 vezes) -- 2 linhas
   					1.2.	for (roda 3 vezes) -- 3 colunas
   				2. Fazer a lógica para somar os valores de cada linha
   					2.1. soma = soma + m[j][i]
   				3. Imprimir a nova matriz
*/

int main() {
    setlocale(LC_ALL, "portuguese");
	int m[3][3], i=0, j=0, soma=0;
    
    for (i=0; i<2; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("Digite um valor para a posiçao (%d, %d): \n", i, j);
            scanf(" %d", &m[i][j]);
        }
    }
    
    for (i = 0; i<3; i++)
    {
    	m[2][i] = 0;
	}
    
    printf("Matriz:\n");
    
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    
    for (i=0; i<3; i++)
    {
    	for (j=0; j<3; j++)
    	{
    		soma = soma + m[j][i];
		}
		m[2][i] = soma;
		soma = 0;
    }
    
    printf("Nova Matriz:\n");
    
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("%d\t", m[i][j]);
        }
        printf("\n");
        
	}
    
    return 0;
}
