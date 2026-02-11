#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> node(101);
bool visited[101];
queue<int> q;
int cnt = 0;

int main() {
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    q.push(1);
    visited[1] = true;

    while (q.size()) {
        int a = q.front();
        q.pop();
        for (int x : node[a]) {
            if (visited[x]) continue;
            q.push(x);
            visited[x] = true;
            cnt++;
        }
    }
    cout << cnt << "\n";
}