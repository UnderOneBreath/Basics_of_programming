#include <iostream>
using namespace std;

int A(int m, int n)
{
    if (m == 0)
        return n + 1;
    else if (m > 0 && n == 0)
        return A(m - 1, 1);
    else if (m > 0, n > 0)
        return A(m - 1, A(m, n - 1));
}

int main()
{
    cout << "0 <= m <= 3 and 0 <= n <= 7" << endl;
    int m, n;
    cin >> m >> n;
    if ((m < 0 || m > 3) || (n < 0 || n > 7))
        return false;
    cout << A(m, n) << endl;
    return 0;
}