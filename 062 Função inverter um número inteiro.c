# include <stdio.h>

/*
	Problema: Crie uma função que inverta os algarismos de um número inteiro
	Abstração:	1. Verificar quantas casas decimais o número tem
					1.1. Dividindo-o sucessivamente por 10 (loop while) e incrementando um contador sobre a condição de ser um número maior ou igual que 0,1
						 obtemos o número de casas decimais do valor
				2. Valor da potência de 10 elevado ao numero de casas - 1 para regular os digitos do número antes da concatenação
					2.1. for (i = 1; i < casas; i++) {
							regulador = regulador * 10;  -- regulador começa em 1
						 }
				3. Obter o valor inteiro de cada digito do número, começando do último digito
					3.1. for (i = 0; i < casas; i++) {
							digitoFloat = (num % pot10) / (pot10 / 10); -- pot10 começa em 10
							digitoInt = digitoFloat * regulador;
							numeroInvertido = numeroInvertido + digitoInt; -- numeroInvertido começa em 0
							pot10 = pot10 * 10;
							regulador = regulador / 10;
						 }
				4. Retornar numero inteiro invertido já concatenado
					4.1. return numInvertido
				5. Imprimir resultados
*/	

int inverterNumero (int numero) {
	float numeroDividido10, digitoFloat;
	int i, casas=0, reguladorCasasConcatenacao=1, determinanteDigitos = 10, digitoInt, numeroInvertido=0;
	
	numeroDividido10 = numero / 10;
	
	while (1) {
		if (numeroDividido10 > 0.1) {
			casas++;
		}
		else
		{
			break;
		}
		numeroDividido10 = numeroDividido10 / 10;
	}
	
	// Totalmente substituível
	for (i = 1; i < casas; i++) {
		reguladorCasasConcatenacao = reguladorCasasConcatenacao * 10;
	}
	
	for (i = 0; i < casas; i++) {
		digitoFloat = (numero % determinanteDigitos) / (determinanteDigitos / 10);
		digitoInt = digitoFloat * reguladorCasasConcatenacao;
		numeroInvertido = numeroInvertido + digitoInt;
		determinanteDigitos = determinanteDigitos * 10;
		reguladorCasasConcatenacao = reguladorCasasConcatenacao / 10;
	}
	
	return numeroInvertido;
}

int main() {
	int numero, numeroInvertido;
	
	printf("Digite um inteiro qualquer: ");
	scanf(" %d", &numero);
	
	numeroInvertido = inverterNumero(numero);
	
	printf("%d\n%d", numero, numeroInvertido);
	
	return 0;
}
