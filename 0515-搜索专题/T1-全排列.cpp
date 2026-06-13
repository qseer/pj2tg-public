#include <bits/stdc++.h>
using namespace std;

const int maxn = 10;

int n;
int a[maxn];      // 当前排列
bool used[maxn];  // 数字 i 是否已使用

// 当前正在填第 pos 个位置
void dfs(int pos)
{
    if(pos > n)
    {
        for(int i = 1; i <= n; ++i) cout << a[i] << " ";
        cout << "\n";
        return;
    }
    for(int i = 1; i <= n; ++i)
    {
        if(used[i]) continue;
        used[i] = true;
        a[pos] = i;
        dfs(pos + 1);
        used[i] = false;  // 回溯，恢复状态
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    dfs(1);
    return 0;
}
