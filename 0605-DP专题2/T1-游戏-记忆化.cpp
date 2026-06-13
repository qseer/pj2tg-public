// P10376 [GESP202403 六级] 游戏 —— 记忆化搜索版
// 直接照着递推式 f(x) = f(x+a) + f(x+b) 写成递归
// 自顶向下，比递推少操心"先算大的还是先算小的"顺序问题
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
int n, a, b, c;
int memo[maxn];
bool vis[maxn];

int f(int x)
{
    if(x <= c) return 1;            // 边界：游戏结束
    if(vis[x]) return memo[x];      // 已算过直接返回
    vis[x] = true;
    int va = (x + a > n) ? 1 : f(x + a);
    int vb = (x + b > n) ? 1 : f(x + b);
    return memo[x] = (va + vb) % mod;
}

int main()
{
    cin >> n >> a >> b >> c;
    cout << f(n);
    return 0;
}
