int total=T;
int sum=0;

void dfs(int x) 
{
    if(x > n) 
    {
        ans = max(ans, sum);
        return ;
    }
    
    // 1. 选
    if(total >= cost[x]) 
    {
        total -= cost[x];
        sum += val[x];
        dfs(x + 1);
        total += cost[x];
        sum -= val[x];
    }

    // 2. 不选
    dfs(x + 1);
}

dfs(1) 在对第 1 件物品做决策
    选了第 1 件物品，total -= cost[1]; sum += val[1];
    不选，total 不变，sum 不变

dfs(2) 在对第 2 件物品做决策