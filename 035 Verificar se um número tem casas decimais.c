# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

// Problema: verificar se um n�mero tem casas decimais
/* Abstra��o:	1. Ler entrada do usu�rio
				2. Atribuir essa entrada a uma vari�vel float
				3. Atribuir o valor da vari�vel float e uma vari�vel int
				4. Comparar ambos os valores num If
				5. Imprimir resultado
*/

int main() {
	setlocale(LC_ALL, "portuguese");	// Muda float de ponto para v�rgula!
	float valor_float;
	int valor_int;
	
	printf("Digite um valor: ");
	scanf(" %f", &valor_float);
	
	valor_int = valor_float;
	
	if (valor_int - valor_float == 0)
	{
		printf("\nO valor %d � inteiro", valor_int);
	}
	else
	{
		printf("\nO valor %.2f � float e tem casas decimais", valor_float);
	}
	
	return 0;
}
