#include <bits/stdc++.h>
using namespace std;

int dp[1004][2][34], b[1004];
int n ,m;

int go(int idx, int tree, int cnt){
    if(cnt <0) return -1e9;
    if(idx ==n) return 0;
    int &ret = dp[idx][tree][cnt];
    if(~ret) return ret;
    int point = tree==b[idx]-1;
    ret = max(go(idx+1, tree, cnt), go(idx+1, tree^1, cnt-1))+point;
    return ret;
    
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    cout << max(go(0,0,m), go(0,1,m-1))<<'\n';
    return 0;
}