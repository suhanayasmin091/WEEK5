// Program to search for a particular value in a linked list
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

int search_value(int v) {
    int pos = 1;
    for (Node *p = head; p; p = p->next, ++pos) {
        if (p->data == v) return pos;
    }
    return -1;
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
    insert_at_end(7);
    insert_at_end(32);
    insert_at_end(43);
    insert_at_end(54);
    insert_at_end(65); 
    display();
    int v = 32;
    int pos = search_value(v);
    if (pos != -1)
        printf("Value %d found at position %d\n", v, pos);
    else
        printf("Value %d not found\n", v);

    v = 76;
    pos = search_value(v);
    if (pos != -1)
        printf("Value %d found at position %d\n", v, pos);
    else
        printf("Value %d not found\n", v);

    free_list();
    return 0;
}
