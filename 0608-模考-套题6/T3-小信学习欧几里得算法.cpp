#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e7 + 10;
bool vis[maxn];
ll tong[maxn];
int primes[maxn], cnt;

void init() {
    for(int i=2; i<=1e7; ++i) {
        if(vis[i] == 0) {
            primes[++cnt] = i;
            for(int j=i; j<=1e7; j += i) {
                tong[j] ++;
                vis[j] = true;
            }
        }
    }
    for(int i=1; i<=1e7; ++i) tong[i] += tong[i-1];
}

int main() 
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    init();
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        cout << tong[n] << endl;
    }
    return 0;
}