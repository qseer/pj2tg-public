#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e7 + 10;
bool notPrime[maxn];
ll tong[maxn];
int primes[maxn], cnt;

void init() {
    for(int i=2; i<=1e7; ++i) {
        if(notPrime[i] == 0) {
            primes[++cnt] = i;
            for(int j=i+i; j<=1e7; j+=i) {
                notPrime[j] = true; // j == b
                // 统计 b 的个数，b 出现的次数，就是皮卡丘比值的 (a, b) 的个数
            }
        }
    }
}

int main() 
{
    // freopen("B.in", "r", stdin);
    // freopen("B.out", "w", stdout);
    init();
    int T; cin >> T;
    while(T--) {
        int ans = 0;
        int n; cin >> n;
        for(int i=1; i<=n; ++i) 
        {
            for(int j=1; j<=cnt && primes[j]<=n; ++j) 
            {
                int b = i*primes[j];
                if(b<=n) 
                {
                    ans ++;
                }
                else 
                {
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}