# include <stdio.h>
# include <stdlib.h>


void selectionSort(int* vetor, int tamanhoVetor) {

    int i, j;
    int indiceMenor;
    int aux;

    for (i = 0; i < tamanhoVetor; i++) {

        indiceMenor = i;


        for (j = i; j < tamanhoVetor; j++) {

            if (vetor[j] < vetor[indiceMenor]) indiceMenor = j;
        }



        aux = vetor[i];
        vetor[i] = vetor[indiceMenor];
        vetor[indiceMenor] = aux;
    }
}


int main() {

    int notaHoje[] = {0, 2, 4, 6, 10, 9, 8, 1, 5};

    int tamanhoVetor=9;

    selectionSort(notaHoje, tamanhoVetor);

    printf("Minha nota hoje: %d", notaHoje[8]);

    return 0;
}
