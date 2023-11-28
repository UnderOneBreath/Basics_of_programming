#include <iostream>
using namespace std;

void res(int *arr)
{
    for (int i = 0; i < sizeof(arr); i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void copyArr(int *arr, int *arr2)
{
    cout << "void copyArr" << endl;
    int sizeArr1 = sizeof(arr);
    int sizeArr2 = sizeof(arr2);
    cout << sizeArr1 << ' ' << sizeArr2 << endl;
}

int main()
{
    int arr[]{1, 5, 10, 50, 100, 500};
    res(arr);
    int n = 5;
    int *arr2 = new int[n];
    cout << "Size Array dinamic: " << sizeof(arr) << endl;
    cout << "Size Array dinamic with using *arr: " << sizeof(arr2) << endl;

    copyArr(arr, arr2);

    int c;
    for (auto i : arr)
    {
        cout << i << " ";
        c++;
    }
    cout << "\nThe lenght of the given Array is: " << c;
}