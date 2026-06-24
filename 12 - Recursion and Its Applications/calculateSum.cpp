#include <iostream>
using namespace std;

int calculateSum(int num);

int main()
{
    int x = 10;
    cout << calculateSum(x) << endl;
    return 0;
}

int calculateSum(int num)
{
    if(num <= 0)
        return 0;
    else
        return calculateSum(num - 1) + num;
}

/*
Sample Output: 

55
*/