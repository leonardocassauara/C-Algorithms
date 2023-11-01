# include <stdio.h>


void insertionSort(int N, int* vetor) {

    int i, valor, indice;

    for (i = 1; i < N; i++) {

        valor = vetor[i];
        indice = i;

        while ((indice > 0) && (vetor[indice-1] > valor)) {

            vetor[indice] = vetor[indice-1];
            indice--;
        }
        vetor[indice] = valor;
    }
}


void imprimirVetor(int N, int* vetor) {
    int i;

    puts(" ");
    for(i = 0; i < N; i++) printf("%d ", vetor[i]);
}


int main() {

    int vetor[] = {4, 5, 19, 231, 9, 0, 331, 1, 2, 23, 11, 41};

    insertionSort(12, vetor);

    imprimirVetor(12, vetor);

    return 0;
}