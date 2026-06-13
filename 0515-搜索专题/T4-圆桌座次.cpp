#include <bits/stdc++.h>
using namespace std;

const int maxn = 10;

int n;
int a[maxn];
bool used[maxn];
int ans;

// 圆排列：固定第 1 个人，排列剩下 n-1 个人
void dfs(int pos)
{
    if(pos > n)
    {
        ++ans;
        // 输出一种方案
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
        used[i] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    if(n == 0)
    {
        cout << 0;
        return 0;
    }
    // 固定 1 号坐在第 1 个位置，消除旋转对称
    used[1] = true;
    a[1] = 1;
    dfs(2);
    cout << ans;
    return 0;
}
