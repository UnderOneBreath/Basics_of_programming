#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string input("input.txt"), output("output.txt");

string inputString;
char firstC, secondC;
int stringL, countC;

long long powV2(int n, int exponent) {
    long long result = n;
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return result;
    for (int i = 1; i < exponent; ++i)
        result *= n;
    return result;
}

int fact(int n) {
    if (n <= 0)
        return 1;
    return n * fact(n - 1);
}

int countCombinat(int k, int l) {
    return fact(l) / (fact(l - k) * fact(k));
}

int main() {
    fstream inp(input);
    ofstream out(output);
    inp >> inputString >> stringL >> firstC >> secondC >> countC;
    int stringSize = inputString.size();

    if (firstC == secondC)
        out << countCombinat(countC - 1, stringL - 1) * powV2(stringSize - 1, stringL - countC);
    else
        out << countCombinat(countC, stringL - 1) * powV2(stringSize - 1, stringL - countC - 1) << endl;
    
    inp.close();
    out.close();
}
