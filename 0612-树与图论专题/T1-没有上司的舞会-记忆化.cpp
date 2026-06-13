#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 6e3 + 10;
int n, indu[maxn];
int val[maxn];
int dp[maxn][2];  // -1 表示未计算
vector<int> G[maxn];

int dfs(int x, int choose)
{
    if(dp[x][choose] != -1) return dp[x][choose];
    
    int res = choose ? val[x] : 0;
    for(int i=0; i<G[x].size(); ++i)
    {
        int v = G[x][i];
        if(choose) res += dfs(v, 0);
        else       res += max(dfs(v, 0), dfs(v, 1));
    }
    return dp[x][choose] = res;
}

int main()
{
    cin >> n;
    for(int i=1; i<=n; ++i) cin >> val[i];
    for(int i=1; i<n; ++i)
    {
        int son, fa;
        cin >> son >> fa;
        G[fa].push_back(son);
        indu[son] ++;
    }
    int root = 0;
    for(int i=1; i<=n; ++i)
    {
        if(indu[i] == 0) {
            root = i;
            break;
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << max(dfs(root, 0), dfs(root, 1));
    return 0;
}
