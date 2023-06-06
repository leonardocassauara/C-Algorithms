# include <stdio.h>

// Função getchar()

int main() {
	char caractere;
	
	printf("Digite um caractere qualquer: \n");
	caractere = getchar();
	
	printf("O caractere digitado foi: \n\tCaractere\t: %c\n\tCodigo ASCII\t: %d", caractere, caractere);
	
	return 0;
}
