// #include <iostream>
// #include <vector>
// using namespace std;
//
// void mergsort(vector<int> &a)
// {
//     if (a.size() <= 1)
//         return;
//     int m = a.size() / 2;
//     vector<int> b(a.begin(), a.begin() + m);
//     vector<int> c(a.begin() + m, a.end());
//     mergsort(b);
//     mergsort(c);
//
//     int i = 0, j = 0;
//     while (i < b.size() && j < c.size())
//     {
//         if (b[i] <= c[j])
//         {
//             a[i + j] = b[i++];
//             cout << a[i + j] << " ";
//         }
//         else
//         {
//             a[i + j] = c[j++];
//             cout << a[i + j] << " ";
//         }
//     }
//     while (i < b.size())
//     {
//         a[i + j] = b[i++];
//     }
//     while (j < c.size())
//     {
//         a[i + j] = c[j++];
//     }
// }
//
// int main()
// {
//     vector<int> a = {2, 1, 4, 3};
//     mergsort(a);
// }

#include <iostream>
using namespace std;

long long aquare_sum(int n)
{
    if (n == 0)
        return n;
    else
        return n * n + aquare_sum(n - 1);
}
int main()
{
    long n;
    cin >> n;
    long result = aquare_sum(n);
    cout << result;
}