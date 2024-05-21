#include <iostream>
#include <math.h>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
string input = "input.txt", output = "output.txt";

int main() {
    fstream inp(input);
    ofstream out(output);

    double x, y, x1, y1, x2, y2;
    double A, B, C;

    inp >> x >> y >> x1 >> y1 >> x2 >> y2;

    A = y2 - y1;
    B = x1 - x2;
    C = ((x1 * (-1)) * A) - (y1 * B);

    if (((A*x + B*y + C) == 0) && (x >= x1 && x <= x2 || x <= x1 && x >= x2) && (y >= y1 && y <= y2 || y <= y1 && y >= y2)) {
        out << "YES";
    } else {
        out << "NO";
    }

}