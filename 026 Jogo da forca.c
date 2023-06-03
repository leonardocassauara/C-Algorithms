# include <stdio.h>
# include <stdlib.h>
# include <locale.h>

// Jogo da forca: pedir uma palavra de no máximo 5 caracteres. O jogador tem 10 tentativas.
// Abstração:	1. Pedir uma string de até 5 caracteres
//				2. Pedir uma letra ao usuário
//				3. Caso a letra esteja na string, mostrar letra na sequência e reduzir tentativa em 1*
//					3.1. Checar se a letra aparece mais de uma vez numa mesma palavra
 
//				4. Caso a letra não esteja na string, reduzir tentativa em 1
//				5. Quando tentativa chegar a 0, finalizar jogo como derrota e mostrar string ao usuário
//				6. Quando as strings da palavra terminarem, finalizar jogo como vitória mostrando tentativas restantes

int main(){
	setlocale(LC_ALL,"portuguese");
	
	char palavra[5]="maca", status[5]="____", usuario;
	int tentativa=10, i=0, l=0;
	
	printf("\tJogo da Forca\n");
	
	while (tentativa != 0)
	{
		printf("Palavra: %s\n", status);
		printf("Qual letra? > ");
		scanf(" %c", &usuario);
		
		tentativa--;
		
		for (i; i <= 5; i++)
		{
			if (usuario == palavra[i])
			{
				status[i] = usuario;
			}
		}
		
		i = 0;
		
		for (l; l < 5; l++)
		{
			if (status[l] == '_')
			{	
				break;
			}
		}
		
		if (l == 5)
		{
			printf("\nParabéns! Você venceu!\n%s", status);
			return 0;
		}
		
		l = 0;
	}
	
	printf("\nQue pena, não foi dessa vez.\nA palavra era > %s", palavra);
	
	return 0;
}
