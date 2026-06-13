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
const ll MOD = 998244353;
int n, m, k;
ll dp[1010][5050];
ll sum[5050];

int main() 
{
    cin >> n >> m >> k;
    for(int j=1; j<=m; ++j) {
        dp[1][j] = 1;
        sum[j] = (sum[j-1] + dp[1][j]) % MOD;
    }
    // dp[i][j] 表示：前 i 个人分蛋糕，给第 i 个人分 j 块蛋糕，的方案数
    for(int i=2; i<=n; ++i) {
        for(int j=1; j<=m; ++j) {
            if(j-k >= 1) dp[i][j] = (dp[i][j] + sum[j-k]) % MOD;
            if(j+k <= m) dp[i][j] = (dp[i][j] + sum[m] - sum[j+k-1] + MOD) % MOD;
        }
        for(int j=1; j<=m; ++j) {
            sum[j] = (sum[j-1] + dp[i][j]) % MOD;
        }
    }
    ll ans = 0;
    for(int j=1; j<=m; ++j) {
        ans = (ans + dp[n][j]) % MOD;
    }
    cout << ans;
    return 0;
}