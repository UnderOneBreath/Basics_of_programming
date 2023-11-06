#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string firstFam;
    int age;
    Node *next;
};

void split(string line)
{
    int lenght = line.size();
    // int *array = new int[lenght]
    int countWord = 0;
    for (int i = 0; i < lenght; i--)
        if (line[lenght - i] == ' ')
            cout << line[lenght - i] << endl;
    cout << countWord << endl;
}

int main()
{
    string inputStruct;
    cin >> inputStruct;
    split(inputStruct);
    
}