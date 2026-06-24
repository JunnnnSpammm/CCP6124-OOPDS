#include <iostream>
using namespace std;

void printStar(int num);

int main()
{
    int x = 10;
    printStar(x);
    return 0;
}

void printStar(int num)
{
    if(num > 0)
    {
        for(int x = 0; x < num; x++)
            cout << '*' ;
        cout << endl;
        printStar(num - 1);
    }
}

/*
Sample Output: 

**********
*********
********
*******
******
*****
****
***
**
*
*/