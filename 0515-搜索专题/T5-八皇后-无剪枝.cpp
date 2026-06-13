#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;

int n;
int col[maxn];
int ans;

// 等所有皇后放完再统一检查（无剪枝，用于对比）
bool checkAll()
{
    for(int i = 1; i <= n; ++i)
        for(int j = i + 1; j <= n; ++j)
            if(col[i] == col[j] || abs(col[i] - col[j]) == abs(i - j))
                return false;
    return true;
}

void dfs(int row)
{
    if(row > n)
    {
        if(checkAll()) ++ans;
        return;
    }
    for(int c = 1; c <= n; ++c)
    {
        col[row] = c;
        dfs(row + 1);  // 不剪枝，直接往下搜
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    dfs(1);
    cout << ans;
    return 0;
}
