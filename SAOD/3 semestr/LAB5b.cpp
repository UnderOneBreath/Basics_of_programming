#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string input = "input.txt", output = "output.txt";

fstream inp(input);
ofstream out(output);

int main()
{
    int N;
    inp >> N;

    int arr[N];
    for (int i = 0; i < N; ++i) inp >> arr[i];

    int maxSum = arr[0];
    int sum = arr[0];
    int temp = 0, begin = 0, end = 0;

    for (int i = 1; i < N; i++) {
        if (arr[i] > sum + arr[i]) {
            sum = arr[i];
            temp = i;
        } else sum += arr[i];

        if (sum > maxSum) {
            maxSum = sum;
            begin = temp;
            end = i;
        }
    }

    out << begin + 1 << " " << end + 1;

    inp.close();
    out.close();
}