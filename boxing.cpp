// Redoing the following problem from midterm (which I bombed...)

// A set of n candidates are interested in enrolling in the school boxing team. The coach asks
// all candidates to line up in random order. In the initial round of screening the coach wants
// a tall candidate to spar with multiple short candidates, and thus uses a simple algorithm. They 
// pair each candidate with the immediately next taller candidate on the right in the line.
// For instance, if the array represents the heights of 4 students in feet (in the order in which
// they stand in the line), the returned sparring pairs are (5.5, 6.2), (5.4,6.2), (6.2, NULL), and (5.8,NULL).
// Note that 6.2 and 5.8 candidates have no taller candidate on the right. Provide a pseudocode to
// implement the algorithm to return all sparring pairs and comment on its worst case time complexity.

#include <iostream>
#include <stdlib.h>
using namespace std;

class Node
{
public:
    float data;
    Node *next;
} *Head = NULL;

void create(float A[], int n);
void display(Node *p);
void boxing_pair(Node *head);

int main()
{
    float A[] = {5.5, 5.4, 6.2, 5.8};
    create(A, 4);
    display(Head);
    boxing_pair(Head);
    
    return 0;
}

void create(float A[], int n)
{
    int i;
    Node *t;
    Node *last;
    Head = new Node;
    Head -> data = A[0];
    Head -> next = nullptr;
    last = Head;
    
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t -> data = A[i];
        t -> next = nullptr;
        last -> next = t;
        last = t;
    }
}

void display(Node *p)
{
    while (p != nullptr)
    {
        printf("%.2f\n", p -> data);
        p = p -> next;
    }
}

void boxing_pair(Node *head)
{
    Node *p = Head;
    Node *q = p -> next;
    
    while (q != nullptr)
    {
        if(p -> data < q -> data)
        {
            printf("(%.2f, %.2f)", p -> data, q -> data);
            p = p -> next;
            q = q -> next;
        } else {
            q = q -> next;
        }
    }
    printf("(%.2f, NULL)", p -> data);
}