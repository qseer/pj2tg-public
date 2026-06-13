#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e6 + 10;
int n;
int a[maxn], dp[maxn][2];

int dfs(int x, bool flag) 
{
    if(x > n) return 0;
    if(dp[x][flag] != -1) return dp[x][flag];
    //小信出手
    if(flag == true) 
    {
        int t1 = dfs(x+1, false) + a[x];
        int t2 = dfs(x+2, false) + a[x] + a[x+1];
        dp[x][flag] = min(t1, t2);
    }
    // 小友出手
    else 
    {
        int t1 = dfs(x+1, true);
        int t2 = dfs(x+2, true);
        dp[x][flag] = min(t1, t2);
    }
    return dp[x][flag];
}

int main() 
{
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i];
    cout << dfs(1, 1);
    return 0;
}