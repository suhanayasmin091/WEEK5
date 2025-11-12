// Program to create a singly linked list and display its elements
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node  *head = NULL;
void insert (int usdata){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = usdata;
    temp->next = NULL;
    if(head != NULL){
        temp->next = head;  
    }
    head = temp;
}
void display(struct node *start){
    while(start != NULL){
        printf("%d ", start -> data);
        start = start -> next;
    }
}
int main(){
    insert(32);
    insert(33);
    insert(34);
    insert(35);
    insert(36);
    display(head);
    return 0;
}