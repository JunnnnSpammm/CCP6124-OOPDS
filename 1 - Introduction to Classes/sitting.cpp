#include <iostream>
using namespace std;

int main()
{
    char SittingDown;

    do
    {
        cout << "Are you sitting down now(y/n)? ";
        cin >> SittingDown;

        if( SittingDown != 'y' )
            cout << "Could you please sit down for the next exercise?";

        cout << "\n\n";
    }
    while( SittingDown != 'y' );

    cout << "Wonderful. Now we will continue today's exercise...\n";
    cout << "\n...\n\nEnd of exercise\n";

    char WantToContinue;
    cout << "\nDo you want to continue(1=Yes/0=No)? ";
    cin >> WantToContinue;

    if(WantToContinue == '1')
    {
        char LayOnBack;

        cout << "Good. For the next exercise, you should lay on your back";
        cout << "\nAre you laying on your back(1=Yes/0=No)? ";
        cin >> LayOnBack;

        if(LayOnBack == '0')
        {
            char Ready;
            do
            {
                cout << "Please lay on your back";
                cout << "\nAre you ready(1=Yes/0=No)? ";
                cin >> Ready;
            }
            while(Ready == '0');
        }
        else if(LayOnBack == '1')
            cout << "\nGreat.\nNow we will start the next exercise.";
        else
            cout << "\nWell, it looks like you are getting tired...";
    }
    else
        cout << "\nWe had enough today";

    cout << "\nWe will stop the session now\nThanks.\n";

    return 0;
}