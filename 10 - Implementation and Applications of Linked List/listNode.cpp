#include <iostream>
using namespace std;

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

int main()
{
    ListNode *p = new ListNode(56.4);
    p = new ListNode(34.2, p);
    cout << (*p).value << endl << p->value << endl;

    ListNode *temp = p->next; 
    delete p;
    p = nullptr;
    delete temp;
    temp = nullptr;

    p = new ListNode(56.4);
    p = new ListNode(34.2, p);
    ListNode *q = p->next;
    cout << q->value << endl;

    delete q;
    q = nullptr;
    delete p;
    p = nullptr;

    p = new ListNode(56.4, new ListNode(31.5));
    q = p;
    while (q->next->next != nullptr)
        q = q->next;
    cout << q->value << endl;

    temp = p->next; 
    delete p; 
    p = nullptr;
    q = nullptr;
    delete temp; 
    temp = nullptr;

    return 0;
}

/*
Sample Output: 

34.2
34.2
56.4
56.4
*/