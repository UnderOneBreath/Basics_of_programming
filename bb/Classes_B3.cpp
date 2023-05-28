#include <iostream>
#include <string>
#include <cmath>

using namespace std;
const double pi = 3.14;

class Vector
{
protected:
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
    cout << endl
         << "Введите x: ";
    cin >> oX;
  }
  void find_coordinatey()
  {
    cout << endl
         << "Введите y: ";
    cin >> oY;
  }
  void print()
  {
    cout << endl
         << "x = " << oX;
    cout << endl
         << "y = " << oY;
    cout << endl
         << "vector(" << oX << "," << oY << ")";
  }
  void new_coordinate()
  {
    cout << endl
         << "Введите новый x: ";
    cin >> oX;
    cout << endl
         << "Введите новый y: ";
    cin >> oY;
  }
  Vector vectorsum(Vector C, Vector A, Vector B)
  {
    C.oX = A.oX + B.oX;
    C.oY = A.oY + B.oY;
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

class Circle : public Vector
{
  double r;

public:
  Circle()
  {
    r = 1;
  }
  Circle(int r1)
  {
    r1 = r;
  }
  void take_r()
  {
    cin >> r;
  }
  void print_r()
  {
    cout << endl
         << "r=" << r;
  }
  double square()
  { // площадь
    return pi * r * r;
  }
  double lenght()
  { // длина
    return 2 * pi * r;
  }
  int Diametre()
  { // диаметр
    return 2 * r;
  }
  void sumCircle(Circle A, Circle B)
  {
    double FS;
    FS = (pi * A.r * A.r) + (pi * B.r * B.r);
    r = sqrt(FS / pi);
    oX = A.oX + B.oX;
    oY = A.oY + B.oY;
  }
};
int main()
{
  Circle A, B, C;
  A.find_coordinatex();
  A.find_coordinatey();
  A.take_r();
  B.find_coordinatex();
  B.find_coordinatey();
  B.take_r();
  C.sumCircle(A, B);
  C.print_r();
  C.print();
}