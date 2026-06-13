#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 2e5 + 10;
int n, fa[maxn]; 
ll ans = 0, a[maxn], l[maxn], r[maxn]; 
vector<int> G[maxn];

void dfs(int u)
{
    if(G[u].size() == 0) 
    {
        // 先把子节点喂饱
        ans ++;
        a[u] = r[u];
        return ;
    }

    long long sum = 0;
    for(int i=0; i<G[u].size(); ++i) 
    {
        int v = G[u][i];
        // 需要根据子节点反馈上来的信息，来决定给 u 加多少
        // 所以先进入子节点，统计子节点的信息
        dfs(v);
        sum += a[v];
        // 从子节点收集它反馈上来的数值，根据它反馈的数值之和，来决定要不要继续给 u 节点投喂
    }

    // 1. sum 够吃,l[u] <= sum <= r[u]
    if(sum >= l[u]) 
    {
        // 确保可以不饿，但会不会撑爆？需要再判断一下
        if(sum <= r[u]) 
        {
            a[u] = sum;
        } else if(sum > r[u]) 
        {
            a[u] = r[u];
        }
    }
    // 2. sum 不够吃 
    else {
        ans ++;
        a[u] = r[u];
    }
}

int main() 
{
    cin >> n;
    for(int i=2; i<=n; ++i) 
    {
        cin >> fa[i];
        G[fa[i]].push_back(i);
    }
    for(int i=1; i<=n; ++i) 
    {
        cin >> l[i] >> r[i];
    }
    dfs(1);
    cout << ans;
    return 0;
}