#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef long long ll;
int n, m;
int score[110][110];
int dp[110][110];
int a[110];
int ans;

// dfs(x, y) 表示 x ~ n 个音符待决策，前一个音符为 y 时的最大得分
int dfs(int x, int y) 
{
    if(dp[x][y] != -1) return dp[x][y];
    if(x == n) {
        return 0;
    }
    if(a[x+1] < 0) {
        for(int i=1; i<=m; ++i) {
            // a[x+1] = i;
            dp[x][y] = max(dp[x][y], dfs(x + 1, i) + score[y][i]);
            // a[x+1] = -1;
        }
    } else {
        dp[x][y] = dfs(x + 1, a[x+1]) + score[y][a[x+1]];
    }
    return dp[x][y];
}

void Sol() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i=1; i<=m; ++i) {
        for(int j=1; j<=m; ++j) {
            cin >> score[i][j];
        }
    }
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
    }
    ans = 0;
    if(a[1] > 0) ans = dfs(1, a[1]);
    else {
        for(int i=1; i<=m; ++i) {
            ans = max(ans, dfs(1, i));
        }

    }
    cout << ans << endl;
}
int main() 
{
    int T; cin >> T;
    while(T--) {
        Sol();
    }
    return 0;
}