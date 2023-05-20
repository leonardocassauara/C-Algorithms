# include <stdio.h>
# include <stdlib.h>

// Imprimir a tabuada de um número informado pelo usuário (while loop)

int main(){
	int valor, contador=0;
	
	printf("Digite um valor para consultar sua tabuada: ");
	scanf("%d", &valor);
	
	while(contador != 11)
	{
		printf("\n%d x %d = %d", valor, contador, contador * valor);
		contador++;
	}
	
	return 0;
}

