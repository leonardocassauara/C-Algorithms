# include <stdio.h>
# include <stdlib.h>

// Calculadora: soma, subtração, multiplicação e divisão
// Abstração:	1. Escolha do primeiro valor
//				2. Escolha da operação
//				3. Escolha do segundo valor
//				4. Switch case com os operadores

int main () {
	float valor_1, valor_2, operacao;
	char operador;
	
	printf("\tCalculadora\n");
	
	scanf(" %f", &valor_1);
	scanf(" %c", &operador);
	scanf(" %f", &valor_2);
	
	switch (operador)
	{
		case ('+'):
			operacao = valor_1 + valor_2;
			break;
		case ('-'):
			operacao = valor_1 - valor_2;
			break;
		case ('/'):
			operacao = valor_1 / valor_2;
			break;
		case ('*'):
			operacao = valor_1 * valor_2;
			break;
		default:
			printf("Os valores digitados foram %f e %f \n", valor_1, valor_2);
	}
	
	printf("Resultado: %.2f\n", operacao);
	
	return 0;
}
