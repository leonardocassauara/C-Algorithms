# include <stdio.h>
# include <string.h>


void imprimirVetor (int n, char* vetor[], char* entrada) {
	int i;
	
	printf("Palavras menores: \t\t");
	for (i = 0; i < n; i++) {
		if (strlen(vetor[i]) < strlen(entrada)) {
			printf("%s ", vetor[i]);
		}
	}
	
	printf("\nPalavras de mesmo tamanho: \t");	
	for (i = 0; i < n; i++) {
		if (strlen(vetor[i]) == strlen(entrada)) {
			printf("%s ", vetor[i]);
		}
	}

	printf("\nPalavras maiores: \t\t");
	for (i = 0; i < n; i++) {
		if (strlen(vetor[i]) > strlen(entrada)) {
			printf("%s ", vetor[i]);
		}
	}
}


int main() {
	const char* p = "camelo";
	const char* nomes[] = {"galinha", "golfinho", "carpa", "tartaruga", "cavalo", "chita", "mosquito", "elefante", "panda", "bode"};
	imprimirVetor(10, nomes, p);
	return 0;
}
