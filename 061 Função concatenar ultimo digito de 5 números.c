# include <stdio.h>

/*
	Problema: Crie uma função que recebe 5 numeros inteiros como parâmetros e retorne um número formado pela unidade dos números recebidos
		1. A unidade de um número inteiro pode ser representada pelo resto da divisão do numero por 10
		2. Como são 5 números, será necessário ordená-los conforme foram passados multiplicando-os por potências de 10
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
	
	printf("Digite um número inteiro: ");
	scanf(" %d", &a);
	printf("\nDigite um número inteiro: ");
	scanf(" %d", &b);
	printf("\nDigite um número inteiro: ");
	scanf(" %d", &c);
	printf("\nDigite um número inteiro: ");
	scanf(" %d", &d);
	printf("\nDigite um número inteiro: ");
	scanf(" %d", &e);
	
	novoNumero = concatenarUltimosDigitosDeCincoNumeros (a, b, c, d, e);
	
	printf("\n%d", novoNumero);
	
	return 0;
}
