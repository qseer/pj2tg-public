#include <bits/stdc++.h>
using namespace std;

const int maxn = 205;

int n, m;
int g[maxn][maxn];
int memo[maxn][maxn];  // 从 (i,j) 出发的最长递增路径长度，0 表示未计算

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int dfs(int x, int y)
{
    if(memo[x][y] != 0) return memo[x][y];
    int res = 1;  // 至少包含自己
    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(g[nx][ny] > g[x][y])
            res = max(res, 1 + dfs(nx, ny));
    }
    return memo[x][y] = res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            cin >> g[i][j];
    int ans = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            ans = max(ans, dfs(i, j));
    cout << ans;
    return 0;
}
