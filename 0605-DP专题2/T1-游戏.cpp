// P10376 [GESP202403 六级] 游戏 —— 递推 DP 版
// dp[x] = 当前值为 x 时的方案数
// 边界：x <= c 时游戏结束，方案数 = 1
// 转移：dp[x] = (x+a 越界 ? 1 : dp[x+a]) + (x+b 越界 ? 1 : dp[x+b])
// 由于 dp[x] 依赖 dp[x+a]、dp[x+b]（更大），需要从大到小递推
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
int n, a, b, c;
int dp[maxn];

int main()
{
    cin >> n >> a >> b >> c;
    for(int x = n; x >= 0; --x)
    {
        if(x <= c) { dp[x] = 1; continue; }
        int va = (x + a > n) ? 1 : dp[x + a];
        int vb = (x + b > n) ? 1 : dp[x + b];
        dp[x] = (va + vb) % mod;
    }
    cout << dp[n];
    return 0;
}
