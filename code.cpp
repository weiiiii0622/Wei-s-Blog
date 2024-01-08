#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow!" << std::endl;
            return -1;
        }
        Node* temp = top;
        int poppedValue = temp->data;
        top = top->next;
        delete temp;
        return poppedValue;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        return top->data;
    }
};

int main() {
    Stack stack;

    stack.push(5); // Pushing 5 onto the stack
    stack.push(10); // Pushing 10 onto the stack
    stack.push(15); // Pushing 15 onto the stack

    std::cout << "Top element: " << stack.peek() << std::endl; // Output: Top element: 15

    std::cout << "Popped element: " << stack.pop() << std::endl; // Output: Popped element: 15
    std::cout << "Popped element: " << stack.pop() << std::endl; // Output: Popped element: 10

    std::cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << std::endl; // Output: Is stack empty? No

    return 0;
}
