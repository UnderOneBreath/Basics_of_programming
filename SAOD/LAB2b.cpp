#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

double evaluateRPN(const string &rpnExpression)
{
    stack<double> operands;

    istringstream iss(rpnExpression);
    string token;

    while (iss >> token)
    {
        if (isdigit(token[0]) || (token[0] == '-' && token.length() > 1))
        {
            double number = stod(token);
            operands.push(number);
        }
        else
        {
            double operand2 = operands.top();
            operands.pop();
            double operand1 = operands.top();
            operands.pop();

            if (token == "+")
            {
                operands.push(operand1 + operand2);
            }
            else if (token == "-")
            {
                operands.push(operand1 - operand2);
            }
            else if (token == "*")
            {
                operands.push(operand1 * operand2);
            }
            else if (token == "/")
            {
                operands.push(operand1 / operand2);
            }
            else
            {
                cerr << "Недопустимый оператор: " << token << endl;
                return 0;
            }
        }
    }

    if (!operands.empty())
    {
        return operands.top();
    }
    else
    {
        cerr << "Ошибка: стек пуст" << endl;
        return 0.0;
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double result = evaluateRPN();

    cout << "Результат: " << result << endl;

    return 0;
}