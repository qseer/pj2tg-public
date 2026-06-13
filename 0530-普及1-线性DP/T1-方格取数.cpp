#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, grid[maxn][maxn], dp[maxn][maxn];

int main()
{
    cin >> n;
    int r, c, v;
    while (cin >> r >> c >> v && (r || c || v))
        grid[r][c] = v;
    // dp[i][j] = 从 (1,1) 出发只向右/下走到达 (i,j) 能取得的最大和
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
    cout << dp[n][n];
    return 0;
}
