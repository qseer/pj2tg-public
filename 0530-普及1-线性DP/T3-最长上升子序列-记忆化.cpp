#include <bits/stdc++.h>
using namespace std;
const int maxn = 5005;
int n, a[maxn], memo[maxn];

// dfs(i) = 以 a[i] 结尾的 LIS 长度
// 至少为 1，所以可以用 memo[i] == 0 表示未算过
int dfs(int i)
{
    if(memo[i]) return memo[i];
    int res = 1;
    for(int j = 1; j < i; ++j)
        if(a[j] < a[i]) res = max(res, dfs(j) + 1);
    return memo[i] = res;
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    int ans = 0;
    for(int i = 1; i <= n; ++i) ans = max(ans, dfs(i));
    cout << ans;
    return 0;
}
