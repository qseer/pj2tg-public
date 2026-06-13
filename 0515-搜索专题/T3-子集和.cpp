#include <bits/stdc++.h>
using namespace std;

const int maxn = 25;

int n, target;
int a[maxn];
bool found;

// 当前考虑第 pos 个元素，已选元素和为 sum
void dfs(int pos, int sum)
{
    if(found) return;  // 已找到，剪枝
    if(sum == target)
    {
        found = true;
        return;
    }
    if(pos > n) return;  // 越界
    if(sum > target) return;  // 和已超过目标，剪枝（正数前提下）

    // 选 a[pos]
    dfs(pos + 1, sum + a[pos]);
    // 不选 a[pos]
    dfs(pos + 1, sum);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> target;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    dfs(1, 0);
    cout << (found ? "YES" : "NO");
    return 0;
}
