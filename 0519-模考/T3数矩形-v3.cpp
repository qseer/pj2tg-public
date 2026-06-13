#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e5 + 10;
ll n, m, k, ans;
ll a[maxn], prefix[maxn];

int main() 
{
    cin >> n >> m >> k;
    for(int i=1; i<=n; ++i) 
    {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
    }
    // 情况 1：枚举任意两根柱子，两根柱子组成矩形长度
    for(int i=1; i<n; ++i) 
    {
        auto L = lower_bound(a + i + 1, a + 1 + n, a[i] + k + 1) - a;
        auto R = upper_bound(a + i + 1, a + 1 + n, a[i] + k + m) - a;
        ans += (R - L) * (m + a[i] + k + 1) - (prefix[R-1] - prefix[L-1]);
        // for(int j=i+1; j<=n; ++j) 
        // {
        //     int L = a[j] - a[i];
        //     int W = L - k;
        //     if(W <= 0) continue;
        //     if(W > m) break;
        //     // W 的取值范围 [1, m]
        //     // W >= 1   a[j] - a[i] - k >= 1, a[j] >= a[i] + k + 1
        //     // W <= m   a[j] - a[i] - k <= m, a[j] <= a[i] + k + m
        //     ans += (m - W + 1); // m - a[j] + a[i] + k + 1 = (m + a[i] + k + 1) - a[j] 
        // }
    }

    // 情况 2：枚举任意两根柱子，两根柱子组成矩形宽度
    for(int i=1; i<n; ++i) 
    {
        for(int j=i+1; j<=n; ++j) 
        {
            int W = a[j] - a[i];
            int L = W + k;
            if(L > m) break;
            // L 的取值范围 [1, m]
            ans += (m - L + 1);
        }
    }
    cout << ans;
    return 0;
}