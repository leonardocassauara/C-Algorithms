# include <stdio.h>
# include <assert.h>
# include <stdlib.h>


typedef struct Node {
    char data;
    struct Node* next;
} Node;


Node* new_item(char c) {
    struct Node* node = malloc(sizeof(struct Node));
    
    node->data = c;
    node->next = NULL;
    return node;
}


Node* push_front(Node* head, char c) {
    Node* new_head = new_item(c);
    
    new_head->next = head;
    return new_head;
}


Node* push_back(Node* head, char c) {

    Node* n = new_item(c);

    if(head == NULL) return n;

    Node* back = back_node(head);
    back->next = n;
    return head;
}


Node* pop_front(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    Node* new_head = head->next;
    free(head);
    return new_head;
}


Node* back_node(Node* head) {
    
    if(head == NULL) return NULL;

    Node* back = head;

    while(back->next != NULL) back = back->next;

    return back;
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


void push_after(Node* node, char c) {

    if (node != NULL) {
        Node* n = new_item(c);
        n->next = node->next;
        node->next = n;
    }
}


Node* remove_item(Node* head, char c) {

    if(head == NULL) return NULL;

    if(head->data == c) return pop_front(head);

    Node* p = head;
    Node* n = p->next;

    while((n != NULL) && (n->data != c)) {
        p = n;
        n = n->next;
    }

    if(n != NULL) {
        p->next = n->next;
        free(n);
    }

    return head;
}


int main() {

    Node* head = NULL;

    head = push_back(head, 'A');
    head = push_back(head, 'B');
    head = push_back(head, 'C');
    head = push_back(head, 'D');

    head = remove_item(head, 'B');

    while(head){
        printf("%c ", head->data);
        head = pop_front(head);
    }

    return 0;
}