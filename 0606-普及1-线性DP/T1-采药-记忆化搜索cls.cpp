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

// 记录：1️⃣ 状态 2️⃣ 子问题的解    dfs2(状态 1， 状态 2) 的返回值，就是当前子问题的解
int dfs2(int x, int capacity)
{
    // 记忆化的剪枝
    if(dp[x][capacity] != -1) return dp[x][capacity];
    // 搜索的终止条件，最小的子问题
    if(x == 0) {
        return 0;
    }
    int yes = -1, no=-1;
    // 1. 选第 x 株采药，能获得的最大价值 yes
    if(capacity >= cost[x]) yes = dfs2(x-1, capacity-cost[x]) + val[x];
    // 2. 不选第 x 株采药，能获得的最大价值 no
    no = dfs2(x-1, capacity);
    dp[x][capacity] = max(yes, no);
    return dp[x][capacity];
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
    cout << dfs2(3, 8);
    return 0;
}