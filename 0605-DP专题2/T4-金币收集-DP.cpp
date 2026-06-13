// P14078 [GESP202509 七级] 金币收集 —— 递推 DP 版（O(n²) LIS 转移）
// 按 x 升序后，对 u = t - x 求最长不下降子序列；x > t 的金币原点都到不了，跳过
// dp[i] = 以排序后第 i 枚金币结尾，最多能收的数量
// 转移：dp[i] = 1 + max{ dp[j] | j < i, u[j] <= u[i] }
// n=1e5 时 O(n²) 可能 TLE，仅作为和记忆化版的对照
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
struct Node { int x, t; } a[maxn];
int dp[maxn];

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
        if(a[i].x > a[i].t) continue; // 原点都到不了，跳过
        dp[i] = 1;
        for(int j = 1; j < i; ++j)
            if(a[j].x <= a[j].t && a[j].t - a[j].x <= a[i].t - a[i].x)
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
