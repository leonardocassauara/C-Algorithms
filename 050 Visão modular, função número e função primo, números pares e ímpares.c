# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/* Problema: Criar ou Importar fun��o primo e fun��o fatorial. Se o usu�rio digitar um valor par, calcular o fatorial desse valor, se n�o verificar se � primo
	 Abstra��o:	1. Criar ou Importar as fun��es requisitadas
						    1.1. fatorial(num)
								1.2. primo(num)
							2. Fazer programa main() para ler um valor do usu�rio e compar�-lo num if-statement
								2.1. Se o valor for par, ent�o calcular seu fatorial
								2.2. Se o valor for �mpar, ent�o verificar se � primo
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
		return printf("\nO valor %d � primo", num);
	}
	else
	{
		return printf("\nO valor %d n�o � primo", num);
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
