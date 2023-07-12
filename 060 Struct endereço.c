# include <stdio.h>
# include <string.h>

/*
	Problema: Fa�a uma struct que cont�m outra struct, e essa struct deve guardar o endere�o do usu�rio. No final, imprima os resultados
	Abstra��o:	1. Struct cep que conter� os n�meros inteiros antes e ap�s o '-'
				2. Struct dados que conter� as strings com as informa��es rua, UF, pa�s, e a struct cep
				3. Ler dados do usu�rio
				4. Imprimir resultados
*/

struct cep {
	int campo1;
	int campo2;
};

struct x {
	char rua[100];
	char UF[10];
	char pais[30];
	struct cep meu_cep;
};

int main(){
	struct x meu_end;
	printf("Digite sua rua: ");
	gets(meu_end.rua);
	fflush(stdin);
	printf("Digite sua UF: ");
	gets(meu_end.UF);
	fflush(stdin);
	printf("Digite seu pais: ");
	gets(meu_end.pais);
	printf("Digite o primeiro campo do seu CEP: ");
	scanf(" %d", &meu_end.meu_cep.campo1);
	printf("Digite o segundo campo do seu CEP: ");
	scanf(" %d", &meu_end.meu_cep.campo2);
	
	printf("%s\n%s\n%s\n%d %d", meu_end.rua, meu_end.UF, meu_end.pais, meu_end.meu_cep.campo1, meu_end.meu_cep.campo2);
	
	return 0;
}
