# include <stdio.h>
# include <assert.h>
# include <stdlib.h>


typedef struct Node{
    char data;
    struct Node* next;
    struct Node* prev;
} Node;


Node* new_item(char c) {
    Node* node = malloc(sizeof(Node));
    node->data = c;
    node->next = NULL;
    node->prev = NULL;

    return node;
}


Node* push_front(Node* head, char c) {
    Node* new_head = new_item(c);
    if(head == NULL) return new_head;

    new_head->next = head;
    head->prev = new_head;

    return new_head;
}


Node* pop_front(Node* head) {
    if(head == NULL) return NULL;

    Node* new_head = head->next;
    if(new_head != NULL) new_head->prev = NULL;

    free(head);
    return new_head;
}


Node* back_node(Node* head) {
    
    if(head == NULL) return NULL;

    Node* back = head;

    while(back->next != NULL) back = back->next;

    return back;
}


Node* push_back(Node* head, char c){
    Node* n = new_item(c);
    Node* back = back_node(head);
    if(back == NULL)
        return n;

    back->next = n;
    n->prev = back;

    return head;
}


void push_after(Node* node, char c){
    if(node == NULL)
        return;

    Node* n = new_item(c);
    n->next = node->next;
    n->prev = node;

    node->next = n;
    n->next->prev = n;
}


Node* find(Node* head, char c) {

    Node* n;

    for(n = head; n != NULL; n = n->next) {

        if(c == n->data) {
            return n;
        }
    }

    return NULL;
}


Node* remove_node(Node* head, Node* B){
    if(head == NULL || B == NULL)
        return head;
    if(B == head)
        return pop_front(head);

    Node* A = B->prev;
    Node* C = B->next;
    A->next = C;
    C->prev = A;
    free(B);
    return head;
}


Node* remove_item(Node* head, char c){
    Node* N = find(head, c);
    return remove_node(head, N);
}


int main(){
    Node* head = NULL;

    head = push_back(head, 'A');
    head = push_back(head, 'B');
    head = push_back(head, 'C');
    head = push_back(head, 'D');
    head = push_back(head, 'E');
    head = push_back(head, 'F');
    head = push_back(head, 'G');

    head = remove_item(head, 'E');

    Node* D = find(head, 'D');

    printf("Para frente: ");
    for(Node* p = D; p != NULL; p = p->next)
        printf("%c ", p->data);

    printf("\nPara trás: ");
    for(Node* p = D; p != NULL; p = p->prev)
        printf("%c ", p->data);

    while(head)
        head = pop_front(head);

    return 0;
}
