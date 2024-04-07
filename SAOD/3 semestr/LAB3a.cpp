#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    vector<int> numbers;
    int number, size;

    while (inputFile >> number) {
        if (number != 0) {
            numbers.push_back(number);
            size += 1;
        }
    }

    inputFile.close();

    // Сортировка чисел
    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < size; i++) {
        outputFile << numbers[i] << ' ';
    }

    outputFile.close();
}