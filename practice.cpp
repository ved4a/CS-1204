#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node* next;
} *Head = nullptr;

void create(int A[], int n);
void display(Node *first);
void insert(Node *node, int x);
int count(Node *node);
int sum(Node *node);
bool is_sorted(Node *node);
void reverse(Node *node);

int main(){
    int A[] = {12, 7, 5, 49, 1};
    create(A, 5);
    display(Head);
    printf("\n");
    // printf("%d", sum(Head));
    // printf("%d", count(Head));
    // insert(Head, 8);
    // display(Head);
    // printf("%d", count(Head));
    reverse(Head);
    display(Head);
    
    return 0;
}

void create(int A[], int n){
    int i;
    Node *t, *last;

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

void display(Node *p){
    while(p!=nullptr){
        printf("%d\n", p -> data);
        p = p -> next;
    }
}

void insert(Node *node, int x){
    struct Node *t = new Node;
    if (t == nullptr){
        printf("Stack Overflow");
    } else {
        t -> data = x;
        t -> next = Head;
        Head = t;
    }
}

int count(Node *node){
    int c = 0;
    if (node == nullptr){
        printf("Empty list.");
    } else {
        while(node != nullptr){
            c++;
            node = node -> next;
        }
    }
    return c;
}

int sum(Node *node){
    int sum = 0;
    if(node == nullptr){
        printf("Empty list.");
    } else {
        while(node != nullptr){
            sum += node -> data;
            node = node -> next;
        }
    }
    return sum;
}

bool is_sorted(Node *node){
    int x = INT32_MIN;
    while(node != nullptr){
        if(node -> data < x){
            return false;
        } else {
            x = node -> data;
            node = node -> next;
        }
    }
    return true;
}

void reverse(Node *node){
    Node *prev = nullptr;
    Node *current = node;
    Node *next = nullptr;

    while(current != nullptr){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    Head = prev;
}