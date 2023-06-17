# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/* Problema: Imprimir as duas prestações e a entrada de uma mercadoria sobre a seguinte regra -> Entrada >= Prestação
   Abstração:	1. Ler valor da mercadoria;
   				2. Calcular valor máximo de cada prestação = mercadoria / 3;
   				3. Ler entrada que deve obedecer as seguintes condições -> Mercadoria >= Entrada >= Max_prestação
   				4. Calcular o valor de cada parcela = (Mercadoria - Entrada) / 2;
   				5. Imprimir Resultado
*/

int main() {
	float mercadoria, max_prestacao, entrada, prestacao;
	
	do {
		printf("\nDigite o valor da mercadoria: R$");
		scanf(" %f", &mercadoria);
	} while (mercadoria < 0);
	
	do {
		max_prestacao = mercadoria / 3;
		printf("\nDigite o valor da entrada: R$");
		scanf(" %f", &entrada);
	} while ((mercadoria < entrada) || (entrada < max_prestacao)); // Erro
	
	if (entrada == mercadoria)
	{
		prestacao = 0;
	}
	else
	{
		prestacao = (mercadoria - entrada) / 2;
	}
	
	printf("\nPara uma mercadoria de R$%.2f temos: \n Entrada de R$%.2f\n Duas parcelas de R$%.2f", mercadoria, entrada, prestacao);
	
	return 0;
}
