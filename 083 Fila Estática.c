#include <stdio.h>
#include <assert.h>
#define MAXSIZE 4

/*  EXERCÍCIOS DE FILAS:
    Fila de Strings para simular um sistema de atendimento, 
*/

typedef struct{
    char data[MAXSIZE];
    int n;
    int first;
}Queue;


void init_queue(Queue* Q){
    Q->n = 0;
    Q->first = 0;
}


void enqueue(Queue* Q, char C){
    assert(Q->n < MAXSIZE);
    int index = (Q->first + Q->n)%MAXSIZE;
    Q->data[index] = C;
    Q->n++;
}


char dequeue(Queue* Q){
    assert(Q->n > 0);
    char C = Q->data[Q->first];
    Q->first = (Q->first+1)%MAXSIZE;
    Q->n--;
    return C;
}


int main(){
    Queue Q;
    init_queue(&Q);
    enqueue(&Q, 'A');
    enqueue(&Q, 'B');
    enqueue(&Q, 'C');
    printf("%c ", dequeue(&Q) );
    enqueue(&Q, 'D');
    printf("%c ", dequeue(&Q) );
    enqueue(&Q, 'E');
    enqueue(&Q, 'F');
    printf("%c ", dequeue(&Q) );
    printf("%c ", dequeue(&Q) );
    printf("%c ", dequeue(&Q) );
    printf("%c ", dequeue(&Q) );
}
