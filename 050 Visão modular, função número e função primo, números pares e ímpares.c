# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/* Problema: Criar ou Importar função primo e função fatorial. Se o usuário digitar um valor par, calcular o fatorial desse valor, se não verificar se é primo
	 Abstração:	1. Criar ou Importar as funções requisitadas
						    1.1. fatorial(num)
								1.2. primo(num)
							2. Fazer programa main() para ler um valor do usuário e compará-lo num if-statement
								2.1. Se o valor for par, entâo calcular seu fatorial
								2.2. Se o valor for ímpar, então verificar se é primo
							3. Imprimir resultados
*/

int fatorial (int num){
	int i=1, fat=1;
	for (i = num; i > 0; i --)
	{
		fat = fat * i;
	}
	
	return fat;
}

int primo (int num){
	int i=1, divisores=0, aux;
	
	for (i = num; i > 0; i--)
	{
		aux = num % i;
		if (aux == 0)
		{
			divisores++;
		}
	}
	
	if (divisores == 2)
	{
		return printf("\nO valor %d é primo", num);
	}
	else
	{
		return printf("\nO valor %d não é primo", num);
	}
}

int main(){
	setlocale(LC_ALL, "portuguese");
	int valor_user;
	
	printf("Digite um valor inteiro qualquer: ");
	scanf(" %d", &valor_user);
	
	if (valor_user % 2 == 0)
	{
		printf("O fatorial de %d vale %d", valor_user, fatorial(valor_user));
	}
	else
	{
		primo(valor_user);
	}
	
	return 0;
}
