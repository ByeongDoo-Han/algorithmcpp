#include <bits/stdc++.h>
using namespace std;

int N, R, Q, L;
vector<vector<int>> graph;
vector<int> nodeValue;

int dfs(int current, int parent, int depth) {
    if (nodeValue[current] >= 0) {
        return nodeValue[current];
    }

    if (depth % 2 == 0) {
        int bestValue = 0;
        for (int child : graph[current]) {
            if (child != parent) {
                bestValue = max(bestValue, dfs(child, current, depth + 1));
            }
        }
        return nodeValue[current] = bestValue;
    } else {
        int bestValue = INT_MAX;
        for (int child : graph[current]) {
            if (child != parent) {
                bestValue = min(bestValue, dfs(child, current, depth + 1));
            }
        }
        return nodeValue[current] = bestValue;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> R;
    nodeValue = vector<int>(N + 1, -1);
    graph = vector<vector<int>>(N + 1, vector<int>());

    for (int i = 0; i < N - 1; i++) {
        int v, u;
        cin >> v >> u;
        graph[v].push_back(u);
        graph[u].push_back(v);
    }

    cin >> L;

    for (int i = 0; i < L; i++) {
        int n, t;
        cin >> n >> t;
        nodeValue[n] = t;
    }

    dfs(R, 0, 0);

    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int q;
        cin >> q;
        cout << nodeValue[q] << "\n";
    }

    return 0;
}