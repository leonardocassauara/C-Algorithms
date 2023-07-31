# include <stdio.h>
# include <stdlib.h>

/*
	Problema: Usuário entra com 4 valores: saldo, conta A, conta B e conta C, respectivamente. Retorne o número de contas que foram pagas.
	Abstração:
				1. Ler dados do Usuário
				2. Ordenar contas 
				3. Verificar se é possível subtrair de saldo o valor da conta
					3.1. Se sim, incrementar número de contas pagas.
				4. Imprimir resultados
*/

int main() {
	int saldo, conta1, conta2, conta3, aux, contasPagas=0;
	
	scanf("%d", &saldo);
	scanf("%d", &conta1);
	scanf("%d", &conta2);
	scanf("%d", &conta3);
	
	if (conta1 > conta2) {
		aux = conta2;
		conta2 = conta1;
		conta1 = aux;
	}
	if (conta1 > conta3) {
		aux = conta3;
		conta3 = conta1;
		conta1 = aux;
	}
	if (conta2 > conta3) {
		aux = conta3;
		conta3 = conta2;
		conta2 = aux;
	}
	
	if (saldo - conta1 >= 0) {
		saldo = saldo - conta1;
		contasPagas++;
	}
	if (saldo - conta2 >= 0) {
		saldo = saldo - conta2;
		contasPagas++;
	}
	if (saldo - conta3 >= 0) {
		saldo = saldo - conta3;
		contasPagas++;
	}
	
	printf("%d", contasPagas);
	return 0;
}
