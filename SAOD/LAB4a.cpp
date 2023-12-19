#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

string input = "input.txt", output = "output.txt";

int main()
{
    fstream in(input);
    ofstream out(output);
}