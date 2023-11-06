#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ifstream input_file("prob1_in.txt");
    ofstream output_file("prob1_out.txt");

    string line;
    while (getline(input_file, line))
    {
        istringstream iss(line);

        vector<int> numbers;
        int number;
        while (iss >> number)
        {
            numbers.push_back(number);
        }
        int max_number = *max_element(numbers.begin(), numbers.end());
        output_file << max_number << endl;
    }

    return 0;
}