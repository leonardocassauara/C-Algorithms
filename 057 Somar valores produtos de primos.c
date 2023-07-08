# include <stdio.h>
# include <locale.h>

/*
	Problema: Ler um conjunto de n�meros inteiros do usu�rio e somar todos os n�meros que podem ser expressos como produtos de dois n�meros primos.
	Abstra��o:	1. Fun��o para ler quantos valores ser�o lidos
				2. Fun��o para ler a quantidade de valores determinada
				3. Fun��o para verificar se um n�mero � primo
				4. Fun��o para verificar se um n�mero � produto de dois primos
				5. Fun��o para somar valores
*/

int lerQuantidadeDeValores() {
	int valores;
	
	printf("Quantos valores ser�o lidos? ");
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
