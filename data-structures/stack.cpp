#include <iostream>

#define MAX 1000

class Stack {
    int top;

    public:
    int a[MAX]; // Maximum size of Stack 
  
    Stack() { top = -1; } 
    bool push(int x); 
    int pop(); 
    int peek(); 
    bool isEmpty(); 
    void print();
};

bool Stack::isEmpty() {
    return top < 0;
}

bool Stack::push(int x) {
    if (top >= MAX - 1) return false;
    a[++top] = x;
    return true;
}

int Stack::pop() {
    if (top < 0) return 0;
    return a[top--];
}

int Stack::peek() {
    if (top < 0) return -1;
    return a[top];
}

void Stack::print() {
    if (top < 0) {
        printf("Stack empty\n");
        return;
    }
    printf("[");
    for (int i = 0; i < top; i++) {
        printf("%d,",a[i]);
    }
    printf("%d]\n",a[top]);
}


int main(){
    Stack myStack;
    myStack.push(5);
    myStack.push(50);
    myStack.print();
    std::cout << "Popping" << std::endl;
    std::cout << myStack.pop() << std::endl;
    std::cout << "Popping again" << std::endl;
    std::cout << myStack.pop() << std::endl;
    std::cout << "isEmpty: " << myStack.isEmpty() << std::endl;

}