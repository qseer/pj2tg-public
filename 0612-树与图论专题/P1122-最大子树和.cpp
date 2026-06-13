#include <bits/stdc++.h>
using namespace std;

const int maxn = 1.6e4 + 10;

int n, val[maxn];
long long dp[maxn];
vector<int> g[maxn];
bool vis[maxn];

void dfs(int u)
{
    vis[u] = true;
    dp[u] = val[u];
    for(int v : g[u])
    {
        if(vis[v]) continue;
        dfs(v);
        if(dp[v] > 0) dp[u] += dp[v];
    }
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> val[i];
    for(int i=1; i<n; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    long long ans = *max_element(dp+1, dp+n+1);
    cout << ans;
    return 0;
}
