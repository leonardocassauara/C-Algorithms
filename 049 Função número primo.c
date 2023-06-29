# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/* Problema: Criar função que verifica se um número é primo e imprimir resultado
   Abstração:	1. Criar função primo
   					1.1. Declarar função e seu tipo
   					1.2. Declarar variaveis da função e seu tipo
   					1.3. Calcular o número de divisores do número selecionado pelo usuário
   						1.3.1. Usar loop for para divir o número por ele mesmo e por valores menores que ele até chegar a 1
   					1.4. Criar if-statement para o número de divisores obtido
   					1.5. A partir do resultado obtido, retornar se é primo ou não (print ou valor)
   				2. Criar main() que vai chamar a função primo
*/

int verificar_primo (int valor){
	int i = 0, aux, divisores=0;
	
	for (i = valor; i > 0; i--)
	{
		aux = valor % i;
		if (aux == 0)
		{
			divisores++;
		}
	}
	
	if (divisores == 2)
	{
		return printf("\nO número %d é primo", valor);
	}
	else
	{
		return printf("\nO número %d não é primo", valor);
	}
}

int main() {
	setlocale(LC_ALL, "portuguese");
	int valor_user;
	
	printf("Digite um valor inteiro para verificar se é primo: ");
	scanf(" %d", &valor_user);
	
	verificar_primo(valor_user);
	
	return 0;
}
