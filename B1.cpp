#define NDEBUG
#include <cassert>
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

int wordcount(char *s)
{
    int k = 0;
    bool wordC = 0;
    for (int i = 0; i < 100; i++)
    {
        if (s[i] == ' ' or s[i] == '\t' or s[i] == '\n')
        {
            wordC = false;
        }
        else if (!wordC)
        {
            wordC = true;
            k++;
        }
    }
    return k;
}

int main()
{
    char s[100] = "a        gg!";
    cout << wordcount(s) << endl;
    // Dulustan's tests
    {
        {
            char s[100] = "a bcd ef gg!";
            assert(wordcount(s) == 4);
        }

        {
            char s[100] = "captain, oh captain!!";
            assert(wordcount(s) == 3);
        }

        {
            char s[100] = "x xx xxx xxxxxxxxx x x x";
            assert(wordcount(s) == 7);
        }

        cout << "SUCCESS!" << endl;
    }

    // Сделайте 3 теста
    // Student's tests
    {
        {
            char s[100] = "Do you want return?";
            assert(wordcount(s) == 4);
        }
        {
            char s[100] = "You want me";
            assert(wordcount(s) == 3);
        }
        {
            char s[100] = "SHIIIISH nooo pleaase noooooooo no no nooo";
            assert(wordcount(s) == 7);
        }
        cout << "SUCCESS!" << endl;
    }
}