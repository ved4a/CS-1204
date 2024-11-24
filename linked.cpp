#include <iostream>
#include <stdlib.h>

struct Node{
    int data;
    Node* next;
} *Head = nullptr;

void create(int A[], int n);
void display(struct Node *p);

int main(){
    int arr[] = {3, 5, 12, 7, 15};
    create(arr, 5);
    display(Head);
    return 0;
}

void create(int A[], int n){
    int i; // counter
    struct Node *t, *last; // pointers for new node and last node

    Head = new Node;
    Head -> data = A[0];
    Head -> next = nullptr;
    last = Head;

    for(i = 1; i < n; i++){
        t = new Node;
        t -> data = A[i];
        t -> next = nullptr;
        last -> next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p != nullptr){
        printf("%d", p -> data);
        p = p -> next;
    }
}