
bool check() 
{
    // c[p[1]], c[p[2]], ..., c[p[n]] 这个字符串是不是一个非回文串
    for(int i=1; i<=n; ++i) 
    {
        i == 1, c[p[1]] == c[p[n]]
        i == 2, c[p[2]] == c[p[n-1]]
        ...
    }
}

void dfs(int x)
{
    if(x == n+1) {
        // 有了一个方案，p[1], p[2], p[3], ..., p[n]
        if(check()) ans ++;
        return ;
    }
    for(int i=1; i<=n; ++i) // 枚举当前第 x 个位置上，放 i 号牛
    {
        if(vis[i] == false) 
        {
            p[x] = i;
            vis[i] = true;
            dfs(x + 1);
            vis[i] = false;
        }
    }
}