#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define MAXSIZE 100

typedef struct{
    int priority;
    char name[51];
}Dados;


typedef struct{
    Dados data[MAXSIZE];
    int n;
}PriorityQueue;


void init_queue(PriorityQueue* q){
    q->n = 0;
}


Dados dequeue(PriorityQueue* q){
    assert(q->n > 0);
    q->n--;
    return q->data[q->n];
}


void enqueue(PriorityQueue* q, int priority, const char* name){
    // Lança um erro quando a condição "q->N < MAXSIZE" retornar false (0)
    assert(q->n < MAXSIZE);
    
    // i recebe o número de itens na Fila
    int i = q->n;

    // Enquanto tiver itens na fila & se a prioridade do item anterior for maior ou igual a prioridade do item que está sendo inserido, então:
    while(i > 0 && q->data[i-1].priority >= priority){
        
        // Então o item na frente da fila "avança" para criar um espaço para o item que está sendo inserido ficar atras dele na fila
        q->data[i] = q->data[i-1];
        i--;
    }

    // O lugar correto na fila recebe os dados do item que está sendo inserido
    q->data[i].priority = priority;
    strcpy(q->data[i].name, name);

    // Atualize o número de itens na fila, incrementando em 1 unidade.
    q->n++;
}


int main(){
    PriorityQueue q;
    init_queue(&q);
    enqueue(&q,  5, "Marquinhos da Silva");
    enqueue(&q, 67, "Zefinha Lemos");
    enqueue(&q, 12, "Bode Gaiato");
    enqueue(&q,  5, "Zequinha");
    enqueue(&q, 67, "Seu Ciço");

    while(q.n > 0){
        Dados D = dequeue(&q);''
        puts(D.name);
    }
}

