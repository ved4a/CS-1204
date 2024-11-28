#include <iostream>
#include <stdlib.h>

class ArrayQueue{
private:
    int front;
    int rear;
    int size;
    int *Q;
public:
    ArrayQueue(int size){this -> front = this -> rear = -1; this -> size = size; Q = new int[size];}
    void enqueue(int x);
    int dequeue();
    void Display();
};

class Node{
public:
    int data;
    Node* next;
} *Head = nullptr;

class LinkedListQueue{
private:
    Node* front;
    Node* rear;
public:
    LinkedListQueue(){this -> front = this -> rear = nullptr;}
    // ~LinkedListQueue();
    void enqueue(int x);
    int dequeue();
    void Display();
};

int main(){
    ArrayQueue queue(7);
    queue.enqueue(5);
    queue.enqueue(3);
    queue.enqueue(12);
    queue.enqueue(97);
    queue.enqueue(8);
    queue.enqueue(36);
    queue.enqueue(42);
    queue.Display();

    queue.enqueue(2);


    // queue.Display();
    
    return 0;
}

void ArrayQueue::enqueue(int x){
    if(rear == size - 1){
        printf("Queue Overflow");
    } else {
        if(front == -1){
            front = 0;
        }
        rear++;
        Q[rear] = x;
    }
}

int ArrayQueue::dequeue(){
    int x = -1;
    if(front == -1 || front > rear){
        printf("Queue Underflow");
    } else {
        x = Q[front];
        front++;
        if(front > rear){
            front = rear = -1;
        }
    }
    return x;
}

void ArrayQueue::Display(){
    if(front == -1){
        printf("Queue is empty");
        return;
    }
    for(int i = front; i <= rear; i++){
        printf("%d\n", Q[i]);
    }
}

void LinkedListQueue::enqueue(int x){
    Node* t = new Node;
    if(t == nullptr){
        printf("Queue Overflow");
        return;
    }
    t -> data = x;
    t -> next = nullptr;
    if(front == nullptr){
        front = rear = t;
    } else{
        rear -> next = t;
        rear = t;
    }
}

int LinkedListQueue::dequeue(){
    int x = -1;
    Node *t;
    if(front == nullptr){
        printf("Queue Underflow");
    } else {
        t = front;
        front = front -> next;
        x = t -> data;
        delete t;
    }
    return x;
}

void LinkedListQueue::Display(){
    Node* t;
    t = front;
    if(front == nullptr){
        printf("Queue is empty");
    } else {
        while(t != nullptr){
            printf("%d", t->data);
            t = t -> next;
        }
    }
}