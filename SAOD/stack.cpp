#include <iostream>
using namespace std;

int main()
{
    int a, n;
    setlocale(LC_ALL, "ru");
    cin >> n;
    int *sl = new int[n];

    for (int i = 0; i < n; i++)
        sl[i] = i;

    for (int i = 0; i < n; i++)
        cout << sl[i] << " ";
}