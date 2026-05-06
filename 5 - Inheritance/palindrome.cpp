#include <iostream>
#include <string>

using namespace std;

class Pstring : public string
{
    public:
        Pstring(string s) : string(s) {}

        bool isPalindrome()
        {
            int length = this->length();
        
            if (length <= 1) return true;

            for (int i = 0; i < length / 2; i++)
            {
                if ((*this)[i] != (*this)[length - 1 - i])
                    return false;
            }

            return true;
        }
};

int main() {
    string userInput;

    cout << "--- Palindrome Checker ---" << endl;
    cout << "Enter a string to test: ";
    getline(cin, userInput);

    Pstring myPstring(userInput);

    if (myPstring.isPalindrome())
        cout << "\"" << userInput << "\" is a palindrome!" << std::endl;
    else 
        cout << "\"" << userInput << "\" is not a palindrome." << std::endl;

    return 0;
}

/*
Sample Output:

--- Palindrome Checker ---
Enter a string to test: noon
"noon" is a palindrome!
*/