# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

// Problema: verificar se um número tem casas decimais
/* Abstração:	1. Ler entrada do usuário
				2. Atribuir essa entrada a uma variável float
				3. Atribuir o valor da variável float e uma variável int
				4. Comparar ambos os valores num If
				5. Imprimir resultado
*/

int main() {
	setlocale(LC_ALL, "portuguese");	// Muda float de ponto para vírgula!
	float valor_float;
	int valor_int;
	
	printf("Digite um valor: ");
	scanf(" %f", &valor_float);
	
	valor_int = valor_float;
	
	if (valor_int - valor_float == 0)
	{
		printf("\nO valor %d é inteiro", valor_int);
	}
	else
	{
		printf("\nO valor %.2f é float e tem casas decimais", valor_float);
	}
	
	return 0;
}
