#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 20;
int n, ans = INT_MAX, a[maxn], b[maxn];
int pos[maxn], vis[maxn];

void check()
{
    int sum = 0;
    for(int i=1; i<=n-1; ++i) {
        int l = pos[i], r = pos[i+1];
        int dis = max(b[l], a[r]);
        sum += dis;
    }
    sum += n;
    ans = min(ans, sum);
}

void dfs(int x)
{
    if(x > n) {
        check();
        return ;
    }
    for(int i=1; i<=n; ++i) {
        if(vis[i] == 0) {
            pos[x] = i;
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