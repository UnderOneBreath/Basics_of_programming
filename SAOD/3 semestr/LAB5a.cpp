#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string input = "input.txt", output = "output.txt";
fstream inp(input);
ofstream out(output);

long long powVersion2(int num, int n)
{
    long long sum = 1;
    for (int i = 0; i < n; i++) sum *= num;
    return sum;
}

int main()
{
    int n;
    inp >> n;
    long long F = 0, f1 = 0, f2 = 1;
    for (int i = 3; i <= n; i++)
    {
        F = f2 + f1 + powVersion2(2, i-2);
        f1 = f2;
        f2 = F;
        cout << F << ' ' << i << endl;
    }
    long long answer = powVersion2(2, n) - F;
    out << answer;

    inp.close();
    out.close();
}