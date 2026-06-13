#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 20;
int n, ans = INT_MAX, a[maxn], b[maxn];
int p[maxn], vis[maxn];

void check()
{
    // p[1], p[2], ..., p[n]
    // c[p[1]], c[p[2]], ..., c[p[n]] 这个字符串，是不是非回文串
}

void dfs(int x)
{
    if(x > n) {
        check();
        return ;
    }
    for(int i=1; i<=n; ++i) {
        if(vis[i] == 0) {
            p[x] = i;
            vis[i] = 1;
            dfs(x + 1);
            vis[i] = 0;
        }
    }
}

int main() 
{
    cin >> n;
    for(int i=1; i<=n; ++i) { cin >> a[i]; }
    for(int i=1; i<=n; ++i) { cin >> b[i]; }
    dfs(1);
    cout << ans;
    return 0;
}