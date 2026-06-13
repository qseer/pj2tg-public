// P14078 [GESP202509 七级] 金币收集 —— 记忆化搜索版（O(n²)，dfs(i) = 以 i 结尾的最多数量）
// 相邻 i, j（x_i <= x_j）需要 t_j - t_i >= x_j - x_i，即 (t-x) 不下降
// 按 x 升序后，对 u = t - x 求最长不下降子序列（前提 u >= 0，即 x <= t 才能从原点到达）
// f(i) = 以第 i 枚（排序后）金币为结尾能收的最大数量
// f(i) = 1 + max{ f(j) | j < i, a[j].t - a[j].x <= a[i].t - a[i].x }
// 注意：O(n²) 在 n=1e5 可能 TLE，仅用于和 DP 版做对比
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
struct Node { int x, t; } a[maxn];
int memo[maxn];

int f(int i)
{
    if(memo[i]) return memo[i];
    int res = 1;
    for(int j = 1; j < i; ++j)
        if(a[j].x <= a[j].t && a[i].x - a[j].x <= a[i].t - a[j].t)
            res = max(res, f(j) + 1);
    return memo[i] = res;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].t;
    sort(a + 1, a + n + 1, [](Node a, Node b)
    {
        if(a.x != b.x) return a.x < b.x;
        return a.t < b.t;
    });
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(a[i].x > a[i].t) continue;
        ans = max(ans, f(i));
    }
    cout << ans;
    return 0;
}
