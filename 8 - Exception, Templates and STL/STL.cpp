#include <iostream>
#include <cstdlib>
#include <memory>

using namespace std;

class IndexOutOfRangeException
{
    public:
        const int index;
        IndexOutOfRangeException(int ix) : index(ix) {}
};

template <class T>
class SimpleVector
{
    private:
        unique_ptr<T []> aptr;
        int arraySize;

    public:
        SimpleVector(int s);                    // Constructor
        SimpleVector(const SimpleVector &obj);  // Copy constructor

        int size() const { return arraySize; }
        T &operator[](int);                     // Overloaded [] operator
        void print() const;                     // outputs the array elements
};

template <class T>
SimpleVector<T>::SimpleVector(int s)
{
    arraySize = s;
    aptr = make_unique<T[]>(s);
    for (int count = 0; count < arraySize; count++)
        aptr[count] = T();
}

template <class T>
SimpleVector<T>::SimpleVector(const SimpleVector &obj)
{
    arraySize = obj.arraySize;
    aptr = make_unique<T[]>(obj.arraySize);
    for (int count = 0; count < arraySize; count++)
        aptr[count] = obj[count];
}

template <class T>
T &SimpleVector<T>::operator[](int sub)
{
    if (sub < 0 || sub >= arraySize)
        throw IndexOutOfRangeException(sub);
    return aptr[sub];
}

template <class T>
void SimpleVector<T>::print() const
{
    for (int k = 0; k < arraySize; k++)
        cout << aptr[k] << " ";
    cout << endl;
}

template <class T>
class SearchableVector : public SimpleVector<T>
{
    public:
    SearchableVector(int s) : SimpleVector<T>(s) { }    // Constructor
    SearchableVector(const SearchableVector &obj);      // Copy constructor

    // Overloaded constructor with base class object parameter
    SearchableVector(const SimpleVector<T> &obj):SimpleVector<T>(obj) { }
    int findItem(T);
};

template <class T>
SearchableVector<T>::SearchableVector(const SearchableVector &obj) :
    SimpleVector<T>(obj)
{}

template <class T>
int SearchableVector<T>::findItem(T item)
{
    for (int count = 0; count < this->size(); count++)
    {
        if ((*this)[count] == item)
            return count;
    }
    return -1;
}

int main()
{
    const int SIZE = 5;
    SearchableVector<int> intTable(SIZE);
    SearchableVector<double> doubleTable(SIZE);

    for (int x = 0; x < SIZE; x++)
    {
        intTable[x] = (x * 2);
        doubleTable[x] = (x * 0.2);
    }

    cout << "These values are in intTable:\n";
    for (int x = 0; x < SIZE; x++)
        cout << intTable[x] << " ";
    cout << endl;
    cout << "These values are in doubleTable:\n";
    for (int x = 0; x < SIZE; x++)
        cout << doubleTable[x] << " ";
    cout << endl;

    int result;
    cout << "Searching for 6 in intTable.\n";
    result = intTable.findItem(6);
    if (result == -1)
        cout << "6 was not found in intTable.\n";
    else
        cout << "6 was found at subscript "
             << result << endl;
    
    cout << "Searching for 1.23 in doubleTable.\n";
    result = doubleTable.findItem(1.23);
    if (result == -1)
        cout << "1.23 was not found in doubleTable.\n";
    else
        cout << "1.23 was found at subscript "
             << result << endl;
    
    return 0;
}

/*
Sample Output: 

These values are in intTable:
0 2 4 6 8 
These values are in doubleTable:
0 0.2 0.4 0.6 0.8 
Searching for 6 in intTable.
6 was found at subscript 3
Searching for 1.23 in doubleTable.
1.23 was not found in doubleTable.
*/