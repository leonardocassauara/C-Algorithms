# include <stdio.h>

int main(){
	char str[100];
	
	printf("\nDigite uma frase qualquer: ");
	gets(str);
	
	printf("\nA frase digitada foi > %s", str);
	
	return 0;
}
