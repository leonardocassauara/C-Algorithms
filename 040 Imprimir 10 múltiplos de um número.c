# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/* Problema: Imprimir 10 múltiplos de um valor dado pelo usuário, o primeiro múltiplo não pode ser o próprio número
   Abstração:	1. Ler número
   				2. Usar loop for para imprimir os múltiplos
*/

int main() {
	setlocale(LC_ALL, "portuguese");
	int num, i;
	
	printf("Digite um número inteiro qualquer: ");
	scanf(" %d", &num);
	
	printf("\nMúltiplos: ");
	for (i = 2; i <= 11; i++)
	{
		printf("%d ", num * i);
	}
	
	return 0;
}
