#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>

using namespace std;

string input = "input.txt", output = "output.txt";
fstream inp(input);
ofstream out(output);

vector<int> spis[1000];
int queue[1000], way[1000], visit[1000], n, m, k;
int c;
int ans = 0, start, finish;


void Print(int v) {
    if (v > 0) {
        Print(way[v]);
        out << v << ' ';
    }
}
void cont(int v) {
    if (v > 0) {
        cont(way[v]);
        c++;
    }
}
void bfs(int v) {
    int i = 1, j, k = 1, u;
    queue[k] = v;
    visit[v] = 1;
    do {
        u = queue[i];
        for (j = 0; j < spis[u].size(); j++)
        if (visit[spis[u][j]] == 0) {
            visit[spis[u][j]] = 1; way[spis[u][j]] = u;
            queue[++k] = spis[u][j];
        }
        i++;
    }
    while (i<=k);
}
void Init(){
    int i, j, k;
    inp >> n >> m;
    memset(way, 0, sizeof(way));
    memset(visit, 0, sizeof(visit));
    for (k = 1; k <= m; k++) {
        inp >> i >> j;
        spis[i].push_back(j);
        spis[j].push_back(i);
    }
    inp >> start >> finish;
}

int main() {
    Init();
    bfs(start);
    cont(finish);
    if (c == 0) {
        out << 0 << endl;
    } else {
        out << c - 1 <<endl;
    }
    Print(finish);
    return 0;
}