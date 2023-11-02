#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector
{
}

int main()
{
    fstream inp("input.txt");
    fstream otp("output.txt");

    int n, x;
    int cout = 0;

    vector<int> array;

    while (inp >> x)
    {
        if (x == 0)
            return;
        cout += 1;
        array.push_back(x);
    }
    for (int i = 0; i < ; i++)
        cout << array[i] << ' ';
}