# include <stdio.h>
# include <stdlib.h>

// Enunciado: Padaria do seu Joao.Seu Jo�o tem uma padaria e precisa saber de algumas informa��es. Ele sabe que em uma fornada, d� pra fazer 120 p�es franceses. Ele cobra cada p�ozinho 0,45 centavos. 
//			  Por dia, 3 fornadas s�o tiradas e vendidas. Seu Jo�o sabe que cada p�ozinho tem um custo de 0,10 centavos para ser produzido. O padeiro recebe por m�s 400 reais. 
//     		  Sabendo destas informa��es, deseja-se saber qual o lucro, no fim do m�s do Seu Jo�o.

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
