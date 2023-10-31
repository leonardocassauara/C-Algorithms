# include <stdio.h>
# include <stdlib.h>


void merge(int* vetor, int inicio, int meio, int fim) {

    int i, j, k;
    int tamanhoLeft = meio - inicio;
    int tamanhoRight = fim - meio;
    int topoLeft = 0;
    int topoRight = 0;
    int* left = malloc(tamanhoLeft*sizeof(int));
    int* right = malloc(tamanhoRight*sizeof(int));
    
    j = 0;
    for (i = inicio; i < meio; i++) {

        left[j] = vetor[i];
        j++;
        
    }

    j = 0;
    for (i = meio; i < fim; i++) {

        right[j] = vetor[i];
        j++;
    }
    

    for (k = inicio; k < fim; k++) {

        if (topoLeft >= tamanhoLeft) {

            vetor[k] = right[topoRight];
            topoRight++;
        }
        else if (topoRight >= tamanhoRight) {

            vetor[k] = left[topoLeft];
            topoLeft++;
        }
        else if (left[topoLeft] < right[topoRight]) {

            vetor[k] = left[topoLeft];
            topoLeft++;
        }
        else {

            vetor[k] = right[topoRight];
            topoRight++;
        }
    }

    free(right);
    free(left);
}


void mergeSort(int* vetor, int inicio, int fim) {

    int meio;

    if ((fim - inicio) > 1) {

        meio = (fim + inicio) / 2;
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio, fim);
        merge(vetor, inicio, meio, fim);
    }
}


int main() {

    int i;
    int a[] = {45, 186, 185, 55, 51, 51, 22, 78, 64, 26, 49, 21};
    mergeSort(a, 0, 12);

    for (i = 0; i < 12; i++) {

        printf("%d ", a[i]);
    }

    return 0;
}