#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e4 + 10;
int n, T;
int d[maxn], a[maxn];

bool check(int k) 
{
    // 默认大根堆，重载为小根堆
    priority_queue<int, vector<int>, greater<int>> q;
    for(int i=1; i<=k; ++i) q.push(a[i]);
    for(int i=k+1; i<=n; ++i) 
    {
        int minEndTime = q.top(); q.pop();
        // 可能有奶牛同时结束演出，此时只需要加一次
        q.push(minEndTime+a[i]);
    }
    int maxEndTime = 0;
    while(!q.empty()) 
    {
        int t = q.top(); q.pop();
        maxEndTime = max(maxEndTime, t);
    }
    return maxEndTime <= T;
}

int main() 
{
    cin >> n >> T;
    for(int i=1; i<=n; ++i) cin >> a[i];
    int l = 1, r = n, ans = -1;
    while(l <= r) 
    {
        int mid = (l + r) / 2;
        if(check(mid)) 
        {
            // 合法，看能不能更小
            ans = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    cout << ans;
    return 0;
}