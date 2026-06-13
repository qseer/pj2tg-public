#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e4 + 10;
int n, T;
int d[maxn], a[maxn];

bool check(int K) 
{
    // K 个舞台，是否合法？

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