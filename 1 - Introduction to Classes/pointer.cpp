#include <iostream>

using namespace std;
int main() {
    int a=1, b=2, c=3;
    int *pA,*pB,*pC;

    cout << "Memory address of a is " << &a << endl;
    cout << "Memory address of b is " << &b << endl;
    cout << "Memory address of c is " << &c << endl;

    cout << "pA is " << pA << endl;
    cout << "pB is " << pB << endl;
    cout << "pC is " << pC << endl;
    
    pA=nullptr;pB=nullptr;pC=nullptr;

    cout << "After allocate nullptr, pA is " << pA << endl;
    cout << "After allocate nullptr, pB is " << pB << endl;
    cout << "After allocate nullptr, pC is " << pC << endl;

    pA = &a; pB = &b; pC = &c;
    cout << "pA point to a, value of (*pA) is " << *pA << endl;
    cout << "pB point to b, value of (*pB) is " << *pB << endl;
    cout << "pC point to c, value of (*pC) is " << *pC << endl;

    cout << "pA is storing memory address of a " << pA << endl;
    cout << "pB is storing memory address of b " << pB << endl;
    cout << "pC is storing memory address of c " << pC << endl;    

    cout << "Memory address of pA " << &pA << " contains " << pA << endl;
    cout << "Memory address of pB " << &pB << " contains " << pB << endl;
    cout << "Memory address of pC " << &pC << " contains " << pC << endl;

    *pA = 4; *pB = 5, *pC = 6;
    cout << "Value of a is " << a << endl;
    cout << "Value of b is " << b << endl;
    cout << "Value of c is " << c << endl;

    cout << "pA point to a, value of (*pA) is " << *pA << endl;
    cout << "pB point to b, value of (*pB) is " << *pB << endl;
    cout << "pC point to c, value of (*pC) is " << *pC << endl;

    cout << "pA is storing memory address of a " << pA << endl;
    cout << "pB is storing memory address of b " << pB << endl;
    cout << "pC is storing memory address of c " << pC << endl;    

    *pA = *pB = *pC = 100;
    cout << "Value of a is " << a << endl;
    cout << "Value of b is " << b << endl;
    cout << "Value of c is " << c << endl;

    cout << "pA is storing memory address of a " << pA << endl;
    cout << "pB is storing memory address of b " << pB << endl;
    cout << "pC is storing memory address of c " << pC << endl;

    c = 7;
    pA = pB = pC;
    cout << "Value of *pA is " << *pA << endl;
    cout << "Value of *pB is " << *pB << endl;
    cout << "Value of *pC is " << *pC << endl;

    cout << "pA is storing memory address of c " << pA << endl;
    cout << "pB is storing memory address of c " << pB << endl;
    cout << "pC is storing memory address of c " << pC << endl;

    /** Dynamic Memory Allocation */
    int *p1 = nullptr; // Declare pointer variable and point null
    cout << "int *p1 = nullptr, p1 contains memory address " << p1 << endl;
    p1 = new int;
    cout << "p1 = new int, p1 contains " << p1 << endl;
    delete p1;
    cout << "delete p1, p1 contains " << p1 << endl;
    p1 = nullptr;
    cout << "p1 = nullprt, p1 contains " << p1 << endl;

    const int size = 3;
    double* p2 = nullptr;
    cout << "double *p2 = nullptr, p2 contains memory address " << p1 << endl;
    p2 = new double[3];
    for(int i=0; i<size; i++) {
        cout << "p2 = new double[3], p2[" << i << "] contains " << p2 + i << endl;
    }
    delete [] p2;
    cout << "delete p2, p2 contains " << p2 << endl;
    p2 = nullptr;
    cout << "p2 = nullprt, p1 contains " << p2 << endl;

    return 0;
}