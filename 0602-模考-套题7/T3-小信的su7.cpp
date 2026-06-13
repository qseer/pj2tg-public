#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e5 + 10;
int n, m;
ll a[maxn], b[maxn];
ll X[maxn], T[maxn];

int findi(int J) 
{
    // 1. 贪心地找下一个要用的电池，最近的、有点的电池
    for(int j=J; j<=m; ++j) {
        if(a[T[j]] > 0) return T[j];
    }
    // 2. 后面电站的电池都没电，就随便找一块有点的电池使用
    for(int i=1; i<=n; ++i) {
        if(a[i] > 0) return i;
    }
    // 都没电了，就结束
    return 0;
}

int main() 
{
    cin >> n >> m;
    // 规定：i 表示电池的下标
    for(int i=1; i<=n; ++i) {
        cin >> a[i]; // 当前电池剩余的电量
        b[i] = a[i]; // b[] 记录满电状态是几格电
    }
    // 规定：j 表示电站的下标
    for(int j=1; j<=m; ++j) {
        cin >> X[j] >> T[j];
    }
    // 去走每一个电站
    ll pos = 0, j = 1, cnt = n;
    while(true) 
    {
        // 当前位置，消耗哪块电池
        int i = findi(j);
        if(i == 0) break;
        // 消耗第 i 块电池，可不可以走到下一个电站 j
        // 1. 使用 i 号电池，走不到 j 号电站
        if(pos + a[i] < X[j] || j > m) {
            pos += a[i];
            a[i] = 0;
        } 
        // 2. 使用 i 号电池，走到 j 号电站 
        else {
            ll dis = X[j] - pos;
            pos += dis;
            a[i] -= dis;
            a[T[j]] = b[T[j]];
            ++ j;
        }
    }
    cout << pos;
    return 0;
}