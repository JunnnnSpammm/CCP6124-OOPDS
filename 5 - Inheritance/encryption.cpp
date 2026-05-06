#include <iostream>
#include <string>

using namespace std;

class EncryptableString : public string
{
    public:
        EncryptableString(string s) : string(s) {}

        void encrypt()
        {
            for (char &c : *this) {
                if (c >= 'a' && c <= 'z') // Handle lowercase wrap-around (z -> a)
                    c = (c == 'z') ? 'a' : c + 1;
                else if (c >= 'A' && c <= 'Z') // Handle uppercase wrap-around (Z -> A)
                    c = (c == 'Z') ? 'A' : c + 1;
            }
        }
};

int main() {
    string userInput;
    
    cout << "--- String Encrypter ---\n";
    cout << "Enter a string to encrypt (or 'quit' to exit): ";

    while (getline(cin, userInput) && userInput != "quit") {
        EncryptableString myStr(userInput);

        myStr.encrypt();

        cout << "Encrypted version: " << myStr << "\n\n";
        cout << "Enter another string: ";
    }
    
    return 0;
}

/*
Sample Output:

--- String Encrypter ---
Enter a string to encrypt (or 'quit' to exit): Encryption
Encrypted version: Fodszqujpo

Enter another string: Password
Encrypted version: Qbttxpse

Enter another string: quit
*/