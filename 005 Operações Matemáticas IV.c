# include <stdio.h>
# include <stdlib.h>

// Enunciado: Padaria do seu Joao. Seu Jo�o tem uma padaria e precisa saber de algumas informa��es. Ele sabe que em uma fornada, d� pra fazer 120 p�es franceses. Ele cobra cada p�ozinho 0,45 centavos. 
//            Por dia, 3 fornadas s�o tiradas e vendidas. Seu Jo�o sabe que cada p�ozinho tem um custo de 0,10 centavos para ser produzido. O padeiro recebe por m�s 400 reais. 
//            Sabendo destas informa��es, deseja-se saber quantos p�es seu Joao deve vender para ter um lucro l�quido de R$ 1500,00 reais ao final do m�s.

int main() {
	int dia = 30, num_paes, recebe=400, lucro=1500;
	float valor_pao=0.45, custo_pao=0.10, lucro_pao;
	lucro_pao = valor_pao - custo_pao;
	num_paes = (lucro - recebe) / lucro_pao;
	printf("Para obter uma receita mensal liquida de R$1500 com um rendimento fixo de R$400, \nJoao tera de preparar e vender %d paes equivalente a R$1100 em vendas", num_paes);
	return 0;
}
