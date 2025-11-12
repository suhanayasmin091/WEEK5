// Program to multiply every element of the linked list by 10
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
    n->data = v; n->next = NULL;
    return n;
}

void insert_at_end(int v) {
    Node *n = new_node(v);
    if (!head) { head = n; return; }
    Node *cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}

void multiply_list(int factor) {
    for (Node *p = head; p; p = p->next)
        p->data *= factor;
}

void display(void) {
    if (!head) { puts("List is empty"); return; }
    printf("List: ");
    for (Node *p = head; p; p = p->next)
        printf("%d%s", p->data, p->next ? " -> " : "\n");
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
    insert_at_end(1);
    insert_at_end(2);
    insert_at_end(3);
    insert_at_end(4);
    insert_at_end(5);
    display();
    multiply_list(10);
    display();
    free_list();
    return 0;
}