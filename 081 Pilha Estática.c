# include <stdio.h>
# define MAXSIZE 1024

/* EXERCÍCIOS DE PILHA:
    verificar abertura e fechamento de ( [ {, evaluate uma string de operadores pósfixos, usar pilha para verificar palindromo (condição de parada)
*/


typedef struct{
    int n;
    char data[MAXSIZE];
}Stack;


void init_stack(Stack* stack){
    stack->n = 0;
}


bool is_empty(Stack* stack){
    return stack->n == 0;
}


char top(Stack* stack){
    assert(!is_empty(stack));
    return stack->data[stack->n - 1];
}


void push(Stack* stack, char value){
    assert(stack->n < MAXSIZE);
    stack->data[stack->n++] = value;
}


void pop(Stack* stack){
    assert(!is_empty(stack));
    stack->n--;
}


int main() {

    char stack[MAXSIZE]; // VETOR DE CHAR - Pilha estática de caractere de tamanho MAXSIZE
    int n = 0;
    char cinput;

    // INSERIR VALOR NA PILHA e INCREMENTAR INDICE
    while ((n < MAXSIZE) && (scanf("%c", &cinput) == 1)) stack[n++] = c;

    while (n > 0) {

        printf("%c ", stack[n-1]);
        n--;
    }
}