#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
    list<int> myList;
    list<int>::iterator iter;

    for (int x = 0; x < 100; x += 10)
        myList.push_back(x);

    // Display the values
    for (iter = myList.begin(); iter != myList.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    myList.reverse();

    // Display the values again
    for (iter = myList.begin(); iter != myList.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    return 0;
}

/*
Sample Output: 

0 10 20 30 40 50 60 70 80 90 
90 80 70 60 50 40 30 20 10 0 
*/