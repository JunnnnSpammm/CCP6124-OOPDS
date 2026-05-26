#include <iostream>
using namespace std;

class IntRange
{
    private:
        int input;  // For user input
        int lower;
        int upper;

    public:
        // Exception class
        class OutOfRange
        {
            public:
                int value;
                OutOfRange(int i) { value = i; }
        };

        IntRange(int low, int high)
        {
            lower = low;
            upper = high;
        }

        int getInput()
        {
            cin >> input;
            if (input < lower || input > upper)
                throw OutOfRange(input);
            return input;
        }
};

int main()
{
    IntRange range(5, 10);
    int userValue;

    cout << "Enter a value in the range 5 - 10: ";
    try
    {
        userValue = range.getInput(); // software testing: please enter 12
        cout << "You entered " << userValue << endl;
    }
    catch (IntRange::OutOfRange ex)
    {
        cout << "That value " << ex.value
             << " is out of range.\n";
    }

    cout << "End of the program.\n";
    return 0;
}

/*
Sample Output: 

Enter a value in the range 5 - 10: 12
That value 12 is out of range.
End of the program.
*/