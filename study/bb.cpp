#include <iostream>
#include <string>

using namespace std;

void modifyValue(int& value) {
    value += 10;
}

int main()
{
    int number = 5;
    modifyValue(number);
    // number будет равно 15, так как значение было изменено внутри функции
    cout << number;
    return 0;

}