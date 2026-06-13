#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 15;
int n;
int a[maxn], b[maxn];
int p[maxn]; // 排列

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) cin >> b[i];
    for(int i = 1; i <= n; ++i) p[i] = i;
    int ans = INT_MAX;
    do
    {
        // 计算当前排列下最少需要多少牛棚
        // 第 i 头牛放在第 p[i] 个位置（按顺序）
        // 需要满足：相邻两头牛之间的距离 > 各自的攻击范围
        // 实际上按某种顺序安排牛，求最小连续长度
        // 设第 i 头牛放在位置 pos[i]
        // pos[i] - pos[i-1] > max(b[p[i-1]], a[p[i]])
        // 即间隔至少为 max(b[prev], a[cur]) + 1
        int len = 1; // 第一头牛占一个位置
        for(int i = 2; i <= n; ++i)
        {
            int gap = max(b[p[i - 1]], a[p[i]]) + 1;
            len += gap;
        }
        ans = min(ans, len);
    } while(next_permutation(p + 1, p + n + 1));
    cout << ans;
    return 0;
}
