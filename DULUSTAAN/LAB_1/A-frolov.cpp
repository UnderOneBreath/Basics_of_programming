#include <iostream>
#include <vector>
using namespace std;
double solve(vector<vector<double>> a)
{
    double sum = 0;
    int n = a.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j || j == n - i - 1)
                sum = sum + a[i][j];
        }
    }
    return sum;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<double>> a(n, vector<double>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    cout << solve(a);
    return 0;
}
