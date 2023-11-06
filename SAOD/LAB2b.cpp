#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

struct Node {
    int d;
    Node *next;
};

Node *top = NULL;

void push(Node **top, int d) {
    Node *pv;
    pv = new Node;
    pv->d = d;
    if (!*top)
        pv->next = NULL;
    else
        pv->next = *top;
    *top = pv;
}

int pop(Node **top) {
    int temp = (*top)->d;
    Node *pv = *top;
    (*top) = (*top)->next;
    delete pv;
    return temp;
}

bool isOperator(const string &s) {
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

int performOperation(const string &op, int a, int b) {
    if (op == "+")
        return a + b;
    else if (op == "-")
        return a - b;
    else if (op == "*")
        return a * b;
    else if (op == "/")
        return a / b;
    else
        return 0; // Error case
}

void evaluateRPN(const string &input, ofstream &outputFile) {
    stack<int> st;
    stringstream ss(input);
    string token;

    while (ss >> token) {
        if (!isOperator(token)) {
            int operand;
            stringstream(token) >> operand;
            st.push(operand);
        } else {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            int result = performOperation(token, operand1, operand2);
            st.push(result);
        }
    }
    outputFile << "Result: " << st.top() << endl;
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Unable to open file.";
        return 1;
    }

    string input;
    getline(inputFile, input);

    evaluateRPN(input, outputFile);

    inputFile.close();
    outputFile.close();

    return 0;
}
