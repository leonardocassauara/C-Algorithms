# include <stdio.h>
# include <locale.h>

/*
	Problema: Crie um programa em C que leia um numero e com base nas condi��es desse n�mero, calcular o seu fatorial ou n�o
	Abstra��o:	1. Fun��o para ler um n�mero do usu�rio
				2. Fun��o para calcular fatorial do usu�rio
				3. Escrever as condi��es no int main
					3.1. par, �mpar, primo, m�ltiplo de 5
				4. Imprimir resultado;
*/

int lerNumero() {
	int numero;
	printf("Digite um n�mero: ");
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
