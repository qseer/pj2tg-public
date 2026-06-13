#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e5 + 10;
int n, ans, sum, capacity;
int cost[maxn], val[maxn];
int dp[110][1010];

// 进入 dfs(x)，表示的状态是：
// 正在对第 x 件物品做决策，已经做完了前面 x-1 物品的决策，还剩下 x ~ n 物品的决策
// 并且此时剩余的空间是 capacity，想要求解能够获得的最大价值
// 前面 x-1 件物品已经获得了 sum 的价值，之后的物品
int dfs(int x, int capacity) 
{
    // 记忆化剪枝
    if(dp[x][capacity] != -1) return dp[x][capacity];
    // 终止条件
    if(x == n+1) {
        return 0;
    }

    int yes = -1, no = -1;
    // 1. 选
    if(capacity - cost[x] >= 0) 
    {
        yes = dfs(x + 1, capacity - cost[x]) + val[x];
    }
    // 2. 不选
    no = dfs(x + 1, capacity);

    // 记忆最优解
    return dp[x][capacity] = max(yes, no);
}

int main() 
{
    memset(dp, -1, sizeof(dp));
    int T; cin >> T >> n;
    capacity = T;
    for(int i=1; i<=n; ++i) 
    {
        cin >> cost[i] >> val[i];
    }
    cout << dfs(1, T);
    return 0;
}

/*
70 4
50 7
50 9
15 3
5  1
*/