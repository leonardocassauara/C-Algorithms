# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/* Problema: Imprimir as duas presta��es e a entrada de uma mercadoria sobre a seguinte regra -> Entrada >= Presta��o
   Abstra��o:	1. Ler valor da mercadoria;
   				2. Calcular valor m�ximo de cada presta��o = mercadoria / 3;
   				3. Ler entrada que deve obedecer as seguintes condi��es -> Mercadoria >= Entrada >= Max_presta��o
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
