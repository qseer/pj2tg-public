#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
const int maxn = 1e4 + 10;
const int maxm = 1e6 + 10;
int n, a[maxn];
vector<int> primes;
bool notPrime[maxm];
int tong[maxm];

// O( n * sqrt(ai) * T )
void decompose(int x) {
    for(int i=2; i*i<=x; ++i) // i=2, 3, 4, 5, 6, ...
    {
        while(x % i == 0) 
        {
            tong[i] ++;
            x /= i;
        }
    }
    if(x > 1) 
    {
        tong[x] ++;
    }
}

bool check() {
    for(int i=2; i<=1e6; ++i) 
    {
        if(tong[i] && tong[i] % n != 0) return false;
    }
    return true;
}

void Sol() {
    memset(tong, 0, sizeof(tong));
    cin >> n;
    for(int i=1; i<=n; ++i) {
        cin >> a[i];
        decompose(a[i]);
    }
    // 检查所有质数的个数是否能够均分 n 份
    cout << (check()? "YES": "NO");
    cout << endl;
}
int main() 
{
    int T; cin >> T;
    while(T--) {
        Sol();
    }
    return 0;
}