#include <bits/stdc++.h>
using namespace std;

const int maxn = 25;

int n, k;
int a[maxn];
int chosen[maxn];  // 选出的 k 个数
int ans;

// 判断 x 是否为质数
bool isPrime(int x)
{
    if(x < 2) return false;
    for(int i = 2; i * i <= x; ++i)
        if(x % i == 0) return false;
    return true;
}

// 从 start 开始选第 cnt 个数，保证组合不重复（顺序无关）
void dfs(int start, int cnt)
{
    if(cnt > k)
    {
        int sum = 0;
        for(int i = 1; i <= k; ++i) sum += chosen[i];
        if(isPrime(sum)) ++ans;
        return;
    }
    // 从 start 开始选，避免重复组合
    for(int i = start; i <= n; ++i)
    {
        chosen[cnt] = a[i];
        dfs(i + 1, cnt + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    dfs(1, 1);
    cout << ans;
    return 0;
}
