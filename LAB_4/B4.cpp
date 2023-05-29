#include <iostream>
#include <string>
using namespace std;

void RecTriangle(int n) {
    if (n == 0) return;
    if (n < n/2)
        RecTriangle(n - 1);
    for (int i = 0; i < n; i++) {
        cout << "x";
    }
    cout << endl;
    RecTriangle(n - 1);
}

int main() {
    int n = 4;
    RecTriangle(n);
    return 0;
}

// void RecTriangle(int n)
// {
//     int m = 0;
//     if (n <= 0)
//     {
//         for (int i = 0; i < 4; i++) {
//             if ((i == 1) || (i == 2))
//                 cout << string(2, '*') << endl;
//             else
//                 cout << "*" << endl;
//         }
//         // string lineStar = "*";
//         // m = n + 4;
//         // if (m == 0)
//         //     return;
//         // if (m % 2 != 0 || m == 2) {
//         //     cout << lineStar << lineStar << endl;
//         //     RecTriangle(n - 1);
//         // } else {
//         //     if (n = -3) {
//         //         cout << lineStar << endl;
//         //         RecTriangle(n - 1);
//         //     }
//         //     cout << lineStar << endl;
//         //     RecTriangle(n - 1);
//         // }
//     }
//     if (n == 0)
//         return;
//     if ((n * 2 + 1) )
// }