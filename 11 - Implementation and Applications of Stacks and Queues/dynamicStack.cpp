#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class DynIntStack
{
    struct StackNode
    {
        int value;
        StackNode *next;

        StackNode(int value1, StackNode *next1 = NULL)
        {
            value = value1;
            next = next1;
        }
    };
    StackNode *top;
    
    public:
        DynIntStack() { top = nullptr; }
        ~DynIntStack();

        void push(int);
        void pop(int &);
        bool isEmpty() const;

    // Stack Exception
    class Underflow {};
};
    
void DynIntStack::push(int num)
{
    top = new StackNode(num, top);
};

void DynIntStack::pop(int &num)
{
    StackNode *temp;

    if (isEmpty()) { throw DynIntStack::Underflow(); }
    else
    {
        // Pop value off top of stack
        num = top->value;
        temp = top;
        top = top->next;
        delete temp;
    }
}

bool DynIntStack::isEmpty() const
{
    return top == nullptr;
}

DynIntStack::~DynIntStack()
{
    StackNode* garbage = top;
    while (garbage != nullptr)
    {
        top = top->next;

        garbage->next = nullptr;
        delete garbage;
        garbage = top;
    }
}

int main()
{
    DynIntStack stack;
    int popped_value;

    for (int value = 5; value <= 15; value = value + 5)
    {
        cout << "Push: " << value << "\n";
        stack.push(value);
    }
    cout << "\n";

    for (int k = 1; k <= 3; k++)
    {
        cout << "Pop: ";
        stack.pop(popped_value);
        cout << popped_value << endl;
    }

    try
    {
        cout << "\nAttempting to pop again... ";
        stack.pop(popped_value);
    }
    catch (DynIntStack::Underflow)
    {
        cout << "Underflow exception occurred.\n";
    }

    return 0;
}
/*
Sample Output: 

Push: 5
Push: 10
Push: 15

Pop: 15
Pop: 10
Pop: 5

Attempting to pop again... Underflow exception occurred.
*/