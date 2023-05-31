# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

// Verificar se um número é perfeito, isso é, a soma dos seus divisores menos o próprio número resulta no próprio número

int main(){
	int numero, divisores=0, aux;
	char continuar='S';
	
	setlocale(LC_ALL, "portuguese"); 	// Acentuação em português
	
	while (continuar == 'S')
	{
		printf("\nDigite um valor: ");
		scanf("%d", &numero);
		
		if (numero == 0)
		{
			printf("\n0 não tem divisores");
			continue;
		}
		else if (numero < 0)
		{
			printf("\nNão trabalhamos com valores negativos");
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
			printf("\nO número %d é perfeito", numero);
		}
		else
		{
			printf("\nO número %d não é perfeito", numero);
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
