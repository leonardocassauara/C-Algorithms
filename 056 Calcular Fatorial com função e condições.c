# include <stdio.h>
# include <locale.h>

/*
	Problema: Crie um programa em C que leia um numero e com base nas condições desse número, calcular o seu fatorial ou não
	Abstração:	1. Função para ler um número do usuário
				2. Função para calcular fatorial do usuário
				3. Escrever as condições no int main
					3.1. par, ímpar, primo, múltiplo de 5
				4. Imprimir resultado;
*/

int lerNumero() {
	int numero;
	printf("Digite um número: ");
	scanf(" %d", &numero);
	
	return numero;
}

double calcularFatorial(int numero) {
	if (numero <= 1) {
		return 1;
	}
	else {
		return numero * calcularFatorial (numero - 1);
	}
}

int verificarNumeroPrimo (int numero) {
	int aux = numero, divisores=0;
	while (aux != 0) {
		if (numero % aux == 0) {
			divisores++;
		}
		aux--;
	}
	if (divisores == 2) {
		return 1;
	}
	else {
		return 0;
	}
}

int main() {
	setlocale(LC_ALL, "portuguese");
	
	int numero;
	double fat=0;
	
	numero = lerNumero();
	

	if (numero % 5 == 0) {
		fat = calcularFatorial(numero);
	}

	
	/*
	if (verificarNumeroPrimo(numero)) {
		fat = calcularFatorial(numero);
	}
	*/
	
	/*
	if (numero % 2 == 0) {
		fat = calcularFatorial(numero);
	} 
	*/
	
	/*
	if (numero % 2 != 0) {
		fat = calcularFatorial(numero);
	} 
	*/
	
	printf("%0.f", fat);
	
	return 0;
}
