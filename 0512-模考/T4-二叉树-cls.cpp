#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e5 + 10;
int n;
int color[maxn];
// int cnt1, cnt2, cnt3 ...
int cnt[maxn]; // 
vector<int> G[maxn];

// u 起点, v 到达节点
void dfs(int u) 
{
    for(int i=0; i<G[u].size(); ++i) 
    {
        int v = G[u][i];
        cnt[v] += cnt[u];
        dfs(v);
    }
}

int main() 
{
    cin >> n;
    for(int i=2; i<=n; ++i) {
        int fa; cin >> fa; // fa -> i
        G[fa].push_back(i);
    }
    string s; cin >> s;
    for(int i=0; i<n; ++i) {
        color[i+1] = s[i] - '0';
    }
    int q; cin >> q;
    while(q--) 
    {
        int x; cin >> x;
        cnt[x] ++; 
        // x == 1   cnt[1] ++
        // x == 2   cnt[2] ++
        // dfs(x);
    }
    dfs(1);
    for(int i=1; i<=n; ++i) 
    {
        if(cnt[i] % 2 == 0) cout << color[i];
        else cout << !color[i];
    }
    return 0;
}