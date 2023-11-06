#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    list<int> numbers;
    int number, size;

    while (inputFile >> number && number != 0) {
        numbers.push_back(number);
        size += 1;
    }

    inputFile.close();

    numbers.remove_if([](int n) { return n < 0; });

    for (int &num : numbers){
        outputFile << num << ' ';
    }

    outputFile.close();

    return 0;
}
