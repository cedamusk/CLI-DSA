#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include <limits>
#ifdef _WIN32
#include <cstdlib>
#else
#include <stdlib.h>
#endif

// -------------------------------------------------------
// 1. Stack Class (Fully Implemented)
// -------------------------------------------------------
class Stack {
private:
    std::vector<int> items;
    int topIndex;
    int capacity;

public:
    // Constructor
    Stack(int size = 100)
        : items(size), topIndex(-1), capacity(size) {
    }

    // Push operation
    bool push(int value) {
        if (isFull()) {
            return false;
        }
        items[++topIndex] = value;
        return true;
    }

    // Pop operation
    bool pop() {
        if (isEmpty()) {
            return false;
        }
        --topIndex;
        return true;
    }

    // Peek (top) operation
    int peek() const {
        if (isEmpty()) {
            return -1; // or throw an exception
        }
        return items[topIndex];
    }

    // Check if stack is empty
    bool isEmpty() const {
        return (topIndex == -1);
    }

    // Check if stack is full
    bool isFull() const {
        return (topIndex == capacity - 1);
    }

    // Display stack contents
    void display() const {
        if (isEmpty()) {
            std::cout << "Stack is empty!\n";
            return;
        }
        std::cout << "Stack [top -> bottom]: ";
        for (int i = topIndex; i >= 0; i--) {
            std::cout << items[i] << " ";
        }
        std::cout << "\n";
    }
};

// -------------------------------------------------------
// 2. Queue Class (Placeholder - Not Implemented)
// -------------------------------------------------------
class Queue {
private:
    // Example placeholders
    // You can implement an array-based or linked-list-based queue here
    // For now, we'll keep it simple so it compiles.
    int dummy;

public:
    Queue(int size = 100) : dummy(size) {}

    bool enqueue(int value) {
        // TODO: Implement
        return false;
    }

    bool dequeue() {
        // TODO: Implement
        return false;
    }

    int getFront() const {
        // TODO: Implement
        return -1;
    }

    bool isEmpty() const {
        // TODO: Implement
        return true;
    }

    bool isFull() const {
        // TODO: Implement
        return false;
    }

    void display() const {
        // TODO: Implement
        std::cout << "Queue display - not implemented.\n";
    }
};

// -------------------------------------------------------
// 3. LinkedList Class (Placeholder - Not Implemented)
// -------------------------------------------------------
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int value) {
        // TODO: Implement
        std::cout << "LinkedList insert - not implemented.\n";
    }

    bool remove(int value) {
        // TODO: Implement
        return false;
    }

    bool search(int value) const {
        // TODO: Implement
        return false;
    }

    void display() const {
        // TODO: Implement
        std::cout << "LinkedList display - not implemented.\n";
    }

    ~LinkedList() {
        // Clean up nodes if you implement this fully
    }
};

// -------------------------------------------------------
// 4. Algorithms Namespace (Placeholder - Not Implemented)
// -------------------------------------------------------
namespace Algorithms {
    // Bubble Sort
    void bubbleSort(std::vector<int>& arr) {
        // TODO: Implement
        std::cout << "bubbleSort - not implemented.\n";
    }

    // Insertion Sort
    void insertionSort(std::vector<int>& arr) {
        // TODO: Implement
        std::cout << "insertionSort - not implemented.\n";
    }

    // Quick Sort
    void quickSort(std::vector<int>& arr, int low, int high) {
        // TODO: Implement
        std::cout << "quickSort - not implemented.\n";
    }

    // Binary Search
    int binarySearch(const std::vector<int>& arr, int target) {
        // TODO: Implement
        std::cout << "binarySearch - not implemented.\n";
        return -1;
    }
}

// -------------------------------------------------------
// 5. Timer Class (Placeholder - Minimal Implementation)
// -------------------------------------------------------
class Timer {
private:
    std::chrono::high_resolution_clock::time_point start_time;
    std::chrono::high_resolution_clock::time_point end_time;

public:
    void start() {
        start_time = std::chrono::high_resolution_clock::now();
    }

    void stop() {
        end_time = std::chrono::high_resolution_clock::now();
    }

    double getDurationMs() const {
        std::chrono::duration<double, std::milli> duration = end_time - start_time;
        return duration.count();
    }
};

// -------------------------------------------------------
// 6. CLI Functions for the Menu System
// -------------------------------------------------------

// Optional: clear the screen (platform-dependent)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void displayMainMenu() {
    std::cout << "\n=== DSA Toolbox ===\n"
        << "1. Stack Operations\n"
        << "2. Queue Operations\n"
        << "3. Linked List Operations\n"
        << "4. Sorting Algorithms\n"
        << "5. Binary Search\n"
        << "6. Exit\n"
        << "Enter your choice: ";
}

// Handle Stack menu
void handleStackOperations() {
    Stack stack; // default capacity = 100
    int choice, value;

    while (true) {
        std::cout << "\n=== Stack Operations ===\n"
            << "1. Push\n"
            << "2. Pop\n"
            << "3. Peek\n"
            << "4. Display\n"
            << "5. Back to Main Menu\n"
            << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            std::cout << "Enter value to push: ";
            std::cin >> value;
            if (stack.push(value)) {
                std::cout << "Pushed " << value << " onto the stack.\n";
            }
            else {
                std::cout << "Stack overflow!\n";
            }
            break;
        case 2:
            if (stack.pop()) {
                std::cout << "Popped top value from stack.\n";
            }
            else {
                std::cout << "Stack is empty!\n";
            }
            break;
        case 3:
            if (!stack.isEmpty()) {
                std::cout << "Top value: " << stack.peek() << "\n";
            }
            else {
                std::cout << "Stack is empty!\n";
            }
            break;
        case 4:
            stack.display();
            break;
        case 5:
            return; // go back to main menu
        default:
            std::cout << "Invalid choice!\n";
        }
    }
}

// Handle Queue menu (Placeholder)
void handleQueueOperations() {
    std::cout << "Queue operations - Coming soon!\n";
    // TODO: Implement actual queue operations
}

// Handle Linked List menu (Placeholder)
void handleLinkedListOperations() {
    std::cout << "Linked List operations - Coming soon!\n";
    // TODO: Implement actual linked list operations
}

// Handle Sorting menu (Placeholder)
void handleSortingOperations() {
    std::cout << "Sorting algorithms - Coming soon!\n";
    // TODO: Implement bubbleSort, insertionSort, quickSort
}

// Handle Binary Search (Placeholder)
void handleBinarySearch() {
    std::cout << "Binary Search - Coming soon!\n";
    // TODO: Implement binary search
}

// -------------------------------------------------------
// 7. main() - Program Entry
// -------------------------------------------------------
int main() {
    int choice;

    while (true) {
        displayMainMenu();
        std::cin >> choice;

        // Validate input
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
            handleQueueOperations();
            break;
        case 3:
            handleLinkedListOperations();
            break;
        case 4:
            handleSortingOperations();
            break;
        case 5:
            handleBinarySearch();
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
