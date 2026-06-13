#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e7 + 10;
int n;
bool notPrime[maxn];
ll tong[maxn], pre[maxn];

void init() 
{
    for(int i=2; i<=1e7; ++i) 
    {
        if(notPrime[i] == false) 
        {
            tong[i] ++;
            for(int j=i+i; j<=1e7; j+=i) 
            {
                notPrime[j] = true;
                tong[j] ++;
            }
        }
    }
    for(int i=1; i<=1e7; ++i) pre[i] = pre[i-1] + tong[i];
}

int main() 
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    init();
    int T; cin >> T;
    while(T--) 
    {
        cin >> n;
        cout << pre[n] << endl;
    }
    return 0;
}