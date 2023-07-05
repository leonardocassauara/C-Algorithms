# include <stdio.h>

/*
	Problema: mostre a sequ�ncia de Fibonaci de forma recursiva
	Abstra��o:	1. Declarar fun��o mostrarSequencia (numeroDeTermos)
					1.1.) int calcularTermoDaSequencia (int numeroDeTermos)
								if (numeroDeTermos == 1) {
									return 1;
								}
								else {
									if (numeroDeTermos == 2) {
										return 1;
									}
									else {
										return (calcularTermoDaSequencia(numeroDeTermos - 1) + calcularTermoDaSequencia(numeroDeTermos - 2);
									}
							}
				2. Ler valor do usu�rio
				3. Chamar fun��o
				4. Imprimir resultado
*/

int calcularTermoDaSequencia(int numeroDeTermos) {
	if (numeroDeTermos == 1) {
		return 1;
	}
	else {
		if (numeroDeTermos == 2)
		{
			return 1;
		}
		else {
			return (calcularTermoDaSequencia(numeroDeTermos - 1) + calcularTermoDaSequencia(numeroDeTermos - 2));
		}
	}
}

int main() {
	int numero, i;
	
	printf("Quantos termos da sequenia de Fibonacci voce quer ver? ");
	scanf(" %d", &numero);
	
	for (i = 1; i <= numero; i++)
	{
		printf("%d ", calcularTermoDaSequencia(i));
	}
	
	return 0;
}
