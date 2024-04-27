#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node{
    char data;
    struct Node* next;
    struct Node* prev;
}Node;


Node* new_item(char c){
    Node* node = malloc(sizeof(Node));
    node->data = c;
    node->next = NULL;
    node->prev = NULL;
    return node;
}


Node* push_front(Node* head, char c){
    Node* new_head = new_item(c);
    if(head == NULL){
        new_head->next = new_head->prev = new_head;
        return new_head;
    }
    Node* p = head->prev;

    new_head->next = head;
    new_head->prev = p;

    p->next = new_head;
    head->prev = new_head;

    return new_head;
}


Node* pop_front(Node* head){
    if(head == NULL)
        return NULL;

    Node* new_head = head->next;
    if(new_head == head)
        return NULL;

    Node* p = head->prev;

    p->next = new_head;
    new_head->prev = p;

    free(head);
    return new_head;
}


Node* push_back(Node* head, char c){
    if(head == NULL)
        return push_front(head, c);

    Node* n = new_item(c);
    Node* p = head->prev;

    n->next = head;
    n->prev = p;

    head->prev = n;
    p->next = n;
    
    return head;
}


int main(){
    Node* head = NULL;

    head = push_front(head, 'A');
    head = push_front(head, 'B');
    head = push_front(head, 'C');
    head = push_front(head, 'D');
    head = push_back(head, 'E');
    head = push_back(head, 'F');
    head = push_back(head, 'G');

    while(head){
        printf("%c ", head->data);
        head = pop_front(head);
    }
}
