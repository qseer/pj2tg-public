#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 1010;
int n, m;
ll C, w[maxn], suffix[maxn], ans;

void dfs(int idx, ll sum)
{
    ans = max(ans, sum);
    if(idx > m) return;
    if(sum + suffix[idx] <= ans) return;
    if(sum + w[idx] <= C) dfs(idx + 1, sum + w[idx]);
    dfs(idx + 1, sum);
}

int main()
{
    cin >> n >> C;
    for(int i = 1; i <= n; ++i)
    {
        ll x;
        cin >> x;
        if(x <= C) w[++m] = x;
    }

    sort(w + 1, w + m + 1, greater<ll>());
    for(int i = m; i >= 1; --i)
        suffix[i] = w[i] + suffix[i + 1];

    dfs(1, 0);

    cout << ans;
    return 0;
}
