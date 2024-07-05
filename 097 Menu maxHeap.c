#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define HEAP_LENGTH 20
int totalElementos = 0;

// TODO: Implementar uma minheap com menu de opções

// * Funções Auxiliares
int obterIndiceFilhoEsq(int indicePai) {
    int indiceFilho = (2 * indicePai) + 1;
    if ((indiceFilho >= totalElementos) || (indiceFilho >= totalElementos)) return -1;
    else return indiceFilho;
}

int obterIndiceFilhoDir(int indicePai) {
    int indiceFilho = (2 * indicePai) + 2;
    if ((indiceFilho >= totalElementos) || (indiceFilho >= totalElementos)) return -1;
    else return indiceFilho;
}

int obterIndicePai(int indiceFilho) {
    int indicePai = (int) floor((indiceFilho-1)/2);
    if ((indiceFilho <= 0) || (indiceFilho >= totalElementos)) return -1;
    else return indicePai;
}

void imprimirHeap(int* heap) {
    int i;
    for (i = 0; i < totalElementos; i++) {
        printf("%d ", heap[i]);
    }
    puts("");
}

// * Funções de Manipulação da Heap
void ajustarSubindo(int* heap, int posicao) {
    if (posicao != -1) {
        int pai = obterIndicePai(posicao);
        if (pai != -1) {
            if (heap[posicao] > heap[pai]) {
                int aux = heap[posicao];
                heap[posicao] = heap[pai];
                heap[pai] = aux;
                ajustarSubindo(heap, pai);
            }
        }
    }
}

void ajustarDescendo(int* heap, int posicao) {
    if ((posicao != -1) && (obterIndiceFilhoEsq(posicao) != -1)) {
        int indiceMenorFilho = obterIndiceFilhoEsq(posicao);
        if ((obterIndiceFilhoDir(posicao) != -1) && (heap[obterIndiceFilhoDir(posicao)] > heap[indiceMenorFilho])) indiceMenorFilho = obterIndiceFilhoDir(posicao);
        if (heap[indiceMenorFilho] > heap[posicao]) {
            int aux = heap[posicao];
            heap[posicao] = heap[indiceMenorFilho];
            heap[indiceMenorFilho] = aux;
            ajustarDescendo(heap, indiceMenorFilho);
        }
    }
}

void inserir(int* heap, int elemento) {
    heap[totalElementos] = elemento;
    totalElementos++;
    ajustarSubindo(heap, totalElementos-1);
}

int remover(int* heap) {
    if (totalElementos == 0) return -1;
    else {
        int retorno = heap[0];
        heap[0] = heap[totalElementos-1];
        totalElementos--;
        ajustarDescendo(heap, 0);
        return retorno;
    }
}

// * Menu
void imprimirMenu() {
    puts("===================================");
    printf("[1] - Inserir elemento x na heap\n");
    printf("[2] - Remover um elemento x da heap\n");
    printf("[3] - Imprimir a heap\n");
    printf("[4] - Sair\n");
    puts("===================================");
    puts("");
}

void menu(int* heap, int entrada) {
    switch (entrada) {
        case 1:
            int elemento;
            puts("");
            printf("Qual valor quer inserir > ");
            scanf("%d", &elemento);
            inserir(heap, elemento);
            break;
        case 2:
            remover(heap);
            imprimirHeap(heap);
            break;
        case 3:
            imprimirHeap(heap);
            break;
        default:
            break;
    }
}

int main() {
    int heap[HEAP_LENGTH];
    int entrada;

    while (1) {
        imprimirMenu();
        printf("Selecione > ");
        scanf("%d", &entrada);

        if (entrada == 4) {
            break;
        }

        menu(heap, entrada);
    }

    return 0;
}