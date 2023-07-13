# include <stdio.h>

/*
	Problema: Crie uma fun��o que recebe 5 numeros inteiros como par�metros e retorne um n�mero formado pela unidade dos n�meros recebidos
		1. A unidade de um n�mero inteiro pode ser representada pelo resto da divis�o do numero por 10
		2. Como s�o 5 n�meros, ser� necess�rio orden�-los conforme foram passados multiplicando-os por pot�ncias de 10
		3. Imprimir resultados
*/

int concatenarUltimosDigitosDeCincoNumeros (int a, int b, int c, int d, int e) {
	a = (a % 10) * 10000;
	b = (b % 10) * 1000;
	c = (c % 10) * 100;
	d = (d % 10) * 10;
	e = (e % 10) * 1;
	
	return a + b + c + d + e;
}

int main () {
	int a, b, c, d, e;
	int novoNumero;
	
	printf("Digite um n�mero inteiro: ");
	scanf(" %d", &a);
	printf("\nDigite um n�mero inteiro: ");
	scanf(" %d", &b);
	printf("\nDigite um n�mero inteiro: ");
	scanf(" %d", &c);
	printf("\nDigite um n�mero inteiro: ");
	scanf(" %d", &d);
	printf("\nDigite um n�mero inteiro: ");
	scanf(" %d", &e);
	
	novoNumero = concatenarUltimosDigitosDeCincoNumeros (a, b, c, d, e);
	
	printf("\n%d", novoNumero);
	
	return 0;
}
