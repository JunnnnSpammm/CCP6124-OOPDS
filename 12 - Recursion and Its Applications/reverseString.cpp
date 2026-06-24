#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void reverseString(string str, int pos);

int main(int argc, char* argv[])
{
    string names = "Adam and Eve";
    reverseString(names, 0);
    return 0;
}

void reverseString(string str, int pos)
{
    if(pos < str.length())
    {
        reverseString(str, pos+1);
        cout << str[pos];
    }
}

/*
Sample Output: 

evE dna madA
*/