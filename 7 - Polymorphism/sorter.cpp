#include <algorithm>
#include <iostream>
using namespace std;

class Sorter
{
    private:
        int *p;
        int size;
        void sort(int n);
        virtual bool compare(int x, int y) = 0;

    public:
        void setArray(int *arr, int size)
        {
            p = arr;
            this->size = size;
        }

        void sort()
        {
            sort(size);
        }
};

void Sorter::sort(int n)
{
    if (n <= 1)
        return;

    //find pos of largest in p[0..n-1]
    //and put it at end of p[0..n-1]

    int maxPos = 0;
    for (int k = 1; k < n; k++)
        if (compare(p[k], p[maxPos]))
        {
            maxPos = k;
        }

    swap(p[n-1], p[maxPos]);
    sort(n-1);
}

class IncrSorter : public Sorter
{
    private:
        bool compare(int x, int y) override
        {
            return x > y;
        }
};

class DecrSorter : public Sorter
{
    private:
        bool compare(int x, int y) override
        {
            return x < y;
        }
};

void printArray(int [], int);

// Example of usage
int main()
{
    int a[5] = {23, 56, 23, -45, 52};

    IncrSorter incSorter;
    incSorter.setArray(a, 5);
    incSorter.sort();
    printArray(a, 5);

    DecrSorter decSorter;
    decSorter.setArray(a, 5);
    decSorter.sort();
    printArray(a, 5);

    return 0;
}

void printArray(int a[ ], int size)
{
    for (int k = 0; k < size; k++)
        cout << a[k] << " ";
    
    cout << endl;
}

/*
Sample Output: 

-45 23 23 52 56 
56 52 23 23 -45 
*/