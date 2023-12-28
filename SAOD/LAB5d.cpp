#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

string input("LAB5d/input.txt"), output("LAB5d/output.txt");

int main() {
    fstream inp(input);
    ofstream out(output);
    int n;
    inp >> n;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        inp >> a[i] >> b[i] >> c[i];
    }

    vector<int> d(n + 1, 0);
    d[1] = a[0];

    if (n > 1)
        d[2] = min(a[0] + a[1], b[0]);
    if (n > 2)
        d[3] = min({d[2] + a[2], d[1] + b[1], c[0]});
    for (int i = 4; i <= n; i++)
        d[i] = min({d[i - 1] + a[i - 1], d[i - 2] + b[i - 2], d[i - 3] + c[i - 3]});

    out << d[n] << endl;

    inp.close();
    inp.close();
    return 0;
}
