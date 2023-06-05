# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <locale.h>

// Problema: Criar um programa que utilize os comandos strcpy, strlen e strcat
// Abstração:	1. strcpy(Ctrl V, Ctrl C)
//				2. strlen(String)
//				3. strcat(String, String)
//				4. strcmp(String, String)

int main(){
	setlocale(LC_ALL,"portuguese");
	
	char str_1[50], str_2[50], str_3[100], str_4[100];
	int comparador;
	
	printf("Digite uma string: ");
	scanf(" %s", &str_1);
	
	printf("\nDigite outra string: ");
	scanf(" %s", &str_2);
	
	strcat(str_3, str_1);
	strcat(str_3, str_2);
	
	printf("\nTudo junto > %s", str_3);
	
	printf("\nO tamanho da primeira string é %d \nO tamanho da segunda string é %d \nO tamanho da string concatenada é %d", strlen(str_1), strlen(str_2), strlen(str_3));
	
	comparador = strcmp(str_1, str_2);
	
	strcpy(str_4, str_3);
	strcat(str_4, str_1);
	
	printf("\nString Original: %s \nString Copiada e modificada: %s", str_3, str_4);
	
	if (comparador == 0)
	{
		printf("\nAs duas strings digitadas são iguais!");
	}
	else
	{
		if (comparador > 0)
		{
			printf("\nA primeira string tem valor ASCII maior que a da segunda string");
		}
		else
		{
			printf("\nA primeira string tem valor ASCII menor que a da segunda string");
		}
	}
	
	return 0;
}
