# include <stdio.h>
# include <stdlib.h>

// Enunciado: Padaria do seu Joao.Seu João tem uma padaria e precisa saber de algumas informações. Ele sabe que em uma fornada, dá pra fazer 120 pães franceses. Ele cobra cada pãozinho 0,45 centavos. 
//			  Por dia, 3 fornadas são tiradas e vendidas. Seu João sabe que cada pãozinho tem um custo de 0,10 centavos para ser produzido. O padeiro recebe por mês 400 reais. 
//     		  Sabendo destas informações, deseja-se saber qual o lucro, no fim do mês do Seu João.

int main() {
	int num_fornadas, dia, num_pao, recebe;
	float valor_pao, custo_pao, lucro;
	dia = 30;
	num_fornadas = 3 * dia;
	num_pao = num_fornadas * 120;
	valor_pao = 0.45;
	custo_pao = 0.10;
	recebe = 400;
	lucro = num_pao * (valor_pao - custo_pao) + recebe;
	printf("Ao preparar %d fornadas e %d paes, vendendo R$%.2f a unidade a um custo de R$%.2f, mais um acrescimo de R$%d \nA receita no final do mes sera de R$%.2f", num_fornadas, num_pao, valor_pao, custo_pao, recebe, lucro);
	return 0;
}
