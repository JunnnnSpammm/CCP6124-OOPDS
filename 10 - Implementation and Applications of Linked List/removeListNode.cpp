#include <iostream>
using namespace std;

class NumberList {
private:
    struct ListNode
    {
        double value;
        ListNode *next;

        ListNode(double value1, ListNode *next1 = nullptr)
        {
            value = value1;
            next = next1;
        }
    };

    ListNode* head;

public:
    NumberList() { head = nullptr; }
    ~NumberList();

    void appendNode(double num);
    void remove(double x);
    void displayList() const;
};

void NumberList::appendNode(double num) {
    ListNode* newNode = new ListNode(num);

    if (!head) {
        head = newNode;
    } else {
        ListNode* nodePtr = head;
        while (nodePtr->next != nullptr) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

void NumberList::remove(double x) {
    if (!head) return;

    ListNode* nodePtr = head;
    ListNode* previousNode = nullptr;

    if (head->value == x) {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
        return;
    }

    while (nodePtr != nullptr && nodePtr->value != x) {
        previousNode = nodePtr;
        nodePtr = nodePtr->next;
    }

    if (nodePtr) {
        previousNode->next = nodePtr->next;
        delete nodePtr;
    }
}

void NumberList::displayList() const {
    ListNode* nodePtr = head;
    while (nodePtr) {
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
    }
}

NumberList::~NumberList() {
    ListNode* nodePtr = head;
    while (nodePtr != nullptr) {
        ListNode* nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

int main() {
    NumberList list;

    list.appendNode(34.2);
    list.appendNode(56.4);
    list.appendNode(89.1);
    
    cout << "--- Initial List ---" << endl;
    list.displayList();

    cout << "--- Removing 89.1 (Tail) ---" << endl;
    list.remove(89.1);
    list.displayList();

    cout << "--- Adding new elements ---" << endl;
    list.appendNode(12.5);
    list.displayList();

    cout << "--- Removing 34.2 (Head) ---" << endl;
    list.remove(34.2);
    list.displayList();

    return 0;
}

/*
Sample Output: 

--- Initial List ---
34.2
56.4
89.1
--- Removing 89.1 (Tail) ---
34.2
56.4
--- Adding new elements ---
34.2
56.4
12.5
--- Removing 34.2 (Head) ---
56.4
12.5
*/