# include <stdio.h>


void imprimir6ElementosVetor (int n, int* vetor, int startIndex) {
	int i;
	
	for (i = startIndex; i < startIndex + 6; i++)
	{
		if (i > n) {
			break;
		}
		printf("%d ", *(vetor + i));
	}
	puts("");
}


int main() {
	int v[] = {54, 21, 73, 79, 10, 8, 32, 34, 63, 76, 14, 21};
	int b[] = {3, 51, 42, 63, 52, 78, 67, 82, 43, 26};
	int startIndex, i;
	
	scanf("%d", &startIndex);
	imprimir6ElementosVetor(12, v, startIndex);
	
	scanf("%d", &startIndex);
	imprimir6ElementosVetor(10, b, startIndex);
	
	return 0;
}
