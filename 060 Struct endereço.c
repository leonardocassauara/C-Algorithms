# include <stdio.h>
# include <string.h>

/*
	Problema: Faça uma struct que contém outra struct, e essa struct deve guardar o endereço do usuário. No final, imprima os resultados
	Abstração:	1. Struct cep que conterá os números inteiros antes e após o '-'
				2. Struct dados que conterá as strings com as informações rua, UF, país, e a struct cep
				3. Ler dados do usuário
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
