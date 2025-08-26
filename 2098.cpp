#include <bits/stdc++.h>
using namespace std;

int n;
int b[16][16];
int dp[16][16];
bool visited[16];

int go(int now){
    
    for(int i=0;i<n;i++){
        if(i==now) continue;
        if(visited) continue;
        go(i);
        dp[now][i] = b[now][i];
    }
    ret = min(go(now), go(idx));
    return ret;
}

int main(){
    memset(dp, -1, sizeof(dp));
    memset(visited, false, sizeof(visited));
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> b[i][j];
        }
    }
    int &result = 1e9;
    for(int i=0;i<n;i++){
        result = min(result, go(i));
    }
    cout << result << '\n';
    return 0;
}