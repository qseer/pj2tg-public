#include <bits/stdc++.h>
using namespace std;

int n, s[405], f[405];
int dp[800005];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> f[i];
    }

    // fix: 原 memset(dp,-1,...) 以 -1 为哨兵，但 f[i] 为负时合法 dp 值也可能等于 -1，
    //      导致可达状态被误判为不可达，改用 INT_MIN 作哨兵。
    fill(dp, dp + 800005, INT_MIN);
    dp[400000] = 0;

    for (int i = 1; i <= n; i++) {
        if (s[i] >= 0) {
            for (int j = 800000; j >= s[i]; j--) {
                if (dp[j - s[i]] != INT_MIN) {  // fix: 原为 != -1
                    dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
                }
            }
        } else {
            for (int j = 0; j <= 800000 + s[i]; j++) {
                if (dp[j - s[i]] != INT_MIN) {  // fix: 原为 != -1
                    dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
                }
            }
        }
    }

    int ans = 0;  // fix: 原为 INT_MIN，不选任何物品答案为 0
    for (int j = 400000; j <= 800000; j++) {
        if (dp[j] >= 0 && dp[j] + (j - 400000) > ans) {
            ans = dp[j] + (j - 400000);
        }
    }
    cout << ans;
    return 0;
}
