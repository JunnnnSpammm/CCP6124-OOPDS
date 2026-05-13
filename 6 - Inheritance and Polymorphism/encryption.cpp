#include <iostream>
#include <fstream>
using namespace std;

class Encryption
{
    protected:
        ifstream inFile;
        ofstream outFile;
        int key;

    public:
        Encryption(char* inFileName, char* outFileName);
        ~Encryption();
        virtual char transform(char ch) = 0;
        void encrypt();
        void setKey(int key){ this->key = key;}
};

Encryption::Encryption(char* inFileName, char* outFileName)
{
    inFile.open(inFileName);
    outFile.open(outFileName);
    
    if (!inFile)
    {
        cout << "The file " << inFileName << " cannot be opened.";
        exit(1);
    }
    
    if (!outFile)
    {
        cout << "The file " << outFileName << " cannot be opened.";
        exit(1);
    }
}

Encryption::~Encryption()
{
    inFile.close();
    outFile.close();
}

void Encryption::encrypt()
{
    char ch;
    char transCh;

    inFile.get(ch);
    while (!inFile.fail())
    {
        transCh = transform(ch);
        outFile.put(transCh);
        inFile.get(ch);
    }
}

class SimpleEncryption : public Encryption
{
    public:
        SimpleEncryption(char* inFileName, char* outFileName) : Encryption(inFileName, outFileName) {}

        virtual char transform(char ch) 
        {
            return ch + key;
        }
};

int main()
{
    char fileIn[] = "fileIn.txt";
    char fileOut[] = "fileOut.txt";

    SimpleEncryption obfuscate(fileIn, fileOut);

    // Get and set the key to be used for the encryption
    cout << "Enter a small integer as an encryption key -> ";
    int key;
    cin >> key;
    obfuscate.setKey(key);

    // Perform the encryption
    obfuscate.encrypt();

    return 0;
}

/*
Sample Output: 

fileIn.txt: The quick brown fox jump over the lazy dog.

Enter a small integer as an encryption key -> 4

fileOut.txt: Xli$uymgo$fvs{r$js|$nyqt$sziv$xli$pe~}$hsk2
*/