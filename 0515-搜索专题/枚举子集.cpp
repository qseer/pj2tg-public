

// 正在对第 x 件物品做决策
void dfs(int x) 
{
    if(x == n+1) {
        // 统计当前方案下的答案
        ans = max(ans, sum);
        return ;
    }

    // 1. 选
    if(total - cost[x] >= 0) 
    {
        total -= cost[x];    // 总容量减少
        sum += val[x];       // 总价值增多
        dfs(x + 1);
        total += cost[x];    // 总容量恢复
        sum -= val[x];       // 总价值恢复
    }

    // 2. 不选
    dfs(x + 1);
}