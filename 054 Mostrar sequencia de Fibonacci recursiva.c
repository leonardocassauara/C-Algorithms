# include <stdio.h>

/*
	Problema: mostre a sequência de Fibonaci de forma recursiva
	Abstração:	1. Declarar função mostrarSequencia (numeroDeTermos)
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
				2. Ler valor do usuário
				3. Chamar função
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
