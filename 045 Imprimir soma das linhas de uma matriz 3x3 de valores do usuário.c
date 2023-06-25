# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/* Problema: Imprimir a soma das linhas de uma matriz 3x3 de valores do usuário
   Abstração:	1. Ler os valores da matriz usando a lógica do loop for
   				2. Imprimir a matriz usando a lógica do loop for
   				3. Fazer a soma das linhas da matriz somando todos os valores da linha, imprimindo-o e resetando o seu valor logo depois
*/

int main() {
    setlocale(LC_ALL, "portuguese");
	int m[3][3], i=0, j=0, soma=0;
    
    for (i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("Digite um valor para a posiçao (%d, %d): \n", i, j);
            scanf(" %d", &m[i][j]);
        }
    }
    
    printf("Matriz:\n");
    
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            printf("[%d]\t", m[i][j]);
        }
        printf("\n");
    }
    
    printf("Soma das linhas:\n");
    
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            soma = soma + m[i][j];
        }
        printf("[%d]\n", soma);
        soma = 0;
    }
    
    return 0;
}
