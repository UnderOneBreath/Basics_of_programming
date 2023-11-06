#include <iostream>
<<<<<<< HEAD
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int countLetters(const string& text) {
    int count = 0;
    for (char c : text) {
        if (isalpha(c)) {
            count++;
        }
    }
    return count;
}

int main() {
    string filename = "text.txt";

    ifstream file(filename);
    if (!file) {
        cout << "Error open file" << endl;
        return 1;
    }

    string text;
    string line;
    while (getline(file, line)) {
        text += line + "\n";
    }
    file.close();

    int letterCount = countLetters(text);
    cout << "Count abc: " << letterCount << endl;

    return 0;
}
=======
#include <vector>
using namespace std;

double get(char n)
{
    cout << int(n) << endl;
    return int(n);
}

int main()
{
    char a;
    cout << int(a) << endl;
    get(a);
}
>>>>>>> 98225032bdf88f0cc01206fbca97354644ff8557
