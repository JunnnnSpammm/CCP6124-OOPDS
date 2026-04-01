#include<iostream>

void swap_pass_by_value(int, int);
void swap_pass_by_reference(int&, int&);
void swap_pass_by_reference_pointer(int*, int*);

using namespace std;
int main() {
    int p = 12;
    int q = 34;

    cout << "Memory address of p = " << &p << endl;
    cout << "Memory address of q = " << &q << endl;

    cout << "\nPass by value" << endl;
    swap_pass_by_value(p,q);
    cout << "p:" << p << endl;
    cout << "q:" << q << endl;

    cout << "\nPass by reference" << endl;
    swap_pass_by_reference(p,q);
    cout << "p:" << p << endl;
    cout << "q:" << q << endl;

    cout << "\nPass by reference using pointers" << endl;
    swap_pass_by_reference_pointer(&p,&q);
    cout << "p:" << p << endl;
    cout << "q:" << q << endl;

    return 0;
}

void swap_pass_by_value(int p, int q) {
    cout << "Memory address of p =" << &p << endl;
    cout << "Memory address of q =" << &q << endl;
    int temp = p;
    p = q;
    q = temp;
}

void swap_pass_by_reference(int& p, int& q) {
    cout << "Memory address of p = " << &p << endl;
    cout << "Memory address of q = " << &q << endl;
    int temp = p;
    p = q;
    q = temp;
}

void swap_pass_by_reference_pointer(int* p, int* q) {
    cout << "Memory address of *p = " << &(*p) << endl;
    cout << "Memory address of *q = " << &(*q) << endl;
    int temp = *p;
    *p = *q;
    *q = temp;
}
