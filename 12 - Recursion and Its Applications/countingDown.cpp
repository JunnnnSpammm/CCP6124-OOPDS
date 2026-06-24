#include <iostream>
using namespace std;

void sign(int n)
{
    if (n <= 0) return;
    
    cout << n << " ";
    sign(n - 1);
}

int main()
{
    int number;

    cout << "Enter a positive integer: ";
    cin >> number;

    cout << "Counting down using recursion: ";
    sign(number);
    cout << endl;

    return 0;
}

/*
Sample Output: 

Enter a positive integer: 6
Counting down using recursion: 6 5 4 3 2 1 
*/