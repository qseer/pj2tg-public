#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e5 + 10;
struct Node {
    int x, t;
}a[maxn];
int dp[1010][1010];

bool cmp(Node x, Node y) 
{
    if(x.x != y.x) return x.x < y.x;
    return x.t < y.t;
}

int dfs(int x, int k) 
{
    if(x == 0) 
    {
        return 0;
    }
    if(dp[x][k] != -1) return dp[x][k];
    int yes=-1, no=-1;
    // 1. 选第 x 枚金币
    if((a[x].t >= a[x].x) && (k == 0 || (k != 0 && a[k].t - a[x].t >= a[k].x - a[x].x))) {
        yes = dfs(x-1, x) + 1;
    }
    // 2. 不选 x 枚金币
    no = dfs(x-1, k);
    dp[x][k] = max(yes, no);
    return dp[x][k];
}

int main() 
{
    memset(dp, -1, sizeof(dp));
    int n; cin >> n;
    for(int i=1; i<=n; ++i) cin >> a[i].x >> a[i].t;
    sort(a + 1, a + 1 + n, cmp);
    cout << dfs(n, 0);
    return 0;
}