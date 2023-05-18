# include <stdio.h>
# include <stdlib.h>

// Imprimir o resto da divisão entre dois inteiros sem usar o operador % (while loop & for loop)

int main(){
	int valor1, valor2, cont=1;

	while (cont==1)
	{
		printf("\nDigite um valor: ");
		scanf("%d", &valor1);
		printf("Digite mais um valor: ");
		scanf("%d", &valor2);
		
		if ((valor1 < 0) && (valor2 < 0))		// Verifica se numeros negativos
		{
			valor1 = valor1 * -1;
			valor2 = valor2 * -1;
		}
		else if ((valor1 < 0) || (valor2 < 0))
		{	
			if (valor1 < 0)
			{
				valor1 = valor1 * -1;	
			}
			else if (valor2 < 0)
			{
				valor2 = valor2 * -1;
			}
		}
		
		if (valor2 == 0)
		{
			printf("\nDenominadores nao aceitam valor 0!");
		}
		else
		{	
			for (valor1; valor1 >= valor2; valor1 = valor1 - valor2){}		// Para a = a, subtraia de a b unidades enquanto a for maior ou igual a b
			printf("\nResto: %d", valor1);
		}
		printf("\n\nQuer continuar?\nDigite 1 para SIM ou Digite 0 para NAO >  ");
		scanf("%d", &cont);
		}
		
	return 0;
}
