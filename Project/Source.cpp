#include <iostream>

class Stack {
private:
    int* data;
    int capacity;
    int topIndex;

public:
    Stack(int capacity) {
        this->capacity = capacity;
        data = new int[capacity];
        topIndex = -1;
    }

    ~Stack() {
        delete[] data;
    }

    void push(int x) {
        if (topIndex == capacity - 1) {
            std::cerr << "Stack overflow!" << std::endl;
            return;
        }
        topIndex++;
        data[topIndex] = x;
    }

    int pop() {
        if (isEmpty()) {
            std::cerr << "Stack is empty!" << std::endl;
            return -1; 
        }
        int value = data[topIndex];
        topIndex--;
        return value;
    }

    bool isEmpty() {
        return topIndex == -1;
    }
};

class Queue {
private:
    Stack s1;
    Stack s2;

public:
    Queue(int capacity) : s1(capacity), s2(capacity) {}

    void enqueue(int x) {
        s1.push(x);
    }

    int dequeue() {
        if (isEmpty()) {
            std::cerr << "Queue is empty!" << std::endl;
            return -1; 
        }

        if (s2.isEmpty()) {
            while (!s1.isEmpty()) {
                s2.push(s1.pop());
            }
        }
        return s2.pop();
    }

    bool isEmpty() {
        return s1.isEmpty() && s2.isEmpty();
    }
};


int main() {
    // Stack example
    Stack stack(5);
    stack.push(1);
    stack.push(2);
    stack.push(3);

    std::cout << "Stack pop: " << stack.pop() << std::endl; 
    std::cout << "Stack pop: " << stack.pop() << std::endl; 
    std::cout << "Stack is empty: " << stack.isEmpty() << std::endl; 
    std::cout << "Stack pop: " << stack.pop() << std::endl; 
    std::cout << "Stack is empty: " << stack.isEmpty() << std::endl; 

    // Queue example
    Queue queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Queue dequeue: " << queue.dequeue() << std::endl; 
    std::cout << "Queue dequeue: " << queue.dequeue() << std::endl; 
    std::cout << "Queue is empty: " << queue.isEmpty() << std::endl; 
    std::cout << "Queue dequeue: " << queue.dequeue() << std::endl; 
    std::cout << "Queue is empty: " << queue.isEmpty() << std::endl; 

    return 0;
}
