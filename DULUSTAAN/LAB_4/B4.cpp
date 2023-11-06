#include <iostream>
#include <string>
using namespace std;

void RegTriangle(int n, int c)
{
	if (c == 0)
		cout << "*" << endl;
	if (c == n)
		return;
	else
	{
		cout << "*";
		for (int i = 0; i < c; ++i)
			cout << "x";
	}
	cout << "*" << endl;
	RegTriangle(n, c + 1);
}
void RecTriangle(int n)
{
	cout << "*";
	if (n < 0)
		return;
	else
		for (int i = 0; i < n; ++i)
			cout << "x";
	cout << "*" << endl;
	RecTriangle(n - 1);
}

int main()
{
	int n = 6;
	int count = 0;
	RegTriangle(n, count);
	RecTriangle(n);
	return 0;
}