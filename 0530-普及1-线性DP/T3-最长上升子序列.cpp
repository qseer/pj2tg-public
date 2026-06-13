#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int n, a[maxn], dp[maxn];

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    // dp[i] = 以 a[i] 结尾的 LIS 长度，至少为 1（只取 a[i] 自己）
    int ans = 0;
    for(int i = 1; i <= n; ++i)
    {
        dp[i] = 1;
        for(int j = 1; j < i; ++j)
            if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
