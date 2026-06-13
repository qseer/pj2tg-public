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
const int maxl = 1e6 + 10;
ll dp[maxl], c[505], l[505];
ll N, L;

int main() 
{
    cin >> N >> L;
    for(int i=1; i<=N; ++i) 
    {
        cin >> c[i] >> l[i];
    }
    // 1. dp 数组初始化，dp[j]
    dp[0] = 0;
    for(int i=1; i<=1e6; ++i) dp[i] = INT_MAX;
    // 2. 更新 dp 数组，dp[j] 表示组成 j 的容量，所需的最小花费
    for(int i=1; i<=N; ++i) 
    {
        for(int j=1e6; j>=l[i]; --j) {
            dp[j] = min(dp[j], dp[j-l[i]] + c[i]);
        }
    }
    ll ans = INT_MAX;
    for(int j=L; j<=1e6; ++j) {
        ans = min(ans, dp[j]);
    }
    if(ans == INT_MAX) cout << "no solution";
    else cout << ans;
    return 0;
}