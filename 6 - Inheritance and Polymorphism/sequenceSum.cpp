#include <iostream>
using namespace std;

class AbstractSeq
{
    public:
        virtual int fun (int k) = 0;

        void printSeq(int k, int m)
        {
            for (int i = k; i <= m; i++)
            {
                cout << fun(i) << ", ";
            }
            cout << endl;
        }


        int sumSeq(int k, int m)
        {
            int sum;

            for (int i = k; i <= m; i++)
            {
                sum += fun(i);
            }
            return sum;
        }
};

class OddSequence : public AbstractSeq
{
    public:
        virtual int fun (int k)
            { return 2*k - 1; }
};

class SquareSequence : public AbstractSeq
{
    public:
        virtual int fun (int k)
            { return k*k; }
};

int main()
{
    OddSequence oddSequence;
    oddSequence.printSeq(1, 7);
    cout << oddSequence.sumSeq(1, 7) << endl << endl;
    
    SquareSequence squareSequence;
    squareSequence.printSeq(1, 7);
    cout << squareSequence.sumSeq(1, 7) << endl;

    return 0;
}

/*
Sample Output: 

1, 3, 5, 7, 9, 11, 13, 
57

1, 4, 9, 16, 25, 36, 49, 
148
*/