# include <stdio.h>

/*
	Problema: Calcule o fatorial de forma recursiva
	Abstração:	1. Declarar função calcularFatorial
					1.1. double calcularFatorial (int numero) {
								if (numero == 1) {
									return 1;
								}
								else {
									return n * calcularFatorial(n - 1);
								}
						}
				2. Ler valor do usuário
				3. Chamar a função uma vez com esse valor
				4. Imprimir resultado
*/

double calcularFatorial (int numero) {
	if (numero == 1) {
		return 1;
	}
	else {
		return numero * calcularFatorial(numero - 1);
	}
}

int main() {
	int numero;
	double fat;
	
	printf("Digite um numero para calcular o seu fatorial: ");
	scanf(" %d", &numero);
	
	fat = calcularFatorial(numero);
	
	printf("O fatorial de %d eh %.0f", numero, fat);
	
	return 0;
}
