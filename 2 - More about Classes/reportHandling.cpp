#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Heading
{
    private:
        string heading;
        string subHeading;

        void printCentered(std::string text) const {
            int length = text.length();
            int spaces = (56 - length) / 2;
            
            if (spaces > 0) {
                std::cout << std::string(spaces, ' ') << text << std::endl;
            } else {
                std::cout << text << std::endl;
            }
        }

    public:
        // Default Constructor
        Heading(string h = "ABC Industries", string sub = "Report")
        {
            heading = h;
            subHeading = sub;
        }

    void printOneLine() const
    {
        cout << heading << " " << subHeading << endl;
    }

    void printBoxed() const
    {
        cout << "********************************************************" << endl;
        printCentered(heading);
        printCentered(subHeading);
        cout << "********************************************************" << endl;
    }
};

int main() {
    Heading defaultHeading;
    std::cout << "--- Default Heading (One Line) ---\n";
    defaultHeading.printOneLine();
    std::cout << "\n";

    Heading customHeading("Pet Pals", "Payroll Report");
    
    std::cout << "--- Custom Heading (One Line) ---\n";
    customHeading.printOneLine();
    std::cout << "\n";

    std::cout << "--- Custom Heading (Boxed and Centered) ---\n";
    customHeading.printBoxed();

    return 0;
}