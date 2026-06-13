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

void getPrimes() {
    for(int i=2; i<=1e6; ++i) {
        if(notPrime[i] == false) primes.push_back(i);
        for(int p: primes) {
            int h = p * i;
            if(h > 1e6) break;
            notPrime[h] = true;
            if(i % p == 0) break;
        }
    }
}

void decompose(int x) {
    for(int p: primes) {
        if(x == 1) break;
        while(x % p == 0) {
            tong[p] ++;
            x /= p;
        }
    }
}

bool check() {
    for(int p: primes) {
        if(tong[p] % n != 0) return false;
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
    getPrimes();
    int T; cin >> T;
    while(T--) {
        Sol();
    }
    return 0;
}