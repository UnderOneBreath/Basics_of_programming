#include <fstream>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

char *M = new char[8];

ofstream out;

void fact(int s, int n)
{
    if (n == 0)
    {
        out << s << endl;
        return;
    }
    else
    {
        s *= n;
        fact(s, n - 1);
    }
}

void per(int pos = 0)
{
    if (pos >= strlen(M))
    {
        out << M << endl;
        return;
    }
    else
    {
        for (int i = pos; i < strlen(M); ++i)
        {
            swap(M[i], M[pos]);
            per(pos + 1);
            swap(M[i], M[pos]);
        }
    }
}

int main()
{
    int len;

    ifstream in("input.txt");
    out.open("output.txt");

    in >> M;
    len = strlen(M);

    fact(len, len - 1);
    per();

    in.close();
    out.close();
}