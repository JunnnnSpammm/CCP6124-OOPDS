#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class DynIntQueue
{
    struct QueueNode
    {
        int value;
        QueueNode *next;
        QueueNode(int value1, QueueNode *next1 = nullptr)
        {
            value = value1;
            next = next1;
        }
    };
    QueueNode *front;
    QueueNode *rear;

    public:
        DynIntQueue();
        ~DynIntQueue();
        
        void enqueue(int);
        void dequeue(int &);
        bool isEmpty() const;
        void clear();
};

DynIntQueue::DynIntQueue()
{
    front = nullptr;
    rear = nullptr;
}

DynIntQueue::~DynIntQueue()
{
    QueueNode* garbage = front;
    while (garbage != nullptr)
    {
        front = front->next;
        garbage->next = nullptr;
        delete garbage;
        garbage = front;
    }
}

void DynIntQueue::enqueue(int num)
{
    if (isEmpty())
    {
        front = new QueueNode(num);
        rear = front;
    }
    else
    {
        rear->next = new QueueNode(num);
        rear = rear->next;
    }
}

void DynIntQueue::dequeue(int& num)
{
    QueueNode* temp = nullptr;
    if (isEmpty())
    {
        cout << "The queue is empty.\n";
        exit(1);
    }
    else
    {
        num = front->value;
        temp = front;
        front = front->next;
        delete temp;
    }
}

bool DynIntQueue::isEmpty() const
{
    if (front == nullptr)
        return true;
    else
        return false;
}

void DynIntQueue::clear()
{
    int value;          // Dummy variable for dequeue
    
    while (!isEmpty())
        dequeue(value);
}

int main()
{
    DynIntQueue iQueue;
    
    for (int k = 1; k <= 5; k++)
        iQueue.enqueue(k*k);
    
    while (!iQueue.isEmpty())
    {
        int value;
        iQueue.dequeue(value);
        cout << value << " ";
    }

    return 0;
}

/*
Sample Output: 

1 4 9 16 25
*/