#include <iostream>
#include <limits>
using namespace std;

void odd(int a);
void even(int a);
void addSum(int a, int &sum);
void getMax(int a, int& max);
void getMin(int a, int& min);

int main()
{
    int i, sum = 0;
    int minOdd = numeric_limits<int>::max();
    int maxEven = numeric_limits<int>::min();
    bool foundOdd = false;
    bool foundEven = false;

    do
    {
        cout << "Type a number (0 to exit): ";
        cin >> i;

        if (i == 0) break;

        addSum(i, sum);
        
        if (i % 2 != 0) {
            getMin(i, minOdd);
            foundOdd = true;
            cout << "Number is odd.\n";
        } else {
            getMax(i, maxEven);
            foundEven = true;
            cout << "Number is even.\n";
        }

    } while (i != 0);

    cout << "\n--- Results ---" << endl;
    cout << "Total Sum: " << sum << endl;

    if (foundOdd)
        cout << "Minimum Odd Number: " << minOdd << endl;
    else
        cout << "Minimum Odd Number: None entered." << endl;

    if (foundEven)
        cout << "Maximum Even Number: " << maxEven << endl;
    else
        cout << "Maximum Even Number: None entered." << endl;

    return 0;
}

void addSum(int a, int& sum)
{
    sum += a;
}

void getMax(int a, int& max)
{
    if (a > max)
        max = a;
}

void getMin(int a, int& min)
{
    if (a < min)
        min = a;
}

void odd(int a) {
    if ((a % 2) != 0) cout << "Number is odd.\n";
    else even(a);
}

void even(int a) {
    if ((a % 2) == 0) cout << "Number is even.\n";
    else odd(a);
}