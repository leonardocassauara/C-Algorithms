# include <stdio.h>
# include <stdlib.h>

// Ler um inteiro e imprimir o seu dobro

int main(){
	int num, dobro;
	
	printf("Digite um numero: ");
	scanf("%d", &num);
	
	dobro = num * 2;
	
	printf("\nO dobro de %d vale: %d", num, dobro);
	
	return 0;
}
