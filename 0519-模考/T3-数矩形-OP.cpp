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
ll a[maxn], prefix[maxn];

int findL(int target, int le)
{
    // 在 a[] 中找到第一个大于等于 target 的 a[k]，返回 k 这个下标
    int l = le, r = n, res = 0;
    while(l <= r) 
    {
        int mid = (l + r) / 2;
        if(a[mid] >= target) {
            res = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    return res;
}

int findR(int target, int le) {
    // 在 a[] 中找到最后一个小于等于 target 的 a[k]，返回 k 这个下标
    int l = le, r = n, res = 0;
    while(l <= r) 
    {
        int mid = (l + r) / 2;
        if(a[mid] <= target) {
            res = mid;
            l = mid + 1;
        } 
        else {
            r = mid - 1;
        }
    }
    return res;
}

int main() 
{
    ll ans = 0;
    cin >> n >> m >> k;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        prefix[i] = prefix[i-1] + a[i];
    }
    // 先枚举线段 i 和线段 j 之间的距离，确定下来长度 L，然后求得宽度 W = L - k
    for(int i=1; i<n; ++i) 
    {
        int L = findL(1 + a[i] + k, i+1);
        int R = findR(m + a[i] + k, i+1);
        // L 不存在？R 不存在？
        if(L == 0 || R == 0) continue;
        ans += 1ll * (R - L + 1) * (m + a[i] + k + 1) - (prefix[R] - prefix[L-1]);
        // for(int j=i+1; j<=n; ++j) 
        // {
        //     int L = a[j] - a[i];
        //     int W = L - k;
        //     if(W <= 0) continue;
        //     // W >= 1 && W <= m
        //     // a[L] - a[i] - k >= 1, a[L] >= 1 + a[i] + k
        //     // a[R] - a[i] - k <= m, a[R] <= m + a[i] + k
        //     if(W > m) break;
        //     // m - a[j] + a[i] + k + 1 = (m + a[i] + k + 1) - a[j]
        //     ans += (m - W + 1);
        // }
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
            ans += (m - L + 1);
        }
    }
    cout << ans;
    return 0;
}