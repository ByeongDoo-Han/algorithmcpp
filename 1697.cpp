#include <bits/stdc++.h>
using namespace std;

int N, M;
int cnt = 1e5;
vector<int> dist(100001, 0);
queue<int> q;

void bfs(int n) {
    if (N == M) return;
    q.push(n);
    while (q.size()) {
        int x = q.front();
        q.pop();
        if (x == M) break;

        for (int nx : {x - 1, x + 1, x * 2}) {
            if (nx < 0 || nx > 1e5) continue;
            if (dist[nx] != 0) continue;
            dist[nx] = dist[x] + 1;
            // cout << nx << ":" << dist[nx] << "\n";
            q.push(nx);
        }
    }
}

int main() {
    cin >> N >> M;
    bfs(N);
    // for (int i = 0; i < 20; i++) {
    //     cout << dp[i] << " ";
    // }
    cout << dist[M];
}