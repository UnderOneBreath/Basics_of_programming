#include <iostream>
#include <string>
using namespace std;

class Vector
{
    int oX;
    int oY;

public:
    Vector()
    {
        oX = 0;
        oY = 0;
    }
    Vector(int x, int y)
    {
        oX = x;
        oY = y;
    }
    void find_coordinatex()
    {
        cout << "x: ";
        cin >> oX;
    }
    void find_coordinatey()
    {
        cout << "y: ";
        cin >> oY;
    }
    void print()
    {
        cout << "x = " << oX << endl;
        cout << "y = " << oY << endl;
        cout << "vector(" << oX << "," << oY << ")" << endl;
    }

    void printVector()
    {
        cout << "vectorskaly = " << oX + oY << endl;
    }

    Vector vectorskaly(Vector C, Vector A, Vector B)
    {
        C.oX = A.oX * B.oX;
        C.oY = A.oY * B.oY;
        return C;
    }
    void skaly(double k)
    {
        oX = oX * k;
        oY = oY * k;
    }
    void skaly(Vector B)
    {
        oX = oX + B.oX;
        oY = oY + B.oY;
    }
};
int main()
{
    Vector A;
    Vector B;
    double k;

    A.find_coordinatex();
    A.find_coordinatey();

    B.find_coordinatex();
    B.find_coordinatey();
    cout << endl;

    Vector C;
    cout << "VECTORSKALY" << endl;
    C.vectorskaly(C, A, B).printVector();

    cout << "k = ";
    cin >> k;

    cout << endl;
    A.skaly(k);
    A.print();

    A.skaly(B);
    A.print();
}