# include <stdio.h>
# include <stdlib.h>

// Imprimir o produto de um numero por 5 sem usar o operador * (while loop)

int main(){
	int valor, contador=1, inicio;
	
	printf("Digite um valor: ");
	scanf("%d", &valor);
	inicio = valor;
	
	while (contador != 5)
	{
		contador++;
		valor = valor + inicio;
	}
	
	printf("O valor %d multiplicado por 5 e igual a %d", inicio, valor);
	
	return 0;
}
