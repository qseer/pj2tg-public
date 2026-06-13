#include <bits/stdc++.h>
using namespace std;

const int maxn = 35;

int n, m;
char g[maxn][maxn];
bool vis[maxn][maxn];
bool found;

// 四个方向：上、下、左、右
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

void dfs(int x, int y)
{
    if(found) return;  // 已找到出口，剪枝
    if(g[x][y] == 'E')
    {
        found = true;
        return;
    }
    vis[x][y] = true;
    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(g[nx][ny] == '#' || vis[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    int sx = 0, sy = 0;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            cin >> g[i][j];
            if(g[i][j] == 'S') sx = i, sy = j;
        }
    dfs(sx, sy);
    cout << (found ? "YES" : "NO");
    return 0;
}
