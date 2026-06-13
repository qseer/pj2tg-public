#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int maxn = 55;
const ll INF = 1e18;

int n, m;
ll K;
int a[maxn][maxn];
ll dp[maxn][maxn][maxn]; // dp[x][y][r]: 到(x,y)，第x行左移r次的最小成本

// 获取第 row 行左移 r 次后，第 col 列的值（1-based）
inline int get(int row, int col, int r)
{
    // 左移 r 次：原第 j 列 -> 新第 ((j - r - 1) mod m + m) % m + 1 列
    // 等价于：新第 col 列 = 原第 ((col - r - 1) mod m + m) % m + 1 列
    int orig = ((col - r - 1) % m + m) % m + 1;
    return a[row][orig];
}

// dfs 返回从 (x,y) 出发到 (n,m) 的最小额外成本（不含已走过的格子）
// 当前状态：在 (x,y)，第 x 行已经左移了 r 次
// 总成本 = 已花操作费 + 已走路径和 + 后续成本
// 这里 dp 存的是"从起点走到(x,y)且第x行左移r次"的最小总成本（含操作费和路径和）
ll solve()
{
    // 初始化 dp 为 INF
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            for(int r = 0; r < m; ++r)
                dp[i][j][r] = INF;

    // 枚举第一行左移次数 r，起点 (1,1) 的值取决于左移后的位置
    for(int r = 0; r < m; ++r)
    {
        // 操作 r 次，费用 r * K，加上起点值
        dp[1][1][r] = (ll)r * K + get(1, 1, r);
    }

    for(int x = 1; x <= n; ++x)
    {
        for(int y = 1; y <= m; ++y)
        {
            for(int r = 0; r < m; ++r)
            {
                if(dp[x][y][r] == INF) continue;
                ll cur = dp[x][y][r];

                // 向下走，到 (x+1, y)，第 x+1 行可以选择新的左移次数 r2
                if(x + 1 <= n)
                {
                    for(int r2 = 0; r2 < m; ++r2)
                    {
                        // 第 x+1 行左移 r2 次的费用，加上新格子的值
                        ll nxt = cur + (ll)r2 * K + get(x + 1, y, r2);
                        if(nxt < dp[x + 1][y][r2])
                            dp[x + 1][y][r2] = nxt;
                    }
                }

                // 向右走，到 (x, y+1)，仍在第 x 行，左移次数保持 r
                if(y + 1 <= m)
                {
                    ll nxt = cur + get(x, y + 1, r);
                    if(nxt < dp[x][y + 1][r])
                        dp[x][y + 1][r] = nxt;
                }
            }
        }
    }

    ll ans = INF;
    for(int r = 0; r < m; ++r)
        ans = min(ans, dp[n][m][r]);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m >> K;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                cin >> a[i][j];
        cout << solve() << "\n";
    }
    return 0;
}
