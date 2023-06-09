# include <stdio.h>

// Eliminando buffer de teclado para mais de 1 scanf (fflush(stdin))

int main() {
	char c1, c2;
	
	printf("Digite um caractere qualquer > ");
	scanf("%c", &c1);
	fflush(stdin);
	
	printf("\nDigite outro caractere qualquer > ");
	scanf("%c", &c2);
	
	printf("\nOs caracteres digitados foram '%c' e '%c'", c1, c2);
	
	return 0;
}
