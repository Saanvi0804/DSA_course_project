#include <iostream>
using namespace std;

#define MAXSIZE 5

class Stack {
private:
    int top;
    int arr[MAXSIZE];

public:
    Stack();
    bool sempty();
    bool sfull();
    void push();
    void pop();
    void peek();
    void print();
};

Stack::Stack() {
    top = -1;
    for (int i = 0; i < MAXSIZE; i++) {
        arr[i] = 0;
    }
}


bool Stack::sempty() {
    if(top == -1)
        return 1;
    else
        return 0;
}


bool Stack::sfull() {
     if(top == MAXSIZE-1)
        return 1;
    else
        return 0;
}


void Stack::push() {
    if (sfull()) {
        cout << "Stack overflow!" << endl;
    } else {
        int val;
        cout << "Enter value to be pushed\n";
        cin >> val;
        top++;
        arr[top] = val;
    }
}

void Stack::pop() {
    if (sempty()) {
        cout << "Stack underflow!" << endl;
        return;
    } else {
        int x = arr[top];
        top--;
        cout << "Popped item is" << x << "\n";
    }
}


void Stack::peek() {
    if (sempty()) {
        cout << "Stack is empty!" << endl;
        return;
    } else {
        cout << "Peek item is" << arr[top] << "\n";
    }
}


void Stack::print() {
    if (sempty()) {
        cout << "Stack is empty!" << endl;
    } else {
        cout << "Stack elements:\n";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << "\n";
        }
        cout << endl;
    }
}

int main() {
    Stack s1;
    int choice;

    while(1){
        cout << "Menu\n";
        cout << "1-Push\n2-Pop\n3-Peek\n4-Print\n5-Exit\n";
        cout << "Enter your choice\n";
        cin >> choice;

        switch(choice){
            case 1: s1.push();
                    break;

            case 2: s1.pop();
                    break;

            case 3:s1.peek();
                    break;

            case 4:s1.print();
                    break;

            case 5: cout << "Exiting Program\n";
                    exit(1);
        }
    }

    return 0;
}
