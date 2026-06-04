#include <iostream>
#include <string>
using namespace std;

template <class T>
class LinkedList
{
    protected:
        struct ListNode
        {
            T value;
            ListNode *next;
            ListNode(T value1, ListNode *next1 = nullptr)
            {
                value = value1;
                next = next1;
            }
        };

        ListNode *head;

    public:
        LinkedList() { head = nullptr; }    // Constructor
        ~LinkedList();                      // Destructor
        void add(T value);
        void remove(T value);
        void displayList() const;
};

template <class T>
void LinkedList<T>::add(T value)
{
    if (head == nullptr)
        head = new ListNode(value);
    else
    {
        // The list is not empty
        ListNode *nodePtr = head;
        while (nodePtr->next != nullptr)
            nodePtr = nodePtr->next;

        // Create a new node and put it after the last node
        nodePtr->next = new ListNode(value);
    }
}

template <class T>
void LinkedList<T>::remove(T value)
{
    ListNode *nodePtr, *previousNodePtr;

    // If the list is empty, do nothing
    if (!head) return;

    // Determine if the first node is the one to delete
    if (head->value == value)
    {
        nodePtr = head;
        head = head->next;
        delete nodePtr;
    }
    else
    {
        nodePtr = head;
        while (nodePtr != nullptr && nodePtr->value != value)
        {
            previousNodePtr = nodePtr;
            nodePtr = nodePtr->next;
        }
    // Link the previous node to the node after nodePtr
    // then delete nodePtr
        if (nodePtr)
        {
            previousNodePtr->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

template <class T>
void LinkedList<T>::displayList() const
{
    ListNode *nodePtr = head;
    while (nodePtr)
    {
        cout << nodePtr->value << " ";
        nodePtr = nodePtr->next;
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    ListNode *nodePtr = head;   // Start at head of list
    while (nodePtr != nullptr)
    {
        ListNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

int main() {
    LinkedList<string> list;

    list.add("A");
    list.add("C");
    list.add("E");
    list.add("F");

    cout << "Here are the initial names:\n";
    list.displayList();
    cout << "\n\n";

    cout << "Now removing E.\n\n";
    list.remove("E");
    cout << "Here are the remaining elements.\n";
    list.displayList();
    cout << endl;
    
    return 0;
}

/*
Sample Output: 

Here are the initial names:
A C E F 

Now removing E.

Here are the remaining elements.
A C F 
*/