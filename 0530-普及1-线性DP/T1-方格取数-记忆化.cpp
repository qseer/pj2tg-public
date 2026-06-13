#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int n, grid[maxn][maxn], memo[maxn][maxn];

// dfs(i,j) = 从 (1,1) 出发只向右/下走到达 (i,j) 能取得的最大和
int dfs(int i, int j)
{
    if(i < 1 || j < 1) return 0;
    if(i == 1 && j == 1) return grid[1][1];
    // memo 用 -1 表示未计算；本题权值非负，安全
    if(memo[i][j] != -1) return memo[i][j];
    return memo[i][j] = max(dfs(i-1, j), dfs(i, j-1)) + grid[i][j];
}

int main()
{
    cin >> n;
    int r, c, v;
    while(cin >> r >> c >> v && (r || c || v))
        grid[r][c] = v;
    memset(memo, -1, sizeof(memo));
    cout << dfs(n, n);
    return 0;
}
