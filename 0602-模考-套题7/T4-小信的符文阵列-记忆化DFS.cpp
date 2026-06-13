#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1010;
const ll INF = 1e18;

int n;
ll a[maxn];
char b[maxn];
ll mi[maxn][maxn], ma[maxn][maxn];
bool vis[maxn][maxn];

// 记忆化搜索 [l, r] 的最小、最大值
// 关键观察：乘法时正负号会翻转，所以只记 min/max 就够覆盖所有最优组合
void dfs(int l, int r)
{
    if(vis[l][r]) return;
    vis[l][r] = true;
    if(l == r) { mi[l][r] = ma[l][r] = a[l]; return; }
    mi[l][r] = INF; ma[l][r] = -INF;
    for(int d = l; d < r; ++d)
    {
        dfs(l, d);
        dfs(d + 1, r);
        ll lmi = mi[l][d], lma = ma[l][d];
        ll rmi = mi[d + 1][r], rma = ma[d + 1][r];
        if(b[d] == '+' || b[d] == '?')
        {
            ma[l][r] = max(ma[l][r], lma + rma);
            mi[l][r] = min(mi[l][r], lmi + rmi);
        }
        if(b[d] == '-' || b[d] == '?')
        {
            ma[l][r] = max(ma[l][r], lma - rmi);
            mi[l][r] = min(mi[l][r], lmi - rma);
        }
        if(b[d] == '*' || b[d] == '?')
        {
            // 乘法：4 种符号组合都要试
            ll c1 = lma * rma, c2 = lma * rmi;
            ll c3 = lmi * rma, c4 = lmi * rmi;
            ma[l][r] = max({ma[l][r], c1, c2, c3, c4});
            mi[l][r] = min({mi[l][r], c1, c2, c3, c4});
        }
    }
}

signed main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i];
        // 破环成链，把第二份接到后面
        a[i + n] = a[i];
        b[i + n] = b[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        dfs(i, i + n - 1);
        cout << abs(mi[i][i + n - 1]) << abs(ma[i][i + n - 1]);
    }
    return 0;
}
