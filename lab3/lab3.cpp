#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "queue.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) return 1;
    ifstream fin(argv[1]);
    if (!fin.is_open()) return 1;

    int V, start, end;
    if (!(fin >> V >> start >> end)) return 0;

    std::vector<::Vector*> adj(V + 1, nullptr);
    for (int i = 1; i <= V; ++i) adj[i] = vector_create();

    int u, v;
    while (fin >> u >> v) {
        if (u < 1 || u > V || v < 1 || v > V) continue;
        size_t u_size = vector_size(adj[u]);
        vector_resize(adj[u], u_size + 1);
        vector_set(adj[u], u_size, v);

        size_t v_size = vector_size(adj[v]);
        vector_resize(adj[v], v_size + 1);
        vector_set(adj[v], v_size, u);
    }

    std::vector<bool> visited(V + 1, false);
    std::vector<int> parent(V + 1, -1);

    Queue* q = queue_create();
    visited[start] = true;
    queue_insert(q, start);

    // Поиск в ширину
    while (!queue_empty(q)) {
        int curr = (int)queue_get(q);
        queue_remove(q);

        for (size_t i = 0; i < vector_size(adj[curr]); ++i) {
            int next = (int)vector_get(adj[curr], i);
            if (!visited[next]) {
                visited[next] = true;
                parent[next] = curr;
                queue_insert(q, next);
            }
        }
    }

    if (!visited[end]) cout << "IMPOSSIBLE\n";
    else {
        std::vector<int> path;
        for (int curr = end; curr != -1; curr = parent[curr]) {
            path.push_back(curr);
        }
        reverse(path.begin(), path.end());

        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i] << (i == path.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    for (int i = 1; i <= V; ++i) vector_delete(adj[i]);

    queue_delete(q);

    return 0;
}