// Program to print the total number of occurences of a given item
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

int count_occurrences(int v) {
    int cnt = 0;
    for (Node *p = head; p; p = p->next)
        if (p->data == v) ++cnt;
    return cnt;
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
    insert_at_end(34);
    insert_at_end(20);
    insert_at_end(20);
    insert_at_end(34);
    insert_at_end(56);
    insert_at_end(67);
    display();
    int x = 34;
    printf("Occurrences of %d = %d\n", x, count_occurrences(x));
    x = 100;
    printf("Occurrences of %d = %d\n", x, count_occurrences(x));
    free_list();
    return 0;
}