#include <bits/stdc++.h>
using namespace std;

const int max_int = 101;
int n, m, a[max_int][max_int], visited[max_int][max_int];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void go(int x, int y)
{
    queue<pair<int, int>> q;
    visited[x][y] = 1;
    q.push({x, y});
    while (q.size())
    {
        tie(x, y) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (a[nx][ny] == 0)
                continue;
            if (visited[nx][ny])
                continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }
    go(0, 0);
    cout << visited[n - 1][m - 1] << '\n';
    return 0;
}
