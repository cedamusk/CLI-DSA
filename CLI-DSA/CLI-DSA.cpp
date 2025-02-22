// dsa.h
#ifndef DSA_H
#define DSA_H

#include <iostream>
#include <chrono>
#include <vector>
#include <string>

// Stack operations
class Stack {
private:
    std::vector<int> items;
    int top;
    int capacity;

public:
    Stack(int size = 100);
    bool push(int value);
    bool pop();
    int peek() const;
    bool isEmpty() const;
    bool isFull() const;
    void display() const;
};

// Queue operations
class Queue {
private:
    std::vector<int> items;
    int front;
    int rear;
    int capacity;

public:
    Queue(int size = 100);
    bool enqueue(int value);
    bool dequeue();
    int getFront() const;
    bool isEmpty() const;
    bool isFull() const;
    void display() const;
};

// LinkedList Node
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

// Linked List Operations
class LinkedList {
private:
    Node* head;

public:
    LinkedList();
    void insert(int value);
    bool remove(int value);
    bool search(int value) const;
    void display() const;
    ~LinkedList();
};

// Sorting and Searching functions
namespace Algorithms {
    void bubbleSort(std::vector<int>& arr);
    void insertionSort(std::vector<int>& arr);
    void quickSort(std::vector<int>& arr, int low, int high);
    int binarySearch(const std::vector<int>& arr, int target);
}

// Performance Measurement
class Timer {
private:
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point end_time;

public:
    void start();
    void stop();
    double getDurationMs() const;
};

#endif // DSA_H

// CLI-DSA.cpp
#include <limits>
#include "dsa.h"

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void displayMainMenu() {
    std::cout << "\n=== DSA Toolbox===\n"
        << "1. Stack operations\n"
        << "2. Queue Operations\n"
        << "3. Linked List Operations\n"
        << "4. Sorting Algorithms\n"
        << "5. Binary Search\n"
        << "6. Exit\n"
        << "Enter your choice:";
}

void handleStackOperations() {
    Stack stack;
    int choice, value;

    while (true) {
        std::cout << "\n=== Stack Operations ===\n"
            << "1. Push\n"
            << "2. Pop\n"
            << "3. Peek\n"
            << "4. Display\n"
            << "5. Back to Main Menu\n"
            << "Enter your choice:";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter value to push:";
            std::cin >> value;
            if (stack.push(value))
                std::cout << "Pushed " << value << " to stack\n";
            else
                std::cout << "Stack overflow!\n";
            break;
        case 2:
            if (stack.pop())
                std::cout << "Popped value from stack\n";
            else
                std::cout << "Stack is empty!\n";
            break;
        case 3:
            if (!stack.isEmpty())
                std::cout << "Top value: " << stack.peek() << "\n";
            else
                std::cout << "Stack is empty!\n";
            break;
        case 4:
            stack.display();
            break;
        case 5:
            return;
        default:
            std::cout << "Invalid choice!\n";
        }
    }
}

int main() {
    int choice;

    while (true) {
        displayMainMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }
        switch (choice) {
        case 1:
            handleStackOperations();
            break;
        case 2:
            // TODO: Implement Queue operations
            std::cout << "Queue Operations - Coming soon!\n";
            break;
        case 3:
            // TODO: Implement Linked List operations
            std::cout << "Linked List Operations - Coming soon!\n";
            break;
        case 4:
            // TODO: Implement Sorting Operations
            std::cout << "Sorting Operations - Coming soon!\n";
            break;
        case 5:
            // TODO: Implement Binary Search
            std::cout << "Binary Search - Coming soon!\n";
            break;
        case 6:
            std::cout << "Thank you for using DSA Toolbox!\n";
            return 0;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }
    }
    return 0;
}
