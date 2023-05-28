#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream input_file("prob2_in.txt");
    ofstream output_file("prob2_out.txt");

    string line;
    while (getline(input_file, line))
    {
        for (int i = 0; i < line.size(); i++)
        {
            if (isalnum(line[i]))
            {
                output_file << line[i];
                if (i != line.size() - 1 && isalnum(line[i + 1]))
                {
                    output_file << "*";
                }
            }
            else
            {
                output_file << line[i];
            }
        }
        output_file << endl;
    }

    return 0;
}