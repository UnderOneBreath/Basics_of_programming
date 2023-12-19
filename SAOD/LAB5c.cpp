#include <iostream>
#include <fstream>
#include <string>

using namespace std;

long long countPalindromes(string s)
{
    int n = s.length();
    long long arr[n][n] = {0};
    for (int i = 0; i < n; i++)
        arr[i][i] = 1;
    for (int len = 2; len <= n; len++)
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;

            if (s[i] == s[j])
                arr[i][j] = arr[i + 1][j] + arr[i][j - 1] + 1;
            else
                arr[i][j] = arr[i + 1][j] + arr[i][j - 1] - arr[i + 1][j - 1];
        }
    }

    return arr[0][n - 1];
}

int main()
{
    ifstream inp("input.txt");
    ofstream out("output.txt");
    string s;
    inp >> s;

    out << countPalindromes(s);

    inp.close();
    out.close();
}