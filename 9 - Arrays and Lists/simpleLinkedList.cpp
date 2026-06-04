#include <iostream>

struct ListNode {
    double value;
    ListNode* next;

    ListNode(double val, ListNode* nextNode = nullptr) {
        value = val;
        next = nextNode;
    }
};

class LinkedList {
private:
    ListNode* head;

public:
    LinkedList() {
        head = nullptr; 
    }

    LinkedList(const LinkedList& other) {
        if (other.head == nullptr) {
            head = nullptr;
            return;
        }
        head = new ListNode(other.head->value);
        ListNode* currentOther = other.head->next;
        ListNode* currentNew = head;

        while (currentOther != nullptr) {
            currentNew->next = new ListNode(currentOther->value);
            currentNew = currentNew->next;
            currentOther = currentOther->next;
        }
    }

    ~LinkedList() {
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    }

    void add(double x) {
        head = new ListNode(x, head);
    }

    bool isMember(double x) const {
        ListNode* current = head;
        while (current != nullptr) {
            if (current->value == x) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void print() const {
        if (head == nullptr) {
            std::cout << "[ Empty List ]\n";
            return;
        }

        ListNode* current = head;
        std::cout << "Head -> ";
        
        while (current != nullptr) {
            std::cout << "[" << current->value << "] -> ";
            current = current->next; // Move to the next node
        }
        
        std::cout << "nullptr\n";
    }
};

int main() {
    std::cout << "Creating an empty list...\n";
    LinkedList myList;
    
    std::cout << "Printing initial list: ";
    myList.print();
    std::cout << "\n";

    std::cout << "Adding 5.5 to the list...\n";
    myList.add(5.5);
    myList.print();
    std::cout << "\n";

    std::cout << "Adding 12.8 to the list...\n";
    myList.add(12.8);
    myList.print();
    std::cout << "\n";

    std::cout << "Adding 99.1 to the list...\n";
    myList.add(99.1);
    myList.print();
    std::cout << "\n";

    std::cout << "--- Final Linked List Structure ---\n";
    myList.print();
    std::cout << "\n";

    return 0;
}

/*
Sample Output: 

Creating an empty list...
Printing initial list: [ Empty List ]

Adding 5.5 to the list...
Head -> [5.5] -> nullptr

Adding 12.8 to the list...
Head -> [12.8] -> [5.5] -> nullptr

Adding 99.1 to the list...
Head -> [99.1] -> [12.8] -> [5.5] -> nullptr

--- Final Linked List Structure ---
Head -> [99.1] -> [12.8] -> [5.5] -> nullptr
*/