#include <iostream>
#include <stdlib.h>

struct Node{
    int data;
    Node* next;
} *Head = nullptr;

int main(){
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