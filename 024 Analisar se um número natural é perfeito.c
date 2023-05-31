# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

// Verificar se um n�mero � perfeito, isso �, a soma dos seus divisores menos o pr�prio n�mero resulta no pr�prio n�mero

int main(){
	int numero, divisores=0, aux;
	char continuar='S';
	
	setlocale(LC_ALL, "portuguese"); 	// Acentua��o em portugu�s
	
	while (continuar == 'S')
	{
		printf("\nDigite um valor: ");
		scanf("%d", &numero);
		
		if (numero == 0)
		{
			printf("\n0 n�o tem divisores");
			continue;
		}
		else if (numero < 0)
		{
			printf("\nN�o trabalhamos com valores negativos");
			continue;
		}
		else
		{
			aux = numero - 1;
			for (numero; aux >= 1; aux--)
			{
				if (numero % aux == 0)
				{
					divisores = divisores + aux;
				}
			}
		}
		
		if (divisores == numero)
		{
			printf("\nO n�mero %d � perfeito", numero);
		}
		else
		{
			printf("\nO n�mero %d n�o � perfeito", numero);
		}
		divisores = 0;
		
		do
		{
			printf("\nQuer continuar? Digite 'S' para continuar ou 'N' para sair: ");
			scanf(" %c", &continuar);
		} while ((continuar != 'S') && (continuar != 'N'));
	}
	
	return 0;
}
