#include <iostream>
using namespace std;

class Numbers
{
    private:
        int number;

        static const string lessThan20[20];
        static const string tens[10];
        static const string hundred;
        static const string thousand;

    public:
        Numbers(int n)
        {
            if (n < 0)
                number = 0;
            else
                number = n;
        }

        void print()
        {
            if (number == 0)
            {
                cout << lessThan20[0];
            }
            else
            {
                int temp = number;

                if (temp >= 1000)
                {
                    cout << lessThan20[temp / 1000] << " " << thousand << " ";
                    temp %= 1000;
                }

                if (temp >= 100)
                {
                    cout << lessThan20[temp / 100] << " " << hundred << " ";
                    temp %= 100;
                }

                if (temp >= 20)
                {
                    cout << tens[temp / 10] << " ";
                    temp %= 10;
                }

                if (temp > 0)
                {
                    cout << lessThan20[temp] << " ";
                }

                cout << endl;
            }
        }
};

const string Numbers::lessThan20[] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", 
    "seventeen", "eighteen", "nineteen"
};

const string Numbers::tens[] = {
    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

const string Numbers::hundred = "hundred";

const string Numbers::thousand = "thousand";

int main()
{
    int input;

    cout << "Enter a positive integer (0-9999): ";
    cin >> input;

    if (input < 0 || input > 9999) {
        cout << "Invalid input. Please enter a number between 0 and 9999." << endl;
    } else {
        Numbers num(input);
        num.print();
    }

    return 0;
}

/*
Sample Output: 

Enter a positive integer (0-9999): 2334
two thousand three hundred thirty four 
*/