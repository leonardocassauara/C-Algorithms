# include <stdio.h>
# include <locale.h>

/*
	Problema: Ler um conjunto de números inteiros do usuário e somar todos os números que podem ser expressos como produtos de dois números primos.
	Abstração:	1. Função para ler quantos valores serão lidos
				2. Função para ler a quantidade de valores determinada
				3. Função para verificar se um número é primo
				4. Função para verificar se um número é produto de dois primos
				5. Função para somar valores
*/

int lerQuantidadeDeValores() {
	int valores;
	
	printf("Quantos valores serão lidos? ");
	scanf(" %d", &valores);
	
	return valores;
}

void lerValores(int numeroDeValores, int vetor[]) {
	int i, numero;
	for (i = 0; i < numeroDeValores; i++) {
		printf("\nDigite um valor: ");
		scanf(" %d", &numero);
		vetor[i] = numero;
	}
}

int verificarNumeroPrimo(int numero) {
	int aux = numero, i, divisores = 0;
	
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

void verificarNumeroProdutoDeDoisPrimos(int numero, int vetor[]) {
	int aux=numero, i=0;
	while (aux != 0) {
		if ((numero % aux == 0) && (verificarNumeroPrimo(aux)))
		{
			if (i != 2) {
				vetor[i] = aux;
				i++;	
			}
		}
		aux--;
	}
}

int somarValores(int a, int b) {
	return a + b;
}

int main() {
	setlocale(LC_ALL, "portuguese");
	int vetor[2], numero, numValores, i, acumulador=0;
	
	numValores = lerQuantidadeDeValores();
	int valores[numValores];
	
	lerValores(numValores, valores);
	for (i = 0; i < numValores; i++)
	{
		verificarNumeroProdutoDeDoisPrimos(valores[i], vetor);
		if (vetor[0] * vetor[1] == valores[i]) {
			acumulador = somarValores(acumulador, valores[i]);
		}		
	}
	printf("\n%d", acumulador);
	
	return 0;
}
