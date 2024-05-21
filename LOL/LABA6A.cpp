#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

string input = "input.txt", output = "output.txt";

double distanceX(double x0, double y0, double x1, double y1) {
    return sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2));
}

int main() {
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

    double x0, y0, R, x1, y1;
    cin >> x0 >> y0 >> R >> x1 >> y1;

    double c;

    c = distanceX(x0, y0, x1, y1);

    if (c > R) {
        cout << 2 << endl;
        double h;
        double lenghtPoint;

        lenghtPoint = pow(pow(c, 2) - pow(R, 2), 0.5);
        h = (R / c) * lenghtPoint;

        double x2, y2, x3, y3, x4, y4;
        double d;

        d = pow(pow(R, 2) - pow(h, 2), 0.5);
        x2 = x0 + ((x1 - x0) / c) * d;
        y2 = y0 + ((y1 - y0) / c) * d;

        x3 = x2 + ((y1 - y0) / c) * h;
        y3 = y2 - ((x1 - x0) / c) * h;

        x4 = x2 - ((y1 - y0) / c) * h;
        y4 = y2 + ((x1 - x0) / c) * h;
        
        cout << fixed << setprecision(5);
        cout << x4 << ' ' << y4 << ' ' << x3 << ' ' << y3 << endl;
    }
    if (c == R) {
        cout << 1 << endl;
        cout << x1 << ' ' << y1;
    }
    if (c < R) cout << 0;
}