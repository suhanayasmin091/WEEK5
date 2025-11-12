// Program to delete a node from the beginning, end and a given position in a linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

static Node *head = NULL;

static Node *new_node(int v) {
    Node *n = malloc(sizeof *n);
    if (!n) { perror("malloc"); exit(EXIT_FAILURE); }
    n->data = v;
    n->next = NULL;
    return n;
}

void insert_at_end(int v) {
    Node *n = new_node(v);
    if (!head) { head = n; return; }
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

void display(void) {
    Node *p = head;
    if (!p) { puts("List is empty"); return; }
    printf("List: ");
    while (p) {
        printf("%d%s", p->data, p->next ? " -> " : "\n");
        p = p->next;
    }
}

int delete_from_beginning(void) {
    if (!head) return 0;
    Node *t = head;
    head = head->next;
    free(t);
    return 1;
}

int delete_from_end(void) {
    if (!head) return 0;
    if (!head->next) {
        free(head);
        head = NULL;
        return 1;
    }
    Node *cur = head;
    while (cur->next && cur->next->next) cur = cur->next;
    free(cur->next);
    cur->next = NULL;
    return 1;
}

int delete_at_position(int pos) {
    if (pos < 1 || !head) return 0;
    if (pos == 1) return delete_from_beginning();
    Node *cur = head;
    for (int i = 1; cur && i < pos - 1; ++i) cur = cur->next;
    if (!cur || !cur->next) return 0;
    Node *t = cur->next;
    cur->next = t->next;
    free(t);
    return 1;
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
    insert_at_end(2);
    insert_at_end(3);
    insert_at_end(6);
    insert_at_end(25);
    insert_at_end(26);
    display();                
    delete_from_beginning();  
    display();                 
    delete_from_end();          
    display();                 
    delete_at_position(3);      
    display();                 
    free_list();
    return 0;
}
