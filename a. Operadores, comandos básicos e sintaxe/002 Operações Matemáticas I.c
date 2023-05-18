# include <stdio.h>
# include <stdlib.h>

// Enunciado: Padaria do seu Joao. Seu João tem uma padaria e precisa saber de algumas informações. 
// 			  Ele sabe que em uma fornada, dá pra fazer 120 pães franceses. Ele cobra cada pãozinho 0,45 centavos. 
//			  Por dia, 3 fornadas são tiradas e vendidas. Deseja-sesaber qual o lucro, no fim do dia do Seu João.

int main() {
	int fornada, dia;
	float valor_pao, num_paes, lucro;
	dia = 1;
	fornada = 3 * dia;
	num_paes = fornada * 120;
	valor_pao = 0.45;
	lucro = valor_pao * num_paes;
	printf("Apos preparar %d fornadas e %.0f paes, ao vender todos eles do lucro sera de R$%.2f", fornada, num_paes, lucro);
	return 0;
}
