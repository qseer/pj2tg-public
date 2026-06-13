#include <bits/stdc++.h>
using namespace std;
const int maxn = 105;
int n, m, h[maxn][maxn], memo[maxn][maxn];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int dfs(int x, int y)
{
    int res = 1;                                  // 站在原地就是长度 1
    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(h[nx][ny] < h[x][y])                   
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
