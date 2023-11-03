# include <stdio.h>

// Desafio de Algoritmo do Beecrowd: https://www.beecrowd.com.br/judge/pt/problems/view/1088

void lerSequencia(int* N, int* vetor, int* i) {
	for (*i = 0; *i < *N; *i = *i + 1) {
		scanf("%d", &vetor[*i]);
	}
}


void ordenarSequenciaBubble(int* N, int* vetor, int* i, int* turno) {
	*turno = 0;
	int ordenado = 0, aux;
	
	while (!ordenado) {
		ordenado = 1;

		for (*i = 0; *i < *N-1; *i = *i + 1) {
	
			if (vetor[*i] > vetor[*i+1]) {
				aux = vetor[*i];
				vetor[*i] = vetor[*i+1];
				vetor[*i+1] = aux;
				
				ordenado = 0;
				*turno = *turno + 1;
			}
		}
	}
}


int main() {
	int N, turno, i=0;
	
	
	while (1) {
		scanf("%d", &N);
		if (N == 0) {
			return 0;
		}
		
		int sequencia[N];
		
		lerSequencia(&N, sequencia, &i);
		ordenarSequenciaBubble(&N, sequencia, &i, &turno);
		printf(turno % 2 == 0 ? "Carlos\n" : "Marcelo\n");
		printf("\n%d\n", turno);
	}
	
	return 0;
}

