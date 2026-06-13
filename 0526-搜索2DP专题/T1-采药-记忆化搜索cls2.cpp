#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e5 + 10;
int n, ans, sum, capacity;
int cost[maxn], val[maxn];
int dp[110][1010];

// 正在对第 x 件物品做决策
void dfs(int x) 
{
    if(x == n+1) {
        // 统计当前方案下的答案
        ans = max(ans, sum);
        return ;
    }

    // 1. 选
    if(capacity - cost[x] >= 0) 
    {
        capacity -= cost[x];    // 总容量减少
        sum += val[x];          // 总价值增多
        dfs(x + 1);
        capacity += cost[x];    // 总容量恢复
        sum -= val[x];          // 总价值恢复
    }

    // 2. 不选
    dfs(x + 1);
}

// 区别：不再枚举一个个的具体方案，而是分解一个个子问题。
// 描述清楚一个子问题，通过「状态」，dfs2 函数的传参，就是状态，用来描述当前处在什么子问题，dfs2(...) 函数的返回值，就是当前子问题的解

// 记录：1️⃣ 状态 2️⃣ 子问题的解    dfs2(x: 还剩下 x 株草药, capacity: 当前剩余的容量) 的返回值，就是当前子问题的解
int dfs2(int x, int capacity)
{
    if(x == 0) {
        // 没有草药需要决策，此时能获得的价值是？dfs2(0, XX)
        return 0;
    }

    int yes = -1, no = -1;
    // 1. 选第 x 株草药，状态发生什么变化：1️⃣剩余的物品数量 -1   2️⃣ 容量减少
    // 选的决策下，可以获得的最大总价值：val[x] + dfs2(x-1, capacity-cost[x]);
    if(capacity >= cost[x]) yes = val[x] + dfs2(x-1, capacity-cost[x]);
    // 2. 不选第 x 株草药，状态发生什么变化：1️⃣剩余待决策的物品数量 -1   2️⃣ 容量不变
    no = dfs2(x-1, capacity);
    return max(yes, no);
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
    // dfs(1);
    // 
    cout << dfs2(3, 8);
    return 0;
}