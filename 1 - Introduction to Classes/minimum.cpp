#include <iostream>
using namespace std;

void ReadArray(int a[], int size)
{
    cout << "Enter " << size << " elements: " << endl;

    for (int i=0; i<size; i++)
    {
        cout << "-> ";
        cin >> a[i];
    }
}

int getMax(int a[], int size)
{
    int Maximum = a[0];

    for (int i = 1; i < size; ++i)
    {
        if (a[i] > Maximum)
            Maximum = a[i];
    }

    return Maximum;
}

void swap(int &x,int &y)
{
    int t = x;

    x = y;
    y = t;
}

void sortArray(int a[], int size)
{
    for (int i=0; i<size-1; i++)
        for (int j=i+1; j<size; j++)
        { //big one bubbles to the end
            if (a[i] > a[j])
            swap(a[i],a[j]);
        }
}

void printArray(int a[],int size)
{
    for (int i = 0; i < size; ++i)
        cout << a[i] << " ";
    
    cout << endl;
}

int main()
{
    // The members of the array
    int Numbers[ ] = {8, 25, 36, 44, 52, 60, 75, 89};
    int Minimum = Numbers[0];
    int a = 8;

    // Compare the members
    for (int i = 1; i < a; ++i)
    {
        if (Numbers[i] < Minimum)
            Minimum = Numbers[i];
    }

    // Announce the result
    cout << "The lowest member value of the array is "
         << Minimum << "." << endl;
    cout << "\n\n";

    const int size = 4;
    int Numbers2[size];

    ReadArray(Numbers2, size);
    int Minimum2 = Numbers2[0];

    // Compare the member
    for (int i = 1; i < size; ++i)
    {
        if (Numbers2[i] < Minimum2)
            Minimum2 = Numbers2[i];
    }

    // Announce the result
    cout << "The Minumum2 = " << Minimum2 << endl;

    //compute the Maximum and announce the result
    int Maximum = getMax(Numbers2, size);
    cout << "The Maximum = " << Maximum << endl;
    sortArray(Numbers2,size);
    printArray(Numbers2,size);

    return 0;
}