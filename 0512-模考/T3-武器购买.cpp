#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 110;
int t;
int n, P, Q;
int p[maxn], c[maxn];
int dp[maxn][maxn]; // dp[i][j] = 前 i 个武器，总强度为 j 的最小花费

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> P >> Q;
        for(int i = 1; i <= n; ++i) cin >> p[i] >> c[i];
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = P + maxn; j >= 0; --j)
            {
                dp[i][j] = dp[i - 1][j];
                if(j >= p[i]) dp[i][j] = min(dp[i][j], dp[i - 1][j - p[i]] + c[i]);
            }
        int ans = 0x3f3f3f3f;
        for(int j = P; j <= P + maxn; ++j)
            ans = min(ans, dp[n][j]);
        if(ans <= Q) cout << ans << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}
