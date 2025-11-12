// Program to insert a new node at the beginning, end and a given position in a linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

static Node *head = NULL;

static Node *new_node(int v) {
    Node *n = malloc(sizeof *n);
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->data = v;
    n->next = NULL;
    return n;
}

void insertAtBeginning(int usdata) {
    Node *t = new_node(usdata);
    t->next = head;
    head = t;
}

void insertAtEnd(int usdata) {
    Node *t = new_node(usdata);
    if (!head) { head = t; return; }
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = t;
}

void insertAtPosition(int usdata, int pos) {
    if (pos <= 1) { insertAtBeginning(usdata); return; }
    Node *cur = head;
    for (int i = 1; cur && i < pos - 1; ++i) cur = cur->next;
    if (!cur) {
        insertAtEnd(usdata);
        return;
    }
    Node *t = new_node(usdata);
    t->next = cur->next;
    cur->next = t;
}

void display(void) {
    Node *p = head;
    printf("List: ");
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void free_list(void) {
    Node *p = head;
    while (p) {
        Node *t = p;
        p = p->next;
        free(t);
    }
    head = NULL;
}

int main(void) {
    insertAtBeginning(23);    
    insertAtEnd(56);          
    insertAtBeginning(7);     
    insertAtPosition(34, 2);  
    insertAtEnd(90);          
    display(); 
    free_list();
    return 0;
}
