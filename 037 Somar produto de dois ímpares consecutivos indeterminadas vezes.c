# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

/* Problema: Fa�a um algoritmo que leia dois numeros inteiros enquanto os n�meros forem diferentes de 0. Esses numeros devem ser �mpares. Se forem �mpares consecutivos, multiplique-os. Imprima a soma das multiplica��es
   Abstra��o:	1. Ler duas entradas do usu�rio
				2. Essas entradas devem ser n�meros �mpares, se n�o pede-se para repetir as entradas
				3. A leitura deve estar dentro de um loop que s� termina quando um dos valores for 0
				4. Se os dois valores forem n�meros �mpares consecutivos, multiplique os dois valores
				5. Adiciona o valor do produto obtido a soma
				6. Imprima o valor da soma quando sair do loop
*/

int main() {
	setlocale(LC_ALL, "portuguese");
	int valor_1, valor_2, soma=0, produto=0, continuar=1;
	
	while(continuar == 1)
	{
		do {
			printf("\nDigite um valor �mpar: ");
			scanf(" %d", &valor_1);
			
			printf("\nDigite mais um valor �mpar: ");
			scanf(" %d", &valor_2);
	    } while ((valor_1 % 2 == 0) || (valor_2 % 2 == 0));		// Se um valor par for digitado, ele vai pedir os dois valores novamente.
	    
	    if (valor_1 + 2 == valor_2)
	    {
	    	produto = valor_1 * valor_2;
	    	soma = soma + produto;
		}
		else if (valor_2 + 2 == valor_1)
		{
			produto = valor_1 * valor_2;
			soma = soma + produto;
		}
		
		do {
			printf("\nQuer continuar? Digite 0 para sair ou 1 para continuar: ");
			scanf(" %d", &continuar);
	    } while ((continuar != 0) && (continuar != 1));
    }
    
    printf("\nSoma dos produtos entre os n�meros �mpares consecutivos obtidos: %d", soma);
    
    return 0;
}
