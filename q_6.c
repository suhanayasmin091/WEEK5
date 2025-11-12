// Program that removes all nodes that have duplicate information
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

void display(void) {
    if (!head) { puts("List is empty"); return; }
    printf("List: ");
    for (Node *p = head; p; p = p->next)
        printf("%d%s", p->data, p->next ? " -> " : "\n");
}

void free_list(Node **h) {
    Node *p = *h;
    while (p) {
        Node *t = p;
        p = p->next;
        free(t);
    }
    *h = NULL;
}

void remove_all_duplicates(void) {
    if (!head) return;
    Node *new_head = NULL, *new_tail = NULL;

    for (Node *p = head; p; p = p->next) {
        int val = p->data;
        int count = 0;
        for (Node *q = head; q; q = q->next)
            if (q->data == val) ++count;
        if (count == 1) {
            Node *n = new_node(val);
            if (!new_head) new_head = new_tail = n;
            else { new_tail->next = n; new_tail = n; }
        }
    }

    free_list(&head);
    head = new_head;
}

int main(void) {
    insert_at_end(11);
    insert_at_end(25);
    insert_at_end(25);
    insert_at_end(35);
    insert_at_end(35);
    insert_at_end(46);
    insert_at_end(58);
    display(); 
    remove_all_duplicates();
    display();
    free_list(&head);
    return 0;
}