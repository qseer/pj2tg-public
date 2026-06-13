#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e5 + 10;
ll n, m, k, ans;
ll a[maxn];

int main() 
{
    cin >> n >> m >> k;
    for(int i=1; i<=n; ++i) 
    {
        cin >> a[i];
    }
    // 约定：长度 > 宽度
    O(n^2) -> O(n) , O(nlogn)
    // 情况 1：枚举任意两根柱子，两根柱子组成矩形长度
    for(int i=1; i<n; ++i) 
    {
        for(int j=i+1; j<=n; ++j) 
        {
            int L = a[j] - a[i];
            int W = L - k;
            if(W <= 0) continue;
            if(W > m) break;
            W >= 1, a[j] - a[i] - k >= 1, a[j] >= 1 + a[i] + k, 满足该条件的左边界的 j 就是 L
            W <= m, a[j] - a[i] - k <= m, a[j] <= m + a[i] + k, R = upper_bound(a + 1 + i + 1, a + 1 + n, m + a[i] + k) - a;
            二分查找，查找到合法的左边界 L，合法的有边界 R，j 的取值 [L, R]，对 ans 才有有效的贡献
            // m - W + 1 = m - L + k = m + a[i] + k - a[j]
            // j == L, ans += m - a[L] + a[i] + k 
            // j == L+1, ans += m - a[L+1] + a[i] + k 
            // ...
            // j == R, ans += m - a[R] + a[i] + k  
            // 总共循环了 (R - L + 1) * (m + a[i] + k)
            // 前缀和处理 a[j]  a[L], a[L+1], ..., a[R]
            // 总贡献 (R - L + 1) * (m + a[i] + k) + (prefix[R] - prefix[L-1])
            ans += (m - W + 1);
        }
    }
    // 情况 2：枚举任意两根柱子，两根柱子组成矩形宽度
    for(int i=1; i<n; ++i) 
    {
        for(int j=i+1; j<=n; ++j) 
        {
            int W = a[j] - a[i];
            int L = W + k;
            if(L > m) break;
            ans += (m - L + 1);
        }
    }
    cout << ans;
    return 0;
}