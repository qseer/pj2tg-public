#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, a[maxn], dp[maxn];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    // dp[i] = 以 a[i] 结尾的最大子段和
    // 要么把 a[i] 续到 dp[i-1] 后面，要么从 a[i] 单独开一段
    int ans = INT_MIN;
    for(int i = 1; i <= n; ++i)
    {
        dp[i] = max(dp[i-1] + a[i], a[i]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
