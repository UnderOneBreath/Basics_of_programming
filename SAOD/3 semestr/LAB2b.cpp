#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

string input = "input.txt", output = "output.txt";
ifstream inp(input);
ofstream out(output);

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

bool Operator(const string &s) {
    return (s == "+" || s == "-" || s == "*" || s == "/");
}

int performOperation(const string &op, int a, int b) {
    if (op == "+") return a + b;
    else if (op == "-") return a - b;
    else if (op == "*") return a * b;
    else if (op == "/") return a / b;
    else return 0;
}

void evaluate(const string &inp, ofstream &out) {
    stack<int> st;
    stringstream ss(inp);
    string symbol;

    while (ss >> symbol) {
        if (!Operator(symbol)) {
            int operand;
            stringstream(symbol) >> operand;
            st.push(operand);
        } else {
            int operand2 = st.top();
            st.pop();
            int operand1 = st.top();
            st.pop();
            int result = performOperation(symbol, operand1, operand2);
            st.push(result);
        }
    }
    out << st.top() << endl;
}

int main() {
    string input;
    getline(inp, input);

    evaluate(input, out);

    inp.close();
    out.close();

    return 0;
}
