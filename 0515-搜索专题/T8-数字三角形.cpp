#include <bits/stdc++.h>
using namespace std;

const int maxn = 505;

int n;
int a[maxn][maxn];
int memo[maxn][maxn];  // -1 表示未计算

// 从 (i,j) 走到最底层的最大路径和，记忆化搜索 = 自顶向下 DP
int dfs(int i, int j)
{
    if(i > n) return 0;
    if(memo[i][j] != -1) return memo[i][j];
    // 只能往左下或右下走
    int res = a[i][j] + max(dfs(i + 1, j), dfs(i + 1, j + 1));
    return memo[i][j] = res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= i; ++j)
            cin >> a[i][j];
    memset(memo, -1, sizeof(memo));
    cout << dfs(1, 1);
    return 0;
}
