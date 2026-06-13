#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, a[maxn], memo[maxn];
bool vis[maxn];

// dfs(i) = 必须以 a[i] 结尾的最大子段和
// a[i] 可能为负 → 不能用 0/-1 区分"未算过"，单独开 vis 标记
int dfs(int i)
{
    if(i == 1) return a[1];
    if(vis[i]) return memo[i];
    vis[i] = true;
    return memo[i] = max(dfs(i-1) + a[i], a[i]);
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int ans = INT_MIN;
    for(int i = 1; i <= n; ++i) ans = max(ans, dfs(i));
    cout << ans;
    return 0;
}
