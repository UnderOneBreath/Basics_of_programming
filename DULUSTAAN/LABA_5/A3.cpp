#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int kn;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << "Selection sort:" << endl;
    for (int i = n - 1; i > -1; i--)
    {
        int max = i;
        int k = 0;
        for (int j = i - 1; j > -1; j--)
            if (v[j] > v[max])
            {
                max = j;
                k++;
            }
        if (k > 0)
        {
            swap(v[max], v[i]);
            for (int t = 0; t < n; t++)
            {
                cout << v[t] << " ";
            }
            kn++;
            cout << endl;
        }
    }
    cout << "all: " << kn << endl;
}