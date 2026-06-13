#include <bits/stdc++.h>
using namespace std;

using PII = pair<int, int>;

const int maxn = 35;

int n, m;
char g[maxn][maxn];
bool vis[maxn][maxn];
int dist[maxn][maxn];  // 到起点的最短步数

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int bfs(int sx, int sy)
{
    queue<PII> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    dist[sx][sy] = 0;
    while(!q.empty())
    {
        auto [x, y] = q.front(); q.pop();
        if(g[x][y] == 'E') return dist[x][y];
        for(int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(g[nx][ny] == '#' || vis[nx][ny]) continue;
            vis[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    return -1;  // 无法到达
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
    int ans = bfs(sx, sy);
    cout << ans;
    return 0;
}
