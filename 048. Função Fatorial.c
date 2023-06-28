# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/* Problema: Criar uma fun��o fatorial para calcular o fatorial de um n�mero qualquer
   Abstra��o:	1. Criar fun��o fatorial
   					1.1. Declarar tipo da fun��o - int fatorial
					1.2. Declarar tipo dos seus par�metros - int num
					1.3. Declarar vari�veis auxiliar necessarias
					1.4. Executar loop for para calcular o fatorial
					1.5. Retornar valor do fatorial
				2. Imprimir resultados
*/

int fatorial(int num) {
	// Calcula at� 13
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
	
	printf("\nO fatorial de %d � %d", valor, fatorial(valor));
	
	return 0;
}
