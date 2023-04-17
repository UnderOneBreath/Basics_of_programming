#include <vector>
#include <iostream>
using namespace std;

class Vector
{
    double x;
    double y;

public:
    Vector(double _x, double _y)
    {
        x = _x;
        y = _y;
    }

    double get_x()
    {
        return x;
    }

    double get_y()
    {
        return y;
    }

    void update_x(double _x)
    {
        x = _x;
    }
    void update_y(double _y)
    {
        y = _y;
    }

    void print()
    {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main()
{
    cout << "Enter x: ";
    double x;
    cin >> x;
    cout << "Enter y: ";
    double y;
    cin >> y;
    Vector a(x, y);
    cout << "(" << x << ", " << y << ")" << endl;

    while (true)
    {
        cout << "Do you want to continue? ->  ";
        char answer;
        cin >> answer;
        if (answer == 'n')
            break;
        else if (answer != 'y')
            continue;
        cout << "Enter new x: ";
        cin >> x;
        a.update_x(x);
        cout << "Enter new y: ";
        cin >> y;
        a.update_y(y);
        a.print();
    }
}