#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e5 + 10;
int n, ans, sum, capacity;
int cost[maxn], val[maxn];

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

int main() 
{
    int T; cin >> T >> n;
    capacity = T;
    for(int i=1; i<=n; ++i) 
    {
        cin >> cost[i] >> val[i];
    }
    dfs(1);
    cout << ans;
    return 0;
}