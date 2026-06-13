#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1010;
ll a[N], b[N], dp[N];
int n, m;
ll dfs(int x)
{
    if (x >= n) return 0;
    if (dp[x] != -1) return dp[x];
    dp[x] = 0;
    ll res = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        res = max(res, b[x] + dfs(x + a[i]));
    }
    return dp[x] = res;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    memset(dp, -1, sizeof(dp));
    cout << dfs(0);
    return 0;
}