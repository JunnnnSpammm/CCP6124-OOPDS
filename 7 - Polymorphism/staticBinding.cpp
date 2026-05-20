#include <iostream>
// #include <memory>
#include <cstdlib>
using namespace std;

class Base
{
    protected:
        int baseVar;

    public:
        Base(int val = 2)
        {
            baseVar = val;
        }

        int getVar() const
        // virtual int getVar() const
        {
            return baseVar;
        }
};

class Derived : public Base
{
    private:
        int deriVar;

    public:
        Derived(int val = 100)
        {
            deriVar = val;
        }

        int getVar() const
        {
            return deriVar;
        }
};

int main()
{
    // shared_ptr<Base> optr = make_shared<Derived>();
    Base* optr = new Derived;
    cout << optr->getVar() << endl;

    delete optr;
    optr = nullptr;

    return 0;
}

/*
Sample Output: 

2
*/