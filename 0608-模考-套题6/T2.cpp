#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e5 + 10;
int n, sum, ans;
int a[maxn], pre[maxn];

bool check(int x) 
{
    int k = lower_bound(pre, pre + n, x) - pre;
    return k < n && pre[k] == x;
}

int main() 
{
    cin >> n;
    for(int i=1; i<=n; ++i) 
    {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    sum = pre[n];
    if(sum % 3 != 0) {
        cout << 0;
        return 0;
    }
    int part = sum / 3;
    for(int i=0; i<n; ++i) 
    {
        // 枚举第一个点，计算后两个点位置
        int x1 = pre[i];
        int x2 = pre[i] + part;
        int x3 = pre[i] + part * 2;
        if(check(x2) && check(x3)) ans ++;
    }
    cout << ans;
    return 0;
}