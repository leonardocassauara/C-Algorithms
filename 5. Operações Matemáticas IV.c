# include <stdio.h>
# include <stdlib.h>

// Enunciado: Padaria do seu Joao. Seu João tem uma padaria e precisa saber de algumas informações. Ele sabe que em uma fornada, dá pra fazer 120 pães franceses. Ele cobra cada pãozinho 0,45 centavos. 
//            Por dia, 3 fornadas são tiradas e vendidas. Seu João sabe que cada pãozinho tem um custo de 0,10 centavos para ser produzido. O padeiro recebe por mês 400 reais. 
//            Sabendo destas informações, deseja-se saber quantos pães seu Joao deve vender para ter um lucro líquido de R$ 1500,00 reais ao final do mês.

int main() {
	int dia = 30, num_paes, recebe=400, lucro=1500;
	float valor_pao=0.45, custo_pao=0.10, lucro_pao;
	lucro_pao = valor_pao - custo_pao;
	num_paes = (lucro - recebe) / lucro_pao;
	printf("Para obter uma receita mensal liquida de R$1500 com um rendimento fixo de R$400, \nJoao tera de preparar e vender %d paes equivalente a R$1100 em vendas", num_paes);
	return 0;
}
