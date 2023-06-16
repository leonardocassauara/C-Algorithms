# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/* Problema: Criar uma caixa registradora eficiente para as notas 200, 100, 50, 20, 10, 5, 2, 1
   Abstração:	1. Ler a quantia que será sacada
   				2. Separar a parte inteira da decimal (centavos) para imprimir os centavos
   				3. Utilizar vários while loops para representar cada nota de forma decrescente decrescendo o valor a ciclo
   				4. A cada decrescimento, incrementar o tipo do decrescimento
   				5. Imprimir resultado
*/

int main() {
	setlocale(LC_ALL, "portuguese");
	int valor_int, nota_200=0, nota_100=0, nota_50=0, nota_20=0, nota_10=0, nota_5=0, nota_2=0, nota_1=0;
	float valor_inicial, valor_float;
	
	do {	// Formatação do valor
		printf("Digite o valor que será sacado: R$\n");
		scanf(" %f", &valor_float);
	} while (valor_float < 0);
	
	valor_inicial = valor_float;
	valor_int = valor_float;			    // Inteira
	valor_float = valor_float - valor_int; // Centavos
	
	while (valor_int >= 200)
	{
		nota_200++;
		valor_int = valor_int - 200;

	}	
	
	while (valor_int >= 100)
	{
		nota_100++;
		valor_int = valor_int - 100;
	}
	
	while (valor_int >= 50)
	{
		nota_50++;
		valor_int = valor_int - 50;
	}
	
	while (valor_int >= 20)
	{
		nota_20++;
		valor_int = valor_int - 20;
	}
	
	while (valor_int >= 10)
	{
		nota_10++;
		valor_int = valor_int - 10;
	}
	
	while (valor_int >= 5)
	{
		nota_5++;
		valor_int = valor_int - 5;
	}
	
	while (valor_int >= 2)
	{
		nota_2++;
		valor_int = valor_int - 2;
	}
	
	while (valor_int >= 1)
	{
		nota_1++;
		valor_int = valor_int - 1;
	}
	
	printf("\n R$%.2f = \n %d notas de R$200\n %d notas de R$100\n %d notas de R$50\n %d notas de R$20\n %d notas de R$10\n %d notas de R$5\n %d notas de R$2\n %d notas de R$1\n + R$%.2f centavos", valor_inicial, nota_200, nota_100, nota_50, nota_20, nota_10, nota_5, nota_2, nota_1, valor_float);

	return 0;
}
