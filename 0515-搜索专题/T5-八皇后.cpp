#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;

int n;
int col[maxn];   // col[row] = 第 row 行皇后所在的列
int ans;

// 检查在 (row, c) 放皇后是否合法
bool check(int row, int c)
{
    for(int i = 1; i < row; ++i)
    {
        // 同列或对角线冲突
        if(col[i] == c || abs(col[i] - c) == abs(i - row))
            return false;
    }
    return true;
}

// 当前处理第 row 行
void dfs(int row)
{
    if(row > n)
    {
        ++ans;
        // 输出一种方案
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
                cout << (col[i] == j ? 'Q' : '.');
            cout << "\n";
        }
        cout << "\n";
        return;
    }
    for(int c = 1; c <= n; ++c)
    {
        if(!check(row, c)) continue;  // 可行性剪枝
        col[row] = c;
        dfs(row + 1);
        col[row] = 0;  // 回溯
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
