# include <stdio.h>
# include <stdlib.h>
# include <locale.h>
# include <string.h>

// Problema: Vetor de n�meros inteiros, orden�-lo em valores crescentes.
/* Abstra��o:	1. Ler entradas do usu�rio que ir�o compor o vetor de 5 valores inteiros
				2. Organizar os loops for de formata��o e obten��o das entradas
				3. Fazer o loop for que ir� reordenar o vetor
					3.1. Vamos comparar se o primeiro valor � maior que o seu sucessor
					3.2. Se for maior, ent�o vamos troc�-lo de lugar e setar troca com valor 1
					3.3. Se n�o for, nada acontece
					3.4. Entretanto, se o loop for terminar com nenhuma troca, setar troca com valor 0
				4. Colocar o loop for dentro de um loop while com condi��o troca == 1
				5. Formatar mensagem de sa�da com o novo vetor
*/

int main() {
	setlocale(LC_ALL, "portuguese");
	int i=0, k=0, vetor[5], troca = 1, aux;
	
	for (i=0; i != 5; i++)
	{
		printf("Digite um valor para o vetor[%d]: ", i);
		scanf(" %d", &vetor[i]);
	}
	
	printf("\nO vetor era\t: ");
	for (i=0; i != 5; i++)
	{
		printf("%d ", vetor[i]);
	}
	
	// Ordena��o do vetor
	while (troca == 1)
	{
		troca = 0;
		
		for (i=0; i != 4; i++)
		{
			if (vetor[i] > vetor[i+1])
			{
				aux = vetor[i];
				vetor[i] = vetor[i+1];
				vetor[i+1] = aux;
				troca = 1;
			}
		}
	}
	
	printf("\nO novo vetor �\t: ");
	for (i=0; i != 5; i++)
	{
		printf("%d ", vetor[i]);
	}
	
	return 0;
}
