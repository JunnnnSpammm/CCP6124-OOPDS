#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
void output(vector<T> v)
{
    for (size_t i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

template <typename T>
void rotateleft(vector<T>& v)
{
    if (v.empty()) return;
    
    T first = v[0];
    
    for (size_t i = 0; i < v.size() - 1; ++i)
    {
        v[i] = v[i + 1];
    }
    
    v[v.size() - 1] = first;
}

int main() {
    vector<int> intVec = {1, 3, 5, 7};
    
    for (size_t i = 0; i < intVec.size(); ++i)
    {
        output(intVec);
        rotateleft(intVec);
    }
    
    cout << endl;

    vector<string> strVec = {"a", "b", "c", "d", "e"};
    
    for (size_t i = 0; i < strVec.size(); ++i)
    {
        output(strVec);
        rotateleft(strVec);
    }

    return 0;
}

/*
Sample Output: 

1 3 5 7 
3 5 7 1 
5 7 1 3 
7 1 3 5 

a b c d e 
b c d e a 
c d e a b 
d e a b c 
e a b c d 
*/