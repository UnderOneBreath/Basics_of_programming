#include <iostream>
#include <vector>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
    int n, count, stp = true;
    int max, min;
    string cmd;
    srand(time(0));
    double M[n];
    while (stp == true)
    {
        cin >> cmd;
        if (cmd == "nums")
        {
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                M[i] = rand() / (RAND_MAX / 100 + 1);
                cout << M[i] << ' ';
                count += M[i];
            }
            cout << endl;
            cout << "SUMM = " << count << " | ";
            cout << "AVERAGE = " << count / n << " | ";

            // ARRAY MAX NUM
            max = M[0];
            min = M[0];
            int temp;
            for (int j = 0; j < n - 1; j++)
            {
                for (int i = 0; i < n - i - 1; i++)
                {
                    if (M[i] > M[i + 1])
                    {
                        temp = M[i];
                        M[i] = M[i + 1];
                        M[i + 1] = temp;
                    }
                }
            }
            // if (k == 1)
            // {
            //     cout << "MAX = " << max << " | ";
            //     cout << "MIN = " << min << " | ";
            //     cout << endl;
            // }

            for (int i = 0; i < n; i++)
            {
                cout << M[i] << " ";
            }
        }
        else if (cmd == "stop")
            stp == false;
    }
    // float M[5];
    // double M[10];

    // float *M; //first element
    // M = new float[10];

    // vector <int> M[]
}