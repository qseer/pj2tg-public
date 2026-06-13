#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxm = 55;
const int maxn = 105;
int n, m, sum, ans;
int a[maxn];
int score[maxm][maxm];
// 0. 状态定义：dp[i][j] 考虑前 i 个音符，且第 i 个音符 a[i] 放置音符 j 时，的最大得分
int dp[maxn][maxm]; 

void solve() 
{
    cin >> n >> m;
    for(int i=1; i<=m; ++i) 
    {
        for(int j=1; j<=m; ++j) 
        {
            cin >> score[i][j];
        }
    }
    for(int i=1; i<=n; ++i) cin >> a[i];
    // 1. 初始化边界条件 dp[1][] 初值均为 0，单个音符不成旋律
    memset(dp, -1, sizeof(dp));
    if(a[1] > 0) dp[1][a[1]] = 0;
    else for(int j=1; j<=m; ++j) dp[1][j] = 0;
    // 2. 状态转移
    for(int i=2; i<=n; ++i) 
    {
        if(a[i] < 0) 
        {
            for(int j=1; j<=m; ++j) 
            {
                for(int k=1; k<=m; ++k) 
                {
                    if(dp[i-1][k] != -1) dp[i][j] = max(dp[i][j], dp[i-1][k] + score[k][j]);
                }
            }
        }
        else 
        {
            int j = a[i];
            for(int k=1; k<=m; ++k) if(dp[i-1][k] != -1) dp[i][j] = max(dp[i][j], dp[i-1][k] + score[k][j]);
        }
    }
    // 3. 从 dp 表中寻找答案
    for(int j=1; j<=m; ++j) {
        ans = max(ans, dp[n][j]);
    }
    cout << ans << endl;
}

int main() 
{
    int T; cin >> T;
    while(T--) 
    {
        ans = -1;
        solve();
    }
    return 0;
}