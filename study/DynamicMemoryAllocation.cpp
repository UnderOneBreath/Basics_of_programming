#include <iostream>

using namespace std;

int main()
{
    int *a = new int;
    int **p;
    p = &a;
    *a = 5;
    cout << *a << endl;
    cout << &a << endl;
    cout << p << endl;
}