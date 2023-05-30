# include <stdio.h>
# include <stdlib.h>

// Imprimir a tabuada do 5 (while loop)

int main(){
	int contador = 0;	

	while (contador != 11)
	{
		printf("\n5 x %d = %d", contador, contador * 5);
		contador++;
	}
	
	return 0;
}
