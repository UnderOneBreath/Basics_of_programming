#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

string input = "input.txt", output = "output.txt";

float dist(float x1, float y1, float x2, float y2) {
    float d;
    d = pow(pow(x2-x1, 2) + pow(y2-y1, 2), 0.5);
    return d;
}

float distPointToPr(double px, double py, double x1, double y1, double x2, double y2) {
    float l = pow(x1-x2, 2) + pow(y1-y2, 2);
    if (l == 0) return dist(px, py, x1, y1);

    double t = max(0.0, min(1.0, ((px-x1) * (x2-x1) + (py-y1) * (y2 - y1))/l));
}

float checkParallelism(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
}
int main() {
    fstream inp(input);
    ofstream out(output);

    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    //Ax + By + C = 0
    // float a1, b1, c1;
    // float a2, b2, c2;

    float k;
    k = (x)

    inp >> x1 >> y1 >> x2 >> y2;
    inp >> x3 >> y3 >> x4 >> y4;

    cout << dist(x1,y1, x3,y3);

}
