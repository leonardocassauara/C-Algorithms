# include <stdio.h>

// String

int main() {
	char str[100];
	int i;
	
	printf("Digite uma frase qualquer > ");
	gets(str);
	
	for (i=0; str[i] != '\0'; i++)
	{
		printf("\nCaractere %d\t: %c", i, str[i]);
	}
	
	return 0;
}
