#include <iostream>
#include <cmath>

using namespace std;

class Matrix
{
private:
    double a;
    double b;
    double c;
    double d;

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
        return a * d - b * c;
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
    double get(int i)
    {
        double arr[4] = {a, b, c, d};
        return arr[i];
    }
    Matrix power(int k);
};

Matrix operator+(Matrix &m1, Matrix &m2)
{
    double a, b, c, d;
    a = m1.get(0) + m2.get(0);
    b = m1.get(1) + m2.get(1);
    c = m1.get(2) + m2.get(2);
    d = m1.get(3) + m2.get(3);
    return Matrix(a, b, c, d);
}

Matrix operator*(Matrix &m1, Matrix &m2)
{
    double a, b, c, d;
    a = m1.get(0) * m2.get(0) + m1.get(1) * m2.get(2);
    b = m1.get(0) * m2.get(1) + m1.get(1) * m2.get(3);
    c = m1.get(2) * m2.get(0) + m1.get(3) * m2.get(2);
    d = m1.get(2) * m2.get(1) + m1.get(3) * m2.get(3);
    return Matrix(a, b, c, d);
}

Matrix operator*(Matrix &m, double num)
{
    double a, b, c, d;
    a = m.get(0) * num;
    b = m.get(1) * num;
    c = m.get(2) * num;
    d = m.get(3) * num;
    return Matrix(a, b, c, d);
}

void power(Matrix m, int k)
{
    Matrix res = m;
    for (int i = 1; i < k; i++)
    {
        res = res * m;
    }
    res.output();
}

int main()
{
    int k, num;

    Matrix m1(1, 2, 3, 4);
    Matrix m2(1, 2, 3, 4);

    // cout << "operator+" << endl;
    // operator+(m1, m2);
    // cout << endl;

    // cout << "operator*" << endl;
    // operator*(m1, m2);
    // cout << endl;

    // cout << "operator*" << endl;
    // cout << "Input num: ";
    // cin >> num;
    // operator*(m1, num);
    // cout << endl;

    cout << "A^k" << endl;
    cout << "Input k: ";
    cin >> k;
    power(m1, 2);
}