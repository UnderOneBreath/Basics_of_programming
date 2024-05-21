#include <iostream>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

ifstream inp("input.txt");
ofstream out("output.txt");

const int MAXN = 100000;
vector<int> a[MAXN + 1];
int degree[MAXN + 1];

pair<int, vector<int>> treeCenter(int n) {
    queue<int> leave;

    for (int i = 1; i <= n; i++)
        if (degree[i] == 1)
            leave.push(i);

    int renNodes = n;
    while (renNodes > 2) {
        int leaveCount = leave.size();
        renNodes -= leaveCount;


        for (int i = 0; i < leaveCount; i++) {
            int leaf = leave.front();
            leave.pop();




        for (int i = 0; i < a[leaf].size(); i++) {
            int neighbor = a[leaf][i];
            degree[neighbor]--;
            if (degree[neighbor] == 1) {
                leave.push(neighbor);
            }
        }
        }
    }

    vector<int> center;
    while (!leave.empty()) {
        center.push_back(leave.front());
        leave.pop();
    }
    return make_pair(center.size(), center);
}

int main() {
    int n, m;
    inp >> n >> m;

    for (int k = 0; k < m; k++) {
        int i, j;
        inp >> i >> j;
        a[i].push_back(j);
        a[j].push_back(i);
        degree[i]++;
        degree[j]++;
    }

    pair<int, vector<int>> center = treeCenter(n);

    out << center.first << endl;
    for (int i = 0; i < center.second.size(); ++i) {
        int v = center.second[i];
        out << v << " ";
    }
    out << endl;


}