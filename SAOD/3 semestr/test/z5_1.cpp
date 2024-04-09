#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> adj[100005]; // Список смежности, предполагаем, что вершин не более 100000

// Функция для выполнения BFS и поиска самой дальней вершины от стартовой
// Возвращает пару: максимальное расстояние и вершину на этом расстоянии
pair<int, int> bfs(int start, int n) {
    vector<int> distance(n + 1, -1); // Вектор для хранения расстояния до каждой вершины
    queue<int> q; // Очередь для BFS
    q.push(start);
    distance[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int next : adj[current]) {
            if (distance[next] == -1) { // Если вершина еще не была посещена
                q.push(next);
                distance[next] = distance[current] + 1;
            }
        }
    }

    int maxDistance = 0;
    int furthestNode = start;

    for (int i = 1; i <= n; ++i) {
        if (distance[i] > maxDistance) {
            maxDistance = distance[i];
            furthestNode = i;
        }
    }

    return {maxDistance, furthestNode};
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, e;
    cin >> n >> e; // Чтение количества вершин и рёбер

    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v; // Чтение ребра между вершинами u и v
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Нахождение самой удалённой вершины от произвольной вершины (например, от 1)
    pair<int, int> first = bfs(1, n);
    
    // Использование найденной вершины для нахождения диаметра
    pair<int, int> second = bfs(first.second, n);

    cout << second.first << endl; // Вывод диаметра дерева
}