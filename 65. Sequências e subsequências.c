# include <stdio.h>
# include <stdlib.h>

/*
	Problema: identificar se uma sequencia B eh subsequencia de uma sequencia A 
			  subsequencia: conjunto de elementos S que nao sao necessariamente adjacentes mas que mantem a mesma ordem em que apareceram na sequencia de referencia
	Abstracao:
				1. Ler numero de elementos de A e de B
				2. ler sequencia A
				3. Ler sequencia B
				4. Verificar se B eh subsequencia de A
					4.1. Verificar se um elemento de B esta presente em A
					4.2. Se nao estiver, entao B nao eh subsequencia de A
					4.3. Se estiver, fazer o teste para o proximo elemento de B mas comecar a partir do indice de parada do teste anterior
					4.4. Se todos os elementos de B estiverem em A seguindo a modalidade de indice do teste, entao B eh subsequencia de A
				5. Imprimir resultados
*/	

void lerSequencia (int numElementos, int sequencia[numElementos]) {
	int i;
	
	for (i = 0; i < numElementos; i++) {
		scanf("%d", &sequencia[i]);
	}
}


int main() {
	int numA, numB, i, j, indiceParada=0, correspondenciaB=0, semCorrespondenciaB=0;
	char resposta;
	
	scanf("%d %d", &numA, &numB);
	
	int seqA[numA], seqB[numB];
	
	lerSequencia(numA, seqA);
	lerSequencia(numB, seqB);
	
	for (i = 0; i < numB; i++)
	{
		for (j = indiceParada; j < numA; j++)
		{
			if (seqB[i] == seqA[j]) 
			{
				correspondenciaB++;
				semCorrespondenciaB = 0;
				indiceParada = j;
				break;
			}
			else
			{
				semCorrespondenciaB++;
			}
			
			if (semCorrespondenciaB == numA - indiceParada) 
			{
				resposta = 'N';
				i = numA;
				break;
			}
		}
	}
	
	if (correspondenciaB == numB) {
		resposta = 'S';
	}
	
	printf("%c", resposta);
	
	return 0;
}