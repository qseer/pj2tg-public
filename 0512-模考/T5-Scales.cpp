#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int maxn = 1010;

int n;
ll C;
ll w[maxn];      // 有效砝码（质量 <= C 的），从大到小排列
ll suffix[maxn]; // suffix[i] = w[i] + w[i+1] + ... + w[m]
ll ans = 0;
int m;           // 有效砝码个数

// DFS 搜索，从第 idx 个砝码开始考虑（从大到小枚举）
// sum: 当前已选砝码的总质量
// 剪枝：超重剪枝 + 最优性剪枝（suffix 和无法超越当前最优）
void dfs(int idx, ll sum)
{
    ans = max(ans, sum);
    if(idx > m) return;
    // 即使把 idx 及之后的所有砝码都选上，也无法超过当前最优解
    if(sum + suffix[idx] <= ans) return;
    // 选择当前砝码（先尝试选，更快逼近 C）
    if(sum + w[idx] <= C) dfs(idx + 1, sum + w[idx]);
    // 不选当前砝码
    dfs(idx + 1, sum);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> C;
    m = 0;
    for(int i = 1; i <= n; ++i)
    {
        ll x;
        cin >> x;
        if(x <= C) w[++m] = x; // 只保留不超过天平承重的砝码
    }

    // 按从大到小排序，先考虑大的砝码，更快逼近最优解
    sort(w + 1, w + m + 1, greater<ll>());

    // 计算后缀和，用于剪枝
    for(int i = m; i >= 1; --i)
        suffix[i] = w[i] + suffix[i + 1];

    dfs(1, 0);

    cout << ans;
    return 0;
}
