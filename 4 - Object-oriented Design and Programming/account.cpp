#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Account
{
    private:
        double balance;
        double intRate;
        double interest;
        int transactions;

    public:
        Account(double rate = 0.045, double bal = 0.0)
        {
            balance = bal;
            intRate = rate;
            interest = 0.0;
            transactions = 0;
        }

        void makeDeposit(double amount)
        {
            balance += amount;
            transactions++;
        }

        bool withdraw(double amount);

        void calcInterest()
        {
            interest = balance * intRate;
            balance += interest;
        }

        double getBalance()
        {
            return balance;
        }

        double getInterest()
        {
            return interest;
        }

        int getTransactions()
        {
            return transactions;
        }
};


bool Account::withdraw(double amount)
{
    if (balance < amount)
        return false; // Not enough in the account
    else
    {
        balance -= amount;
        transactions++;
        return true;
    }
}

void displayMenu();
char getChoice(char max);
void makeDeposit(Account &account);
void withdraw(Account &account);

int main()
{
    const char MAX_CHOICE = '7';
    Account savings;
    char choice;

    cout << fixed << showpoint << setprecision(2);
    do
    {
        displayMenu();
        choice = getChoice(MAX_CHOICE);
        switch(choice)
        {
            case '1':
                cout << "The current balance is $";
                cout << savings.getBalance() << endl;
                break;
            
            case '2':
                cout << "There have been ";
                cout << savings.getTransactions()
                     << " transactions.\n";
                break;
            
            case '3':
                cout << "Interest earned for this period: $";
                cout << savings.getInterest() << endl;
                break;
            
            case '4':
                makeDeposit(savings);
                break;
            
            case '5':
                withdraw(savings);
                break;
            
            case '6':
                savings.calcInterest();
                cout << "Interest added.\n";
        }
    } while(choice != '7');

    return 0;
}

void displayMenu()
{
    cout << "\n\n                MENU\n\n";
    cout << "1) Display the account balance\n";
    cout << "2) Display the number of transactions\n";
    cout << "3) Display interest earned for this period\n";
    cout << "4) Make a deposit\n";
    cout << "5) Make a withdrawal\n";
    cout << "6) Add interest for this period\n";
    cout << "7) Exit the program\n\n";
    cout << "Enter your choice: ";
}

char getChoice(char max)
{
    char choice = cin.get();
    cin.ignore();

    while (choice < '1' || choice > max)
    {
        cout << "Choice must be between 1 and " << max << ". "
             << "Please re-enter choice: ";
        choice = cin.get();
        cin.ignore();
    }
    return choice;
}

void makeDeposit(Account &account)
{
    double dollars;

    cout << "Enter the amount of the deposit: ";
    cin >> dollars;
    cin.ignore();
    account.makeDeposit(dollars);
}

void withdraw(Account &account)
{
    double dollars;

    cout << "Enter the amount of the withdrawal: ";
    cin >> dollars;
    cin.ignore();
    if (!account.withdraw(dollars))
        cout << "ERROR: Withdrawal amount too large.\n\n";
}

/*
Sample Output: 

                MENU

1) Display the account balance
2) Display the number of transactions
3) Display interest earned for this period
4) Make a deposit
5) Make a withdrawal
6) Add interest for this period
7) Exit the program

Enter your choice: 4
Enter the amount of the deposit: 100


                MENU

1) Display the account balance
2) Display the number of transactions
3) Display interest earned for this period
4) Make a deposit
5) Make a withdrawal
6) Add interest for this period
7) Exit the program

Enter your choice: 1
The current balance is $100.00


                MENU

1) Display the account balance
2) Display the number of transactions
3) Display interest earned for this period
4) Make a deposit
5) Make a withdrawal
6) Add interest for this period
7) Exit the program

Enter your choice: 6
Interest added.


                MENU

1) Display the account balance
2) Display the number of transactions
3) Display interest earned for this period
4) Make a deposit
5) Make a withdrawal
6) Add interest for this period
7) Exit the program

Enter your choice: 3
Interest earned for this period: $4.50


                MENU

1) Display the account balance
2) Display the number of transactions
3) Display interest earned for this period
4) Make a deposit
5) Make a withdrawal
6) Add interest for this period
7) Exit the program

Enter your choice: 5
Enter the amount of the withdrawal: 50


                MENU

1) Display the account balance
2) Display the number of transactions
3) Display interest earned for this period
4) Make a deposit
5) Make a withdrawal
6) Add interest for this period
7) Exit the program

Enter your choice: 2
There have been 2 transactions.


                MENU

1) Display the account balance
2) Display the number of transactions
3) Display interest earned for this period
4) Make a deposit
5) Make a withdrawal
6) Add interest for this period
7) Exit the program

Enter your choice: 7
*/