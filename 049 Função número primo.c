# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/* Problema: Criar fun��o que verifica se um n�mero � primo e imprimir resultado
   Abstra��o:	1. Criar fun��o primo
   					1.1. Declarar fun��o e seu tipo
   					1.2. Declarar variaveis da fun��o e seu tipo
   					1.3. Calcular o n�mero de divisores do n�mero selecionado pelo usu�rio
   						1.3.1. Usar loop for para divir o n�mero por ele mesmo e por valores menores que ele at� chegar a 1
   					1.4. Criar if-statement para o n�mero de divisores obtido
   					1.5. A partir do resultado obtido, retornar se � primo ou n�o (print ou valor)
   				2. Criar main() que vai chamar a fun��o primo
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
		return printf("\nO n�mero %d � primo", valor);
	}
	else
	{
		return printf("\nO n�mero %d n�o � primo", valor);
	}
}

int main() {
	setlocale(LC_ALL, "portuguese");
	int valor_user;
	
	printf("Digite um valor inteiro para verificar se � primo: ");
	scanf(" %d", &valor_user);
	
	verificar_primo(valor_user);
	
	return 0;
}
