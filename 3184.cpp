#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int ship;
int wolf;
char a[251][251];
bool visited[251][251];

void go(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    pair<int, int> sw = {0, 0};
    while (q.size()) {
        tie(x, y) = q.front();
        q.pop();

        if (a[x][y] == 'o') {
            sw.first++;
        } else if (a[x][y] == 'v') {
            sw.second++;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (visited[nx][ny]) continue;
            if (a[nx][ny] == '#') continue;
            visited[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    if (sw.first > sw.second) {
        ship += sw.first;
    } else {
        wolf += sw.second;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            // visited[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                go(i, j);
            }
        }
    }
    cout << ship << " " << wolf << "\n";
    return 0;
}
