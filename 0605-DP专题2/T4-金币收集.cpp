#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n;
struct Node { int x, t; } a[maxn];
int tails[maxn], len;

int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i].x >> a[i].t;
    sort(a + 1, a + n + 1, [](Node a, Node b)
    {
        if(a.x != b.x) return a.x < b.x;
        return a.t < b.t;
    });
    for(int i = 1; i <= n; ++i)
    {
        if(a[i].x > a[i].t) continue; // 原点都到不了，整条链都用不上
        int u = a[i].t - a[i].x;
        int pos = upper_bound(tails + 1, tails + len + 1, u) - tails;
        tails[pos] = u;
        if(pos > len) ++len;
    }
    cout << len;
    return 0;
}