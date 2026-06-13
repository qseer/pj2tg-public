#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;

int main()
{
    ll n; cin >> n;
    vector<pair<ll, int>> fac; // (质因子, 次数)
    for(ll i = 2; i * i <= n; ++i)
    {
        if(n % i == 0)
        {
            int cnt = 0;
            while(n % i == 0)
            {
                n /= i;
                ++cnt;
            }
            fac.push_back({i, cnt});
        }
    }
    if(n > 1) fac.push_back({n, 1});
    // 按格式输出
    for(int i = 0; i < fac.size(); ++i)
    {
        if(i > 0) cout << " * ";
        cout << fac[i].first;
        if(fac[i].second > 1) cout << "^" << fac[i].second;
    }
    return 0;
}
