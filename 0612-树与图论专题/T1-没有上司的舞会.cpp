#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 6e3 + 10;
int n, indu[maxn];
int val[maxn];
int dp[maxn][2];
vector<int> G[maxn];

void dfs(int x) 
{
    dp[x][1] = val[x];
    for(int i=0; i<G[x].size(); ++i) 
    {
        int v = G[x][i];
        dfs(v);
        dp[x][0] += max(dp[v][0],dp[v][1]);
        dp[x][1] += dp[v][0];
    }
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
    dfs(root);
    cout << max(dp[root][0], dp[root][1]);
    return 0;
}