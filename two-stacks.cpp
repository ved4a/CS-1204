#include <iostream>
using namespace std;

class twoStacks {
private:
    int* arr;
    int size;
    int top1, top2;
public:
    // constructor
    twoStacks(int n) {
        size = n;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    // deconstructor
    ~twoStacks() {
        delete[] arr;
    }

    // push from right
    void push1(int x) {
        if (top1 < top2 - 1) {
            top1++;
            arr[top1] = x;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    // push from left
    void push2(int x) {
        if (top1 < top2 - 1) {
            top2--;
            arr[top2] = x;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    // pop from right
    int pop1() {
        if (top1 == -1) {
            cout << "Stack Underflow\n";
            return -1;
        } else {
            int n = arr[top1];
            top1--;
            return n;
        }
    }

    // pop from left
    int pop2() {
        if (top2 == size) {
            cout << "Stack Underflow\n";
            return -1;
        } else {
            int n = arr[top2];
            top2++;
            return n;
        }
    }
};

int main() {
    twoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    ts.push2(15);
    ts.push1(11);
    ts.push2(7);
    cout << "Popped element from stack1 is " << ts.pop1() << endl;
    ts.push2(40);
    cout << "Popped element from stack2 is " << ts.pop2() << endl;
    return 0;
}
