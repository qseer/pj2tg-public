#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 10;
int n, m, k;
int a[maxn];

int main() 
{
    ll ans = 0;
    cin >> n >> m >> k;
    for(int i=1; i<=n; ++i) cin >> a[i];
    // 先枚举线段 i 和线段 j 之间的距离，确定下来长度 L，然后求得宽度 W = L - k
    for(int i=1; i<n; ++i) 
    {
        for(int j=i+1; j<=n; ++j) 
        {
            int L = a[j] - a[i];
            int W = L - k;
            if(W <= 0) continue;
            if(W > m) break;
            ans += (m - W + 1);
        }
    }
    // 再枚举线段 i 和线段 j 之间的距离，作为宽度 W，然后求得长度 L = W + k
    for(int i=1; i<n; ++i) 
    {
        for(int j=i+1; j<=n; ++j) {
            int W = a[j] - a[i];
            int L = W + k;
            // 如何判断合法？
            if(L > m) break;
            // 如何统计该长宽下的方案数？
            ans += (m - L + 1); // m - (W + k) + 1 = m + a[i] - k + 1 - a[j] 
        }
    }
    cout << ans;
    return 0;
}