#include <iostream>
#include <fstream>
#include <vector>
#include <random>
using namespace std;

class Nonsense_Gen
{
public:
    Nonsense_Gen()
    {
        ifstream dictionary_file("dictionary.txt");
        string word;
        while (dictionary_file >> word)
        {
            dictionary.push_back(word);
        }
    }

    void generate()
    {
        ofstream output_file("nonsense_" + to_string(file_count) + ".txt");
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(0, dictionary.size() - 1);
        for (int i = 0; i < 10; i++)
        {
            output_file << dictionary[dis(gen)] << " ";
        }
        output_file.close();
        file_count++;
    }

private:
    vector<string> dictionary;
    int file_count = 1;
};

int main()
{
    Nonsense_Gen gen;
    gen.generate();
    gen.generate();
    gen.generate();

    return 0;
}