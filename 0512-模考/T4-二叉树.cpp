#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e5 + 10;
int n, q;
int fa[maxn];
char col[maxn];
int diff[maxn]; // 差分数组，记录子树翻转次数
vector<int> G[maxn];

void dfs(int u)
{
    for(int v : G[u])
    {
        diff[v] += diff[u];
        dfs(v);
    }
}

int main()
{
    cin >> n;
    for(int i = 2; i <= n; ++i)
    {
        cin >> fa[i];
        G[fa[i]].push_back(i);
    }
    for(int i = 1; i <= n; ++i) cin >> col[i];
    cin >> q;
    while(q--)
    {
        int a; cin >> a;
        diff[a]++;
    }
    dfs(1);
    for(int i = 1; i <= n; ++i)
    {
        if(diff[i] % 2 == 1) col[i] = (col[i] == '0' ? '1' : '0');
        cout << col[i];
    }
    return 0;
}
