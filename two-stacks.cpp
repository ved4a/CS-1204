#include <stdlib.h>
#include <iostream>
using namespace std;

class twoStacks
{
private:
    int *arr;
    int size;
    int top1, top2;
public:
    // constructor
    twoStacks(int n){
        size = n;
        arr = new int[size];
        int top1 = -1;
        int top2 = size - 1;
    };

    // push from 1 end
    void push1(int x){
        if(top1 < top2 - 1){
            top1++;
            arr[top1] = x;
        } else {
            cout << "Stack Overflow";
        }
    }

    // push from other end
    void push2(int x){
        if(top1 < top2 - 1){
            top2--;
            arr[top2] = x;
        } else {
            cout << "Stack Overlow";
        }
    }

    // pop from 1 end
    int  pop1(){
        int n = -1;
        if(top1 == -1){
            cout << "Stack Underflow";
        } else {
            n = arr[top1];
            top1--;
        }
        return n;
    }

    // pop from other end
    int pop2(){
        int n = -1;
        if(top2 == size - 1){
            cout << "Stack Underflow";
        } else {
            n = arr[top2];
            top2++;
        }
        return n;
    }
};

int main(){
    twoStacks ts(5); 
    ts.push1(5); 
    ts.push2(10); 
    ts.push2(15); 
    ts.push1(11); 
    ts.push2(7); 
    cout << "Popped element from stack1 is " << ts.pop1(); 
    ts.push2(40); 
    cout << "\nPopped element from stack2 is " << ts.pop2(); 
    return 0; 
}