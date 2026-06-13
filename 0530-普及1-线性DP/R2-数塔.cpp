#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, a[maxn][maxn], memo[maxn][maxn];
bool vis[maxn][maxn];

// dfs(i, j) = 从 (i, j) 出发走到底层能得到的最大和
// 数塔权值可能为 0 / 负，不能用 memo == 0 当未算过 → 单独开 vis
int dfs(int i, int j)
{
    if(i == n) return a[n][j];                   // 已在底层，只能取自己
    if(vis[i][j]) return memo[i][j];
    vis[i][j] = true;
    return memo[i][j] = a[i][j] + max(dfs(i+1, j), dfs(i+1, j+1));
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= i; ++j) cin >> a[i][j];
    cout << dfs(1, 1);
    return 0;
}
