# include <stdio.h>
# include <stdlib.h>

// Media aritm�tica das notas (If statement)

int main(){
	float nota1, nota2, media;
	
	printf("Digite o valor da primeira nota: ");
	scanf("%f", &nota1);
	printf("\nDigite o valor da segunda nota: ");
	scanf("%f", &nota2);
	
	media = (nota1 + nota2) / 2;
	
	printf("\nMedia: %.2f", media);
	
	return 0;
}
