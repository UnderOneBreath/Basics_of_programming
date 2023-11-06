#include <iostream>
using namespace std;

struct Node
{
    int d;
    Node *next;
};
Node *top = NULL;
void push(Node **top, int d)
{
    Node *pv;
    pv = new Node;
    pv->d = d;
    if (!top)
        pv->next = NULL;
    else
        pv->next = *top;
    *top = pv;
}
int pop(Node **top)
{
    int temp = (*top)->d;
    Node *pv = *top;
    (*top) = (*top)->next;
    delete pv;
    return temp;
}
void init()
{
    int d;
    while (!feof(stdin))
    {
        cin >> d;
        push(&top, d);
    }
}
void print(Node *top)
{
    Node *temp;
    temp = top;
    while (temp)
    {
        cout << temp->d << ' ' << '\n';
        temp = temp->next;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    top = 0;
    init();
    pop(&top);
    print(top);
}