#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

string input = "input.txt", output = "output.txt";

double dist(double x1, double y1, double x2, double y2) {
    double d;
    d = pow(pow(x2-x1, 2) + pow(y2-y1, 2), 0.5);
    return d;
}

double distPointToPr(double px, double py, double x1, double y1, double x2, double y2) {
    double l = pow(x1-x2, 2) + pow(y1-y2, 2);
    if (l == 0) return dist(px, py, x1, y1);

    double t = max(0.0, min(1.0, ((px-x1) * (x2-x1) + (py-y1) * (y2 - y1))/l));
    double projX = x1 + t * (x2 - x1);
    double projY = y1 + t * (y2 - y1);
}

// float checkParallelism(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
// }
int main() {
    fstream inp(input);
    ofstream out(output);

    double x1, y1, x2, y2;
    double x3, y3, x4, y4;

    //Ax + By + C = 0
    // float a1, b1, c1;
    // float a2, b2, c2;

    cout distPointToPr()
    inp >> x1 >> y1 >> x2 >> y2;
    inp >> x3 >> y3 >> x4 >> y4;

    cout << dist(x1,y1, x3,y3);

}
