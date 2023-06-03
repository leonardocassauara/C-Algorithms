# include <stdio.h>
# include <stdlib.h>
# include <locale.h>
# include <string.h>

// Exemplo do Strcpy e Strlen

int main(){
	setlocale(LC_ALL,"portuguese");
	
	char frase[30], usuario[30];
	int tamanho;
	
	printf("\nDigite uma frase > ");
	scanf(" %s", &usuario);
	
	strcpy(frase, usuario);
	
	tamanho = strlen(frase);
	
	printf("\nA sua frase tem %d caracteres", tamanho);
	
	return 0;
}
