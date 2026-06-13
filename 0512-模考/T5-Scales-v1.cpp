#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll C;
vector<ll> w;       // 有效砝码（质量 <= C 的）
vector<ll> suffix;  // suffix[i] = w[i] + w[i+1] + ... + w[m-1]
ll ans = 0;

/**
 * DFS 搜索，从第 idx 个砝码开始考虑
 * @param idx  当前考虑的砝码下标（从大到小枚举）
 * @param sum  当前已选砝码的总质量
 * 
 * 剪枝策略：
 * 1. 超重剪枝：sum > C 时直接返回
 * 2. 最优性剪枝：sum + suffix[idx] <= ans 时，即使剩下全选也无法超越当前最优，剪枝
 */
void dfs(int idx, ll sum) {
    // 更新最优解
    ans = max(ans, sum);
    
    if (idx < 0) return;
    
    // 剪枝：即使把 idx 及之后的所有砝码都选上，也无法超过当前最优解
    if (sum + suffix[idx] <= ans) return;
    
    // 选择当前砝码（从大到小，先尝试选，更快逼近 C）
    if (sum + w[idx] <= C) {
        dfs(idx - 1, sum + w[idx]);
    }
    
    // 不选当前砝码
    dfs(idx - 1, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> C;
    
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        // 只保留不超过天平承重 C 的砝码，更大的永远用不上
        if (x <= C) {
            w.push_back(x);
        }
    }
    
    // 按从大到小排序，先考虑大的砝码，更快逼近最优解
    sort(w.rbegin(), w.rend());
    
    int m = w.size();
    
    // 计算后缀和，用于剪枝
    suffix.resize(m);
    for (int i = m - 1; i >= 0; i--) {
        suffix[i] = w[i] + (i + 1 < m ? suffix[i + 1] : 0);
    }
    
    dfs(m - 1, 0);
    
    cout << ans << endl;
    
    return 0;
}
