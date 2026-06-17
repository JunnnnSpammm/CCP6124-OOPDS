#include <iostream>
#include <string>
#include "DynQueue.h"

int main() {
    // --- Demonstration 1: Integer Queue ---
    std::cout << "====================================\n";
    std::cout << "Demonstrating Integer Dynamic Queue\n";
    std::cout << "====================================\n";
    
    DynQueue<int> intQueue;
    int catchInt;

    std::cout << "Enqueuing 5, 10, 15...\n";
    intQueue.enqueue(5);
    intQueue.enqueue(10);
    intQueue.enqueue(15);
    std::cout << "Current Queue Size: " << intQueue.size() << "\n\n";

    std::cout << "Dequeuing items:\n";
    while (!intQueue.isEmpty()) {
        intQueue.dequeue(catchInt);
        std::cout << "Dequeued: " << catchInt << "\n";
    }
    std::cout << "Current Queue Size: " << intQueue.size() << "\n\n";


    // --- Demonstration 2: String Queue ---
    std::cout << "====================================\n";
    std::cout << "Demonstrating String Dynamic Queue\n";
    std::cout << "====================================\n";

    DynQueue<std::string> stringQueue;
    std::string catchStr;

    std::cout << "Enqueuing names: Alice, Bob, Charlie...\n";
    stringQueue.enqueue("Alice");
    stringQueue.enqueue("Bob");
    stringQueue.enqueue("Charlie");
    std::cout << "Current Queue Size: " << stringQueue.size() << "\n\n";

    // Dequeue just one to show partial removal
    stringQueue.dequeue(catchStr);
    std::cout << "Dequeued front item: " << catchStr << "\n";
    std::cout << "Current Queue Size after 1 dequeue: " << stringQueue.size() << "\n\n";

    std::cout << "Clearing the rest of the queue...\n";
    stringQueue.clear();
    std::cout << "Is queue empty now? " << (stringQueue.isEmpty() ? "Yes" : "No") << "\n";

    // --- Demonstration 3: Exception Handling ---
    std::cout << "\nAttempting to dequeue from the empty string queue:\n";
    try {
        stringQueue.dequeue(catchStr);
    } catch (const std::underflow_error& e) {
        std::cout << "Caught Expected Exception: " << e.what() << "\n";
    }

    return 0;
}

/*
Sample Output: 

====================================
Demonstrating String Dynamic Queue
====================================
Enqueuing names: Alice, Bob, Charlie...
Current Queue Size: 3

Dequeued front item: Alice
Current Queue Size after 1 dequeue: 2

Clearing the rest of the queue...
Is queue empty now? Yes

Attempting to dequeue from the empty string queue:
*/