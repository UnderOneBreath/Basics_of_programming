#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

string input = "input.txt", output = "output.txt";

float distance(float x1, float y1, float x2, float y2) {
    return pow(pow(x2 - x1, 2) + pow(y2 - y1, 2), 0.5);
}

int main() {
    ifstream inp(input);
    ofstream out(output);

    float x0, y0, R, x, y;
    cin >> x0 >> y0 >> R >> x >> y;

    float l;
    l = distance(x0, y0, x, y);

    cout << l;
}