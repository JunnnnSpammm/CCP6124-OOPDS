#include <iostream>
#include <string>
using namespace std;

class Date
{
    private:
        int day;
        int month;
        int year;

        bool isValid(int d, int m, int y)
        {
            if (m > 12 || m < 1 || d < 1)
                return false;

            switch (m) {
                case 2:
                    if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
                        return d <= 29;
                    } else {
                        return d <= 28;
                    }
                case 4:
                case 6:
                case 9:
                case 11:
                    return d <= 30;
                default:
                    return d <= 31;
            }
        }

        string getMonthName() const
        {
            static const string months[] = {
                "January", "February", "March", "April", "May", "June",
                "July", "August", "September", "October", "November", "December"
            };

            return months[month - 1];
        }

    public:
        // Default Constructor
        Date() : day(1), month(1), year(2001) {}

        Date(int d, int m, int y) : Date() {
            if (isValid(d, m, y))
            {
                day = d;
                month = m;
                year = y;
            }
            else
                {
                std::cout << "Invalid date provided! Falling back to 1/1/2001.\n";
            }
        }

        void printMDY() const
        { cout << month << "/" << day << "/" << year << endl; }

        void printLongDate() const
        { cout << getMonthName() << " " << day << ", " << year << endl; }

        void printEuroDate() const
        { cout << day << " " << getMonthName() << " " << year << endl; }
};

int main() {
    std::cout << "Valid Date (15, 3, 2016):" << std::endl;
    Date d1(15, 3, 2016);
    d1.printMDY();
    d1.printLongDate();
    d1.printEuroDate();

    std::cout << "\nInvalid Date (13, 45, 2018) - Should default to 1/1/2001:" << std::endl;
    Date d2(13, 45, 2018);
    d2.printEuroDate();

    std::cout << "\nLeap Year Check (29, 2, 2024):" << std::endl;
    Date d3(29, 2, 2024);
    d3.printEuroDate();

    return 0;
}