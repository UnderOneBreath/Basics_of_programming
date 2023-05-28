#include <iostream>

using namespace std;

class Matrix
{
private:
    double a;
    double b;
    double c;
    double d;
    double op = 0;

public:
    Matrix(double a1, double b1, double c1, double d1)
    {
        a = a1;
        b = b1;
        c = c1;
        d = d1;
    }
    double opred()
    {
        op = a * d - b * c;
        return op;
    }
    Matrix transpose()
    {
        return (Matrix(a, c, b, d));
    }
    void output()
    {
        cout << a << " " << b << endl;
        cout << c << " " << d << endl;
    }
};

int main()
{
    Matrix m(1, 2, 3, 4);
    m.output();
    cout << "Determinant: ";
    cout << m.opred();
    cout << endl;
    cout << "transpose matrix: " << endl;
    m.transpose().output();
}