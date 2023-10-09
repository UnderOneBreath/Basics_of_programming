#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < a.size(); i++)
        cin >> a[i];
    cout << "Bubble Sort: " << endl;
    int k = 0;
    for (int t = a.size() - 1; t >= 1; t--)
    {
        bool sorted = true;
        for (int i = a.size() - 1; i > 0; i--)
            if (a[i - 1] > a[i])
            {
                swap(a[i - 1], a[i]);
                sorted = false;
                for (int j = 0; j < a.size(); j++)
                    cout << a[j] << " ";
                k++;
                cout << endl;
            }
        if (sorted)
            break;
    }
    cout << "all: " << k;
}