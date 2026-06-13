#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, m, h[maxn][maxn], memo[maxn][maxn];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// dfs(x, y) = 从 (x,y) 出发能滑出的最长路径长度（包含起点）
// 一定不会重复访问：滑雪只往严格更低处走 → 天然 DAG，且最优子结构成立
int dfs(int x, int y)
{
    if(memo[x][y]) return memo[x][y];
    int res = 1;                                  // 站在原地就是长度 1
    for(int k = 0; k < 4; ++k)
    {
        int nx = x + dx[k], ny = y + dy[k];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(h[nx][ny] < h[x][y])                   // 必须严格更低
            res = max(res, dfs(nx, ny) + 1);
    }
    return memo[x][y] = res;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) cin >> h[i][j];
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j) ans = max(ans, dfs(i, j));
    cout << ans;
    return 0;
}
