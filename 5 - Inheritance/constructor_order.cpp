#include <iostream>
// #include <memory>

using namespace std;

class Base
{
    public:
        Base()
        {
            cout << "Entering the base.\n";
        }

        virtual ~Base()
        {
            cout << "Leaving the base.\n";
        }
};

class Camp : public Base
{
    public:
        Camp()
        {
            cout << "Entering the camp.\n";
        }

        virtual ~Camp()
        {
            cout << "Leaving the camp.\n";
        }
};

int main()
{
    // shared_ptr<Camp> outpost = make_shared<Camp> ();
    Camp* outpost = new Camp;
    delete outpost;

    outpost = nullptr;

    return 0;
}

/*
Sample Output: 

Entering the base.
Entering the camp.
Leaving the camp.
Leaving the base.
*/