#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
string input = "input.txt", output = "output.txt";

int main() {
    fstream inp(input);
    ofstream out(output);
    int n;
    double S;
    inp >> n;
    int *x = new int[n];
    int *y = new int[n];
    for (int i = 0; i < n; i++)
        inp >> x[i] >> y[i];

    for (int i = 1; i < n; i++)
        S += (y[i-1] + y[i]) * (x[i] - x[i-1]);

    out << fixed << setprecision(4);
    out << (abs(S) - (y[0] + y[n-1]) * (x[n-1] - x[0])) * 0.5;
}