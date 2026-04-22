#include <iostream>
#include <iomanip>
using namespace std;

class NumberArray
{
    private:
        double *aPtr;
        int arraySize;

    public:
        NumberArray(const NumberArray &);
        NumberArray(int size, double value);
        ~NumberArray() { if (arraySize > 0) delete [] aPtr; }

        void print() const;
        void setValue(double value);
};

NumberArray::NumberArray(const NumberArray &obj)
{
    arraySize = obj.arraySize;
    aPtr = new double[arraySize];
    for(int index = 0; index < arraySize; index++)
        aPtr[index] = obj.aPtr[index];
}

NumberArray::NumberArray(int size, double value)
{
    arraySize = size;
    aPtr = new double[arraySize];
    setValue(value);
}

void NumberArray::setValue(double value)
{
    for(int index = 0; index < arraySize; index++)
        aPtr[index] = value;
}

void NumberArray::print() const
{
    for(int index = 0; index < arraySize; index++)
        cout << aPtr[index] << " ";
}

int main()
{
    NumberArray first(3, 10.5);

    NumberArray second = first;

    cout << setprecision(2) << fixed << showpoint;

    cout << "Value stored in first object is ";
    first.print();

    cout << "\nValue stored in second object is ";
    second.print();

    cout << "\nOnly the value in second object will "
         << "be changed.\n";
    second.setValue(20.5);

    cout << "Value stored in first object is ";
    first.print();

    cout << endl << "Value stored in second object is ";
    second.print();

    return 0;
}

/*
Sample Output: 

Value stored in first object is 10.50 10.50 10.50 
Value stored in second object is 10.50 10.50 10.50 
Only the value in second object will be changed.
Value stored in first object is 10.50 10.50 10.50 
Value stored in second object is 20.50 20.50 20.50
*/