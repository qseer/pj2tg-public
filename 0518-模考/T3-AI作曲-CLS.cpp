#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxm = 55;
const int maxn = 105;
int n, m, sum, ans, maxScore;
int a[maxn];
int score[maxm][maxm];

// dfs(x, y) 前 x 个音符，以 y 结尾（a[x]=y)，的最大得分 => dfs 的返回值就是子问题的解 => 存储在 dp[x][y] 中
int dfs(int x, int y) 
{
    // 【补全】终止条件
    if(__?__) 
    {
        return __?__;
    }
    if(a[x-1] > 0) {
        return dfs(x-1, a[x-1]) + score[a[x-1]][y];
    }
    else {
        // 【补全】枚举的音符 i 是 a[x-1]，此时 dfs(x, y) 的解，怎么从子问题的解中转移过来？
        for(int i=1; i<=m; ++i) 
        {
            __?__
        }
    }
}

void solve() 
{
    cin >> n >> m;
    for(int i=1; i<=m; ++i) 
    {
        for(int j=1; j<=m; ++j) 
        {
            cin >> score[i][j];
            maxScore = max(maxScore, score[i][j]);
        }
    }
    for(int i=1; i<=n; ++i) cin >> a[i];
    dfs(1);
    cout << ans << endl;
}

int main() 
{
    int T; cin >> T;
    while(T--) 
    {
        ans = -1;
        maxScore = -1;
        solve();
    }
    return 0;
}