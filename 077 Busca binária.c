# include <stdio.h>
# include <stdlib.h>


int buscaBinaria(int tamanhoVetor, int* vetor, int valorProcurado) {

    int inicio = 0;
    int fim = tamanhoVetor - 1;
    int meio;

    while (inicio < fim) {
    
        meio = (fim + inicio) / 2;
    
        if (vetor[meio] > valorProcurado) {
           
            fim = meio;
        }
        else if (vetor[meio] < valorProcurado) {
            
            inicio = meio;
        }
        else {
            
            return meio;
        }
    }
    
    return -1;
}


int main() {

    int notaHoje[] = {0, 2, 4, 6, 10, 9, 8, 1, 5};

    int tamanhoVetor=9;
    int valorProcurado=10; // vamo familia

    if (buscaBinaria(9, notaHoje, 10)) printf("Vamo krl");
    else printf("é o caixas.");

    return 0;
}
