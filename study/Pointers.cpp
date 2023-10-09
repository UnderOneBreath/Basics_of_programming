#include <iostream>
#include <vector>

using namespace std;


int main() {
    vector<vector<int>> a;
    int p = &a;
    cout << &a << endl;
}
