# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/* Problema: Criar uma função fatorial para calcular o fatorial de um número qualquer
   Abstração:	1. Criar função fatorial
   					1.1. Declarar tipo da função - int fatorial
					1.2. Declarar tipo dos seus parâmetros - int num
					1.3. Declarar variáveis auxiliar necessarias
					1.4. Executar loop for para calcular o fatorial
					1.5. Retornar valor do fatorial
				2. Imprimir resultados
*/

int fatorial(int num) {
	// Calcula até 13
	int i = 1; 
	int fat=1;
	
	for (i = num; i != 0; i--)
	{
		fat = fat * i;
	}
	
	return fat;
} 

int main() {
	setlocale(LC_ALL, "portuguese");
	int valor;
	
	printf("Digite um valor para calcular seu fatorial: ");
	scanf(" %d", &valor);
	
	printf("\nO fatorial de %d é %d", valor, fatorial(valor));
	
	return 0;
}
