#include <iostream>
using namespace std;

class DayOfYear
{
    private:
        int day;
        static const string month[12];

    public:
        DayOfYear(int d)
        {
            if (d < 1 || d > 365) 
                day = 1;
            else
                day = d;
        }

        void print()
        {
            if (day < 31) // January
                cout << month[0] << " " << day;
            else if (day < 59) // February
                cout << month[1] << " " << day - 31;
            else if (day < 90) // March
                cout << month[2] << " " << day - 59;
            else if (day < 120) // April
                cout << month[3] << " " << day - 90;
            else if (day < 151) // May
                cout << month[4] << " " << day - 120;
            else if (day < 181) // June
                cout << month[5] << " " << day - 151;
            else if (day < 212) // July
                cout << month[6] << " " << day - 181;
            else if (day < 243) // August
                cout << month[7] << " " << day - 212;
            else if (day < 273) // September
                cout << month[8] << " " << day - 243;
            else if (day < 301) // October
                cout << month[9] << " " << day - 273;
            else if (day < 334) // November
                cout << month[10] << " " << day - 301;
            else // December
                cout << month[11] << " " << day - 334;
        }
};

const string DayOfYear::month[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

int main()
{
    int input;

    cout << "Enter day (1-365): ";
    cin >> input;

    if (input < 1 || input > 365) {
        cout << "Invalid input. Please enter a number between 1 and 365." << endl;
    } else {
        DayOfYear day(input);
        day.print();
    }

    return 0;
}

/*
Sample Output: 

Enter day (1-365): 169
June 18
*/