# include <stdio.h>
# include <stdlib.h>

// Enunciado: Padaria do seu Joao. Seu João tem uma padaria e precisa saber de algumas informações. Ele sabe que em uma fornada, dá pra fazer 120 pães franceses. 
// 			  Ele cobra cada pãozinho 0,45 centavos. Por dia, 3 fornadas são tiradas e vendidas. Seu João sabe que cada pãozinho tem um custo de 0,10 centavos para ser produzido. 
//            Sabendo destas informações, deseja-se saber qual o lucro, no fim do dia do Seu João.

int main() {
	int num_fornada, num_pao, dia;
	float valor_pao, custo_pao, lucro;
	dia = 1;
	num_fornada = 3 * dia;
	num_pao = 120 * num_fornada;
	valor_pao = 0.45;
	custo_pao = 0.10;
	lucro = (num_pao * valor_pao) - (num_pao * custo_pao); // == num_pao(valor_pao - custo_pao)
	printf("\nAo preparar %d fornadas e %d paes, ao vender cada unidade por R$%.2f a um custo de producao de R$%.2f, \no lucro sera de R$%.2f", num_fornada, num_pao, valor_pao, custo_pao, lucro);
	return 0;
}
