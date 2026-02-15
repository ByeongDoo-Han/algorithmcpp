#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int dp[10001];
int ret;
int cnt3a, cnt5a, cnt7a;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    a.resize(n);
    memset(dp, 0, sizeof(n + 1));

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0] = a[0] * 3;
    dp[1] = min(dp[0] + min(a[0], a[1]) * 3, min(a[0], a[1]) * 5);
    dp[2] = min(dp[1] + min(a[1], a[2]) * 5, min(min(a[0], a[1]), a[2]) * 7);

    for (int i = 3; i < n; i++) {
        dp[i] = min(dp[i - 1] + min(a[i - 1], a[i]) * 5, min(min(a[i - 2], a[i - 1]), a[i]) * 7);
    }

    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }

    cout << dp[n - 1] << "\n";
}
