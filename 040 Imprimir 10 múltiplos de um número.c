# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/* Problema: Imprimir 10 m�ltiplos de um valor dado pelo usu�rio, o primeiro m�ltiplo n�o pode ser o pr�prio n�mero
   Abstra��o:	1. Ler n�mero
   				2. Usar loop for para imprimir os m�ltiplos
*/

int main() {
	setlocale(LC_ALL, "portuguese");
	int num, i;
	
	printf("Digite um n�mero inteiro qualquer: ");
	scanf(" %d", &num);
	
	printf("\nM�ltiplos: ");
	for (i = 2; i <= 11; i++)
	{
		printf("%d ", num * i);
	}
	
	return 0;
}
