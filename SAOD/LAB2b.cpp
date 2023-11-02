#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Node
{
    char c;
    Node *next;
};
Node *top = 0;
// void push(Node **top, char c)
// {
//     Node *pv;
//     pv = new Node;
//     pv->c = c;
//     if (!top)
//         pv->next = NULL;
//     else
//         pv->next = *top;
//     *top = pv;
// }

char pop(Node **top)
{
    char temp = (*top)->c;
    Node *pv = *top;
    (*top) = (*top)->next;
    delete pv;
    return temp;
}

vector<int> *arr;
void init()
{
    int d;
    while (!feof(stdin))
    {
        cin >> d;
        arr->push_back(d);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    init();
    pop(&top);
}