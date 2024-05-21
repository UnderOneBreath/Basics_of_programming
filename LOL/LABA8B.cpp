#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char str[10010][30];
int n;
struct bor {
    bor *next[26];
    int value;
};
bor mainnode;
void addbor(bor *node, char *s)
{
    node->value++;
    if (*s == 0)
    {
        return;
    }
    if (!node->next[*s - 'a']) {
        node->next[*s - 'a'] = new bor;
        memset(node->next[*s - 'a'], 0, sizeof(bor));
    }
    addbor(node->next[*s - 'a'], s + 1);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%i\n", &n);
    for (int i = 0; i < n; i++) gets(str[i]);
    memset(&mainnode, 0, sizeof(bor));
    for (int i = 0; i < n; i++)
    {
        int l = strlen(str[i]);
        for (int j = 0; j < l; j++)
        {
            addbor(&mainnode, &str[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        bor *cnode = &mainnode;
        char *s = str[i];
        while (*s)
        {
            cnode = cnode->next[*s - 'a'];
            s++;
        }
        printf("%i\n", cnode->value - 1);
    }
}