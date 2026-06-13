#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxq = 5e4 + 7;
const int INF = 0x3f3f3f3f;
int t, n, P, Q;
int dp[maxq];  // dp[v] 表示花费 v 能达到的最大强度

int solve() {
    // 初始化：dp[0] = 0 表示花费 0 强度为 0
    // 其他位置初始化为 -INF 表示不可达
    memset(dp, -0x3f, sizeof(dp));
    dp[0] = 0;

    // 对每件武器进行 0/1 背包转移
    for (int i = 1; i <= n; ++i) {
        int p, c;
        cin >> p >> c;
        // 倒序遍历，确保每件武器只选一次
        for (int v = Q; v >= c; --v) {
            if (dp[v - c] != -INF) {
                dp[v] = max(dp[v], dp[v - c] + p);
            }
        }
    }

    // 找出满足强度 >= P 的最小花费
    for (int v = 0; v <= Q; ++v) {
        if (dp[v] >= P) {
            return v;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 多组测试数据
    cin >> t;
    while (t--) {
        cin >> n >> P >> Q;
        cout << solve() << "\n";
    }

    return 0;
}