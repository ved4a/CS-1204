#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node{
    int data;
    Node* next;
} *Head = nullptr;

void create(int A[], int n);
void display(struct Node *p);
int count(struct Node *p);
int sum(struct Node *p);
int max(struct Node *p);
Node* search(struct Node *p, int key);
void insert(struct Node *p, int pos, int x);
void del(struct Node *p, int pos);
bool isSorted(struct Node *p);
void reverse(struct Node *first);

int main(){
    int arr[] = {3, 5, 12, 7, 15};
    create(arr, 5);
    display(Head);
    // printf("%d\n", count(Head));
    // printf("%d\n", sum(Head));
    // printf("%d\n", max(Head));
    reverse(Head);
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
        printf("%d\n", p -> data);
        p = p -> next;
    }
}

int count(struct Node *p){
    int x = 0;
    while(p != nullptr){
        x++;
        p = p -> next;
    }
    return x;
}

int sum(struct Node *p){
    int sum = 0;
    while(p != nullptr){
        sum += p -> data;
        p = p-> next;
    }
    return sum;
}

int max(struct Node *p){
    int n = INT32_MIN;
    while(p){
        if(n < p -> data){
            n = p -> data;
        }
        p = p -> next;
    }
    return n;
}

Node* search(struct Node *p, int key){
    if(p == nullptr){
        return NULL;
    }
    if(key == p -> data){
        return p;
    }
    search(p -> next, key);
}

void insert(struct Node *first, int pos, int x){
    struct Node *t, *p;
    // insert at Head
    if(pos == 0){
        t = new Node;
        t -> data = x;
        t -> next = Head;
        Head = t;
    } else if(pos > 0) {
        // insert at a pos beyond head
        p = Head;
        for(int i = 0; i < pos - 1 && p; i++){
            p = p -> next;
        }
        if(p){
            t = new Node;
            t -> data = x;
            t -> next = p -> next;
            p -> next = t;
        }
    }
}

void del(struct Node *p, int pos){
    struct Node *a, *b;
    a = Head;
    b = nullptr;

    // delete head
    if(pos == 0){
        Head = Head -> next;
        delete a;
    } else if (pos > 0){
        for(int i = 0; i < pos - 1 && a; i++){
            b = a;
            a = a -> next;
        }
        b -> next = a -> next;
        delete a;
    }
}

bool isSorted(struct Node *first){
    int x = INT32_MIN;
    struct Node *p;
    while(p){
        if(p -> data < x){
            return false;
        }
        x = p -> data;
        p = p-> next;
    }
    return true;
}

void reverse(struct Node *first){
    Node *current = Head;
    Node *prev, *next = nullptr;

    while(current != nullptr){
        next = current -> next;
        current -> next = prev;
        prev = current;
        current = next;
    }
    Head = prev;
}