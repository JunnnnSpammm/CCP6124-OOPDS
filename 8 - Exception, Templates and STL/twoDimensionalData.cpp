#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

void getData(ifstream& inFile, vector<string>& tourists,
             vector<vector<string> >& destinations)
{
    int count;
    inFile >> count;

    tourists.resize(count);
    destinations.resize(count);

    int index;
    int count2;
    std::string word;

    for (int i = 0; i < count; i++)
    {
        inFile >> index >> word;
        tourists[index] = word;
    }

    for (int i = 0; i < count; i++)
    {
        inFile >> index >> count2;

        for (int n = 0; n < count2; n++)
        {
            inFile >> word;
            destinations[index].push_back(word);
        }
    }
}

// Returns the index of a string in a vector of strings, or
// -1 if the searched for string is not found.
int indexOf(vector<string> vec, string name)
{
    for (int k = 0; k < vec.size(); k++ )
    {
        if (name == vec[k]) return k;
    }
    return -1;
}

int main(int argc, char* argv[])
{
    ifstream inFile("lab08pc02_tourists.txt");
    if (!inFile)
    {
        cout << "Cannot open the file lab08pc02_tourists.txt";
        return 1;
    }

    vector <string> tourists;
    vector<vector<string> > destinations;
    getData(inFile, tourists, destinations);

    // Print names of tourists
    cout << "Names of tourists are:\n";
    for (int k = 0; k < tourists.size(); k++)
    {
        cout << tourists[k] << endl;
    }

    // Interact with the user
    cout << "Enter name of tourists as prompted, type 'quit' to end.\n";
    string name;
    while (true)
    {
        cout << "Tourist? ";
        cin >> name;
        if (name == "quit") break;
        int index = indexOf(tourists, name);
        if (index == -1)
        {
            cout << "There is no such tourist." << endl;
            continue;
        }
    
        // print the list of destinations
        vector<string>::iterator iter = destinations[index].begin();
        while (iter != destinations[index].end())
        {
            cout << *iter << " ";
            iter ++;
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}

/*
Sample Output: 

Names of tourists are:
Ali
AhKao
Muthu
Enter name of tourists as prompted, type 'quit' to end.
Tourist? Ali
Putrajaya Cyberjaya KL 
Tourist? AhKao
Cyberjaya 
Tourist? Muthu

Tourist? quit
*/