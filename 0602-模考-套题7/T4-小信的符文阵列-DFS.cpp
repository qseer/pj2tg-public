#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 30;
const ll INF = 1e18;

int n;
ll a[maxn];
char b[maxn];
ll mi, ma;

// 暴力枚举 [l, r] 所有运算顺序，返回所有可能的值
// 调用条件：区间内已没有 ?，所有运算符都是 +/-/*
vector<ll> calc(int l, int r)
{
    if(l == r) return {a[l]};
    vector<ll> res;
    // 枚举最后一刀切在哪个运算符 b[d]
    for(int d = l; d < r; ++d)
    {
        vector<ll> L = calc(l, d);
        vector<ll> R = calc(d + 1, r);
        for(ll x : L) for(ll y : R)
        {
            if(b[d] == '+') res.push_back(x + y);
            else if(b[d] == '-') res.push_back(x - y);
            else res.push_back(x * y);
        }
    }
    return res;
}

// 逐位决策：考虑 b[idx] 这个运算符
// 若是 ?，枚举三种取值后递归到下一位；否则直接递归到下一位
// 走到 idx == r 表示所有运算符都已确定，是 base case
void enumQ(int l, int r, int idx)
{
    if(idx >= r)
    {
        // 已经没 ? 了，把所有运算顺序的值并入答案
        for(ll x : calc(l, r))
        {
            mi = min(mi, x);
            ma = max(ma, x);
        }
        return;
    }
    if(b[idx] == '?')
    {
        for(char c : {'+', '-', '*'})
        {
            b[idx] = c;
            enumQ(l, r, idx + 1);
        }
        b[idx] = '?'; // 回溯，恢复现场
    }
    else enumQ(l, r, idx + 1);
}

signed main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i] >> b[i];
        // 破环成链，把第二份接到后面
        a[i + n] = a[i];
        b[i + n] = b[i];
    }
    for(int i = 1; i <= n; ++i)
    {
        mi = INF; ma = -INF;
        enumQ(i, i + n - 1, i);
        cout << abs(mi) << abs(ma);
    }
    return 0;
}
