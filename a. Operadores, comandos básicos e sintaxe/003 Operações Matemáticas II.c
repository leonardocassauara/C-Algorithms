# include <stdio.h>
# include <stdlib.h>

// Enunciado: Padaria do seu Joao. Seu Jo�o tem uma padaria e precisa saber de algumas informa��es. Ele sabe que em uma fornada, d� pra fazer 120 p�es franceses. 
// 			  Ele cobra cada p�ozinho 0,45 centavos. Por dia, 3 fornadas s�o tiradas e vendidas. Seu Jo�o sabe que cada p�ozinho tem um custo de 0,10 centavos para ser produzido. 
//            Sabendo destas informa��es, deseja-se saber qual o lucro, no fim do dia do Seu Jo�o.

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
